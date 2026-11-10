#ifndef PATTERNCLASS_H
#define PATTERNCLASS_H

#include"ColorClass.h"
#include"RowColumnClass.h"
#include<fstream>

using namespace std;

// Encodes information on a given pattern, using height, widths, values 1/0
// and the color the user would like to draw the pattern in
class PatternClass{
    private:
        int height, width;
        int** patternValues;
        ColorClass patternColor;
    public:
        // Initializes height, width and patternValues to 0
        PatternClass();

        // Take height and width and Dynamically allocates memory to hold 
        // hold pattern values
        void initializePattern(const int height, const int width);

        // Deletes teh allocated memory on destruction
        ~PatternClass();
        
        // Takes in file input name, and stores it in the object while 
        // validating the values. returns false on bad input
        bool readPatternFromFile(string &inputFileName, string &errorMessage);

        // Gets the pattern value (1/0) at that particular location, by first
        // verifying if the location is a valid location
        bool getValueAtLocation(const RowColumnClass &inRowCol, 
                                int &outValue) const;
        
        // Gets the patternColor attribute
        ColorClass getPatternColor() const;

        // Sets the value specified in the position
        void setPatternValue(const int inValue, 
                             const int rowIndex, 
                             const int colIndex);

        // Sets patternColor to the given color
        void setPatternColor(ColorClass &inColor);

        // Used for drawing rectangles. Turns the pattern into a
        // Hollow or filled rectangle
        void setToRectangle(bool isFilled);
};

#endif