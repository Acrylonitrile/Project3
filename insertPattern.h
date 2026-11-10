#ifndef INSERTPATTERN_H
#define INSERTPATTERN_H

#include"ColorImageClass.h"
#include<string>

using namespace std;

// Called when the used chooses to insert a pattern. Will prompt the user
// to input the name of the pattern file, desired color and position, verifies 
// it having the proper input and then performs the insertion
// Unlike ppm files, pattern files are not assumed to have proper file etension
// as it was not specified in the requirements but headers will be verified
void insertPattern(ColorImageClass &inputImage, string &errorMessage);

#endif