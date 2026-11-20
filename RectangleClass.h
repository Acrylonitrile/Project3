#ifndef RECTANGLECLASS_H
#define RECTANGLECLASS_H

#include"ColorClass.h"
#include"RowColumnClass.h"
#include<string>

// Programmer: Anhad Bhati
// Date: November 10, 2026
//
// Purpose:
// Encodes information on a given rectangle, including starting row, column, 
// height, width, filled or not filled, color. 

class RectangleClass
{
  private:
    int height;
    int width;
    int startRow;
    int startCol;
    bool isFilled;
    ColorClass rectangleColor;
  public:
    // Default constructor
    RectangleClass();
    // getter functions
    int getStartRow() const;
    int getStartCol() const;
    bool getIsFilled() const;
    ColorClass getRectangleColor() const;

    // Checks if the location is valid and outputs 1 only if that location 
    // is within the rectangle and has color, i.e. either on the boundary
    // in case of unfilled or else within the rectangle or on the boundary if 
    // filled
    bool getValueAtLocation(const RowColumnClass &inRowCol) const;

    // Displays a menu for the user to input the dimensions of rectangle and 
    // and stores it within upon successful validation
    bool readRectanglefromInput(string &errorMessage);
};

#endif