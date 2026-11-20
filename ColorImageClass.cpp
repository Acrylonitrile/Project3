#include "ColorImageClass.h"
#include "constants.h"
#include "ColorClass.h"
#include "RowColumnClass.h"
#include "PatternClass.h"
#include "checkPpmFileName.h"
#include "checkRange.h"
#include "validateTwoInts.h"
#include "RectangleClass.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Programmer: Anhad Bhati
// Date: November 10, 2026
//
// Purpose:
// This class represents an image, with each pixel represented by colorclass
// object

ColorImageClass::ColorImageClass() : height(0), width(0), startRow(0), 
                                     startCol(0), pixelColors(0)
                                     
{ ; }

void ColorImageClass::initializeImage(const int height, const int width)
{
  clearImage();
  pixelColors = new ColorClass *[height];
  for (int rowIndex = 0; rowIndex < height; rowIndex++)
  {
    pixelColors[rowIndex] = new ColorClass[width];
  }
}

ColorImageClass::~ColorImageClass()
{
  clearImage();
}

void ColorImageClass::clearImage()
{
  if (pixelColors != 0)
  {
    for (int rowIndex = 0; rowIndex < height; rowIndex++)
    {
      delete[] pixelColors[rowIndex];
    }
    delete[] pixelColors;
  }
  pixelColors = 0;
}

int ColorImageClass::getStartRow() const
{
  return startRow;
}

int ColorImageClass::getStartCol() const
{
  return startCol;
}

ColorClass ColorImageClass::getTransparencyColor() const
{
  return transparencyColor;
}

void ColorImageClass::readImageAttributes()
{
  validateTwoInts(startRow, startCol,
                  PROMPT_INSERT_IMAGE_POSITION,
                  ERROR_DATA);

  // Choosing transparency color
  transparencyColor.chooseColorFromMenu(PROMPT_TRANSPARENCY_COLOR);
}

bool ColorImageClass::readPpmHeader(ifstream &inFile, 
                                    int &numRows, int &numCols, 
                                    string &errorMessage)
{
  string magicNumber;
  int maxColorValue;

  inFile >> magicNumber;
  // Checking for no or incorrect magic number
  if (inFile.fail())
  {
    errorMessage = ERROR_NO_HEADER;
    return false;
  }
  if (magicNumber != PPM_IDENTIFIER_STRING)
  {
    errorMessage = ERROR_INCORRECT_MAGIC_NUM + magicNumber;
    return false;
  }

  // checking for width and height valid and within bounds
  inFile >> numCols >> numRows;
  if (inFile.fail())
  {
    errorMessage = ERROR_INCORRECT_DIMENSIONS;
    return false;
  }
  if (!checkRange(numCols, MIN_DIMENSION_VALUE, MAX_DIMENSION_VALUE) ||
      !checkRange(numRows, MIN_DIMENSION_VALUE, MAX_DIMENSION_VALUE))
  {
    errorMessage = ERROR_DIMENSIONS_RANGE;
    return false;
  }
  // Checking if the max color value in the header is 255
  inFile >> maxColorValue;
  if (inFile.fail() || maxColorValue != MAX_COLOR_VALUE)
  {
    errorMessage = ERROR_INCORRECT_MAX_COLOR;
    return false;
  }
  return true;
}

bool ColorImageClass::readImageFromFile(ifstream &inFile, string &errorMessage)
{
  // Verify ppm header
  bool isHeaderValid = readPpmHeader(inFile, height, width, errorMessage);

  if (!isHeaderValid)
  {
    return false;
  }

  initializeImage(height, width);
  for (int rowIndex = 0; rowIndex < height; rowIndex++)
  {
    for (int colIndex = 0; colIndex < width; colIndex++)
    {
      bool isPixelValid = pixelColors[rowIndex][colIndex]
                              .readColorFromFile(inFile, errorMessage);
      if (!isPixelValid)
      {
        return false;
      }
    }
  }
  string extraValue;
  if (inFile >> extraValue)
  {
    errorMessage = ERROR_EXTRA_VALUES_IMAGE;
    return false;
  }
  return true;
}

