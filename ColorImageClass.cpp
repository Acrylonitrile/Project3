#include"ColorImageClass.h"
#include"constants.h"
#include"ColorClass.h"
#include"RowColumnClass.h"
#include"PatternClass.h"
#include"readPpmHeader.h"
#include"checkPpmFileName.h"
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

ColorImageClass::ColorImageClass(): height(0), width(0), pixelColors(0)
{ ; }

void ColorImageClass::initializeImage(const int height, const int width)
{
    pixelColors = new ColorClass*[height];
    for(int rowIndex = 0; rowIndex < height; rowIndex++)
    {
        pixelColors[rowIndex] = new ColorClass[width];
    }

}

ColorImageClass::~ColorImageClass()
{
    for(int rowIndex = 0; rowIndex < height; rowIndex++)
    {
        delete [] pixelColors[rowIndex];
    }
    delete [] pixelColors;
}

bool ColorImageClass::readImageFromFile(ifstream &inFile, string &errorMessage)
{
    bool isHeaderValid = readPpmHeader(inFile, height, width, errorMessage);

    if(!isHeaderValid)
    {
        return false;
    }


    initializeImage(height, width);
    for(int rowIndex = 0; rowIndex < height; rowIndex++)
    {
        for(int colIndex = 0; colIndex < width; colIndex++)
        {
            bool isPixelValid = pixelColors[rowIndex][colIndex]
                                .readColorFromFile(inFile, errorMessage);
            if(!isPixelValid){
                return false;
            }
        }
    }    
    string extraValue;
    if(inFile >> extraValue)
    {
        errorMessage = ERROR_EXTRA_VALUES;
        return false;
    }
    return true;
}


bool ColorImageClass::validateLocation(const int rowIndex, 
                                       const int colIndex) const
{
    if(rowIndex < IMG_MIN_ROW_INDEX ||
       rowIndex > IMG_MIN_ROW_INDEX + height - 1 ||
       colIndex < IMG_MIN_COL_INDEX ||
       colIndex > IMG_MIN_COL_INDEX + width - 1)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool ColorImageClass::setColorAtLocation(const RowColumnClass &inRowCol,
                                         const ColorClass &inColor)
{
    int rowIndex = inRowCol.getRow();
    int colIndex = inRowCol.getCol();

    bool isLocationValid = validateLocation(rowIndex,colIndex);
    if(isLocationValid)
    {
        pixelColors[rowIndex][colIndex].setTo(inColor);
    }
    return isLocationValid;
}

bool ColorImageClass::getColorAtLocation(const RowColumnClass &inRowCol,
                                         ColorClass &outColor) const
{
    int rowIndex = inRowCol.getRow();
    int colIndex = inRowCol.getCol();

    bool isLocationValid = validateLocation(rowIndex,colIndex);
    if(isLocationValid)
    {
        outColor.setTo(pixelColors[rowIndex][colIndex]);
    }
    return isLocationValid;
}

void ColorImageClass::insertImage(const ColorImageClass &inputImage, 
                                  const int startRow, const int startCol,
                                  ColorClass &transparencyColor)
{
    for(int rowIndex = 0; rowIndex < height; rowIndex++)
    {
        for(int colIndex = 0; colIndex < width; colIndex++)
        {
            ColorClass inputColor;
            RowColumnClass locationIndex(rowIndex - startRow, 
                                         colIndex - startCol);
            bool isLocationValid = inputImage.getColorAtLocation(
                                                locationIndex, 
                                                inputColor
                                                );

            if(isLocationValid && !inputColor.compareColor(transparencyColor))
            {
                pixelColors[rowIndex][colIndex].setTo(inputColor);
            }
        }
    }
}

void ColorImageClass::insertPattern(const PatternClass &inputPattern,
                                    const int startRow, const int startCol)
{
    ColorClass patternColor = inputPattern.getPatternColor();
    for(int rowIndex = 0; rowIndex < height; rowIndex++)
    {
        for(int colIndex = 0; colIndex < width; colIndex++)
        {
            RowColumnClass locationIndex(rowIndex - startRow,
                                         colIndex - startCol);
            int patternValue;
            bool isLocationValid = inputPattern.getValueAtLocation(
                                                    locationIndex, 
                                                    patternValue
                                                );
            
            if(isLocationValid && patternValue == 1)
            {
                pixelColors[rowIndex][colIndex] = patternColor;
            }
        }
    }

}


bool ColorImageClass::printImage(string &outFileName, 
                                 string &errorMessage) const
{

    ofstream outFile;
    outFile.open(outFileName.c_str());
    if(outFile.fail())
    {
        errorMessage =  ERROR_OPEN_IMAGE_FILE + outFileName;
        return false;
    }
    else
    {
        outFile << PPM_IDENTIFIER_STRING << endl;
        outFile << width << " " << height << endl;
        outFile << MAX_COLOR_VALUE << endl;
        for(int rowIndex = 0; rowIndex < height; rowIndex++)
        {
            for(int colIndex = 0; colIndex < width; colIndex++)
            {
                
                pixelColors[rowIndex][colIndex].printComponentValues(outFile);
                if(colIndex == width - 1)
                {
                    outFile << endl;
                }
                else
                {
                    outFile << " ";
                }
            }
        }
    }
    return true;
}