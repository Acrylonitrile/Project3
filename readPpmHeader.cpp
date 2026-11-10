#include"readPpmHeader.h"
#include"constants.h"
#include"checkRange.h"
#include<fstream>
#include<string>

using namespace std;

// Programmer: Anhad Bhati
// Date: November 10, 2026
//
// Purpose: 
// Reads the ppm heeader and verifies if it has the correct format

bool readPpmHeader(ifstream &inFile, int &numRows, int &numCols, string &errorMessage)
{
    string magicNumber;
    int maxColorValue;

    inFile >> magicNumber;
    // Checking for no or incorrect magic number
    if(inFile.fail())
    {
        errorMessage = ERROR_NO_HEADER;
        return false;
    }
    if(magicNumber != PPM_IDENTIFIER_STRING)
    {
        errorMessage = ERROR_INCORRECT_MAGIC_NUM + magicNumber; 
        return false;
    }

    // checking for width and height within bounds
    inFile >> numCols >> numRows;
    if(inFile.fail())
    {
        errorMessage = ERROR_INCORRECT_DIMENSIONS;
        return false;
    }
    if(!checkRange(numCols,MIN_DIMENSION_VALUE,MAX_DIMENSION_VALUE) || 
       !checkRange(numRows,MIN_DIMENSION_VALUE,MAX_DIMENSION_VALUE))
    {
        errorMessage = ERROR_DIMENSIONS;
        return false;
    }
    // Checking if the max color value in the header is 255
    inFile >> maxColorValue;
    if(inFile.fail() || maxColorValue != MAX_COLOR_VALUE){
        errorMessage = ERROR_INCORRECT_MAX_COLOR;
        return false;
    }
    return true;
}