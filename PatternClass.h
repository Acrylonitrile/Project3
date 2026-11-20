#ifndef PATTERNCLASS_H
#define PATTERNCLASS_H

#include "ColorClass.h"
#include "RowColumnClass.h"
#include <fstream>

using namespace std;

// Programmer: Anhad Bhati
// Date: November 10, 2026
//
// Purpose:
// Encodes information on a given pattern, using height, widths, values 1/0
// and the color the user would like to draw the pattern in

class PatternClass
{
private:
  int height, width;
  int startRow, startCol;
  int **patternValues;
  ColorClass patternColor;
  // Take height and width and Dynamically allocates memory to hold
  // pattern values
  void initializePattern(const int height, const int width);

  // Clears the dynamically allocated memory to the pattern
  void clearPattern();
public:
  // Initializes height, width and patternValues to 0
  PatternClass();

  // Initializes to input height and width
  PatternClass(const int inHeight, const int inWidth);

  ~PatternClass();

  // Getter functions for startRow and startCol
  int getStartRow() const;
  int getStartCol() const;

  // Prompts the user to input startRow, startCol and patternColor
  // Validates and stores it only when valid
  void readPatternAttributes();
  // Takes in file input name, and stores it in the object while
  // validating the values. returns false on bad input
  bool readPatternFromFile(ifstream &inFile, string &errorMessage);

  // Gets the pattern value (1/0) at that particular location, by first
  // verifying if the location is a valid location, and returns true if so
  bool getValueAtLocation(const RowColumnClass &inRowCol, int &outValue) const;

  // Gets the patternColor attribute
  ColorClass getPatternColor() const;

  // Sets the value specified in the position
  void setPatternValue(const int inValue,
                       const int rowIndex,
                       const int colIndex);

  // Sets patternColor to the given color
  void setPatternColor(const ColorClass &inColor);
};

#endif