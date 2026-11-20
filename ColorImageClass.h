#ifndef COLORIMAGECLASS_H
#define COLORIMAGECLASS_H

#include "constants.h"
#include "ColorClass.h"
#include "RowColumnClass.h"
#include "PatternClass.h"
#include "RectangleClass.h"
#include <string>
#include <fstream>

using namespace std;

// Programmer: Anhad Bhati
// Date: November 10, 2026
//
// Purpose:
// This class represents an image, with each pixel represented by colorclass
// object


class ColorImageClass
{
private:
  int height;
  int width;
  int startRow;
  int startCol;
  ColorClass **pixelColors;
  ColorClass transparencyColor;

  // Checks if the location (rowIndex, colIndex) provided is within the
  // bounds of the image. Returns true only if the location is valid
  bool validateLocation(const int rowIndex, const int colIndex) const;
  // Reads the ppm heeader and verifies if it has the correct format
  bool readPpmHeader(ifstream &inFile, int &numRows, int &numCols,
                     string &errorMessage);
  // Initializes to desired width and height and dynamucally allocates
  // memor for image
  void initializeImage(const int numRows, const int numCols);

  // clears all the dynamically allocated memory
  void clearImage();
public:
  // Default constructor initializes all to 0
  ColorImageClass();

  // deletes allocated memory on destruction
  ~ColorImageClass();

  // getters for startRow and startCol
  int getStartRow() const;
  int getStartCol() const;

  // returns the transparency color of the image
  ColorClass getTransparencyColor() const;

  // Prompts the user to enter the startRow, startCol, and choose the 
  // transparency color for the image
  void readImageAttributes();

  // Reads RGB values from a ppm file. Returns false in case of bad values, or 
  // less or more values than expected
  bool readImageFromFile(ifstream &inFile, string &errorMessage);

  // Sets the color at the location specified by the RowCOlumnClass object
  bool setColorAtLocation(const RowColumnClass &inRowCol,
                          const ColorClass &inColor);

  // Gets the Color value at the specified position, if the location is invalid,
  // returns false
  bool getColorAtLocation(const RowColumnClass &inRowCol,
                          ColorClass &outColor) const;

  // Inserts an image onto itself, positions with transparency color are
  // unaffected. Starting position is the upper left corner of the image
  // and can be negative. negative indexes are ignored and only the
  // overlaping regions are added
  void insertImage(const ColorImageClass &inputImage);

  // Same as insertImage, but we insert a pattern instead
  void insertPattern(const PatternClass &inputPattern);

  void insertRectangle(const RectangleClass &inputRectangle);

  // Prints the color values of all the pixels, one row in each line
  // as a .ppm file along with the proper headers.
  void printImage(ofstream &outFile) const;
};

#endif