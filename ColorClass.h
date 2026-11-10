#ifndef COLORCLASS_H
#define COLORCLASS_H

#include<fstream>
#include<string>

using namespace std; 

class ColorClass
{
    private:
        int redValue;
        int greenValue;
        int blueValue;

        // Clips the RGB color values of a ColorClass object between
        // MIN_COLOR_VALUE and MAX_COLOR_VALUE
        bool clipColorValues();
    public:
        // Initializes the object to white colour
        ColorClass();
        
        // Initializes the object with the color values provided in the input
        ColorClass(const int inRed, const int inGreen, const int inBlue);
        
        // Reads RGB values from a file and assigns it to itself, will return 
        // false in case of bad input or color out of range
        bool readColorFromFile(ifstream &inFile, string &errorMessage);

        // Following functions set the color to pre-defined values
        void setToBlack();
        void setToRed();
        void setToGreen();
        void setToBlue();
        void setToWhite();
        // Sets the color of object to the integer values provided in the input

        // Given a userOption 1-5 assigns it to a particular color depending on 
        // the value
        void setToUserOption(int userOption);

        // Returns true only if clipping occurs
        bool setTo(const int inRed, const int inGreen, const int inBlue);

        // Sets the color values to that of the values of ColorClass object
        // provided in the input. Returns true only if clipping occurs
        bool setTo(const ColorClass &inColor);

        // Compares rgb values to that of another ColorClass object
        bool compareColor(const ColorClass &rhsColor) const;

        // Prints the RGB values of the object on the output file
        void printComponentValues(ofstream& outFile) const;
};

#endif