bool ColorImageClass::validateLocation(const int rowIndex,
                                       const int colIndex) const
{
  if (!checkRange(rowIndex,IMG_MIN_ROW_INDEX, IMG_MIN_ROW_INDEX + height -1) ||
      !checkRange(colIndex, IMG_MIN_COL_INDEX, IMG_MIN_COL_INDEX + width -1))
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

  bool isLocationValid = validateLocation(rowIndex, colIndex);
  if (isLocationValid)
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

  bool isLocationValid = validateLocation(rowIndex, colIndex);
  if (isLocationValid)
  {
    outColor.setTo(pixelColors[rowIndex][colIndex]);
  }
  return isLocationValid;
}

void ColorImageClass::insertImage(const ColorImageClass &inputImage)
{
  for (int rowIndex = 0; rowIndex < height; rowIndex++)
  {
    for (int colIndex = 0; colIndex < width; colIndex++)
    {
      // Since starting locations can be negative, we take the difference of 
      // coordinates with starting row and column and check if it is a valid 
      // location
      ColorClass inputColor;
      RowColumnClass locationIndex(rowIndex - inputImage.getStartRow(),
                                   colIndex - inputImage.getStartCol());
      bool isLocationValid = inputImage.getColorAtLocation(
                                        locationIndex,
                                        inputColor
                                        );
      // pixel overwritten with input image only if it is a valid location
      // and does not have the transparency color
      if (isLocationValid && 
          !inputColor.compareColor(inputImage.getTransparencyColor()))
      {
        pixelColors[rowIndex][colIndex].setTo(inputColor);
      }
    }
  }
}

void ColorImageClass::insertPattern(const PatternClass &inputPattern)
{
  ColorClass patternColor = inputPattern.getPatternColor();
  for (int rowIndex = 0; rowIndex < height; rowIndex++)
  {
    for (int colIndex = 0; colIndex < width; colIndex++)
    {
      // Since starting locations can be negative, we take the difference of 
      // coordinates with starting row and column and check if it is a valid 
      // location
      RowColumnClass locationIndex(rowIndex - inputPattern.getStartRow(),
                                   colIndex - inputPattern.getStartCol());
      int patternValue;
      bool isLocationValid = inputPattern.getValueAtLocation(
                                          locationIndex,
                                          patternValue
                                          );
      // pixel overwritten only on valid location and having a value of 1
      if (isLocationValid && patternValue == MAX_PATTERN_VALUE)
      {
        pixelColors[rowIndex][colIndex] = patternColor;
      }
    }
  }
}

void ColorImageClass::insertRectangle(const RectangleClass &inputRectangle)
{
  ColorClass rectangleColor = inputRectangle.getRectangleColor();
  for (int rowIndex = 0; rowIndex < height; rowIndex++)
  {
    for (int colIndex = 0; colIndex < width; colIndex++)
    {
      // Since starting locations can be negative, we take the difference of 
      // coordinates with starting row and column and check if it is a valid 
      // location
      RowColumnClass locationIndex(rowIndex - inputRectangle.getStartRow(),
                                   colIndex - inputRectangle.getStartCol());

      bool isLocationValid = inputRectangle.getValueAtLocation(locationIndex);
      // pixel overwritten only on valid location and having a value of 1
      if (isLocationValid)
      {
        pixelColors[rowIndex][colIndex] = rectangleColor;
      }
    }
  }
}

void ColorImageClass::printImage(ofstream &outFile) const
{
  outFile << PPM_IDENTIFIER_STRING << endl;
  outFile << width << " " << height << endl;
  outFile << MAX_COLOR_VALUE << endl;
  for (int rowIndex = 0; rowIndex < height; rowIndex++)
  {
    for (int colIndex = 0; colIndex < width; colIndex++)
    {

      pixelColors[rowIndex][colIndex].printComponentValues(outFile);
      if (colIndex == width - 1)
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
