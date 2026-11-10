#ifndef COLORIMAGECLASS_H
#define COLORIMAGECLASS_H

#include"constants.h"
#include"ColorClass.h"
#include"RowColumnClass.h"
#include"PatternClass.h"
#include<string>
#include<fstream>

using namespace std;

class ColorImageClass
{
    private:
        int height;
        int width;
        ColorClass** pixelColors;

        // Checks if the location (rowIndex, colIndex) provided is within the
        // bounds of the image. Returns true only if the location is valid
        bool validateLocation(const int rowIndex, const int colIndex) const;
    public:
        // Default constructor initializes all to 0
        ColorImageClass();

        // Initializes to desired width and height and dynamucally allocates
        // memor for image
        void initializeImage(const int numRows, const int numCols);

        // deletes allocated memory on destruction
        ~ColorImageClass();

        // Reads RGB values from a ppm file (which is already verified for 
        // proper header). Returns false in case of bad values, or less or 
        // more values than expected
        bool readImageFromFile(ifstream &inFile, string &errorMessage);
        
        // Sets the color at the location specified by the RowCOlumnClass object
        bool setColorAtLocation(const RowColumnClass &inRowCol,
                                const ColorClass &inColor);
        
        // Gets the Color value at the specified position
        bool getColorAtLocation(const RowColumnClass &inRowCol,
                                ColorClass &outColor) const;

        // Inserts an image onto itself, positions with transparency color are
        // unaffected. Starting position is the upper left corner of the image
        // and can be negative. negative indexes are ignored and only the 
        // overlaping regions are added
        void insertImage(const ColorImageClass &inputImage, 
                         const int startRow, const int startCol,
                         ColorClass &transparencyColor);

        // Same as insertImage, but we insert a pattern instead
        void insertPattern(const PatternClass &inputPattern,
                           const int startRow, const int startCol);
                           

        // Prints the color values of all the pixels, one row in each line
        // as a .ppm file along with the proper headers.
        bool printImage(string &outFileName, string &errorMessage) const;
};

#endif