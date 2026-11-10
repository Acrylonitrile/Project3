#ifndef INSERTIMAGE_H
#define INSERTIMAGE_H

#include"ColorImageClass.h"
#include<string>

using namespace std;

// This is called when the used chooses the insert image option
// Asks the user to provide output file name and validates it as a 
// valid .ppm file
// On successfull validation, prompts the user to input position and 
// choose transparency color and validates those inputs as well

void insertImage(ColorImageClass &inputImage, string &errorMessage);

#endif