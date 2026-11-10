#include"checkPpmFileName.h"
#include"constants.h"
#include<string>

using namespace std;


// Programmer: Anhad Bhati
// Date: November 10, 2026
//
// Purpose: 
// This function validates whether a filename is a valid .ppm file

bool checkPpmFileName(const string &fileName, string &errorMessage)
{
    if(fileName.length() <= PPM_FILE_EXTENSION.length() ||
       fileName.substr(fileName.length() - PPM_FILE_EXTENSION.length()) 
       != PPM_FILE_EXTENSION)
    {
        errorMessage = ERROR_INVALID_PPM;
        return false;
    }
    else
    {
        return true;
    }
}