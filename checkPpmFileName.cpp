#include"checkPpmFileName.h"
#include"constants.h"
#include<string>

using namespace std;


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