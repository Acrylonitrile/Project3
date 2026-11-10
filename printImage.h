#ifndef PRINTIMAGE_H
#define PRINTIMAGE_H

#include"ColorImageClass.h"
#include<string>

using namespace std;

// Called when user desires to print the current image on a ppm file. 
// Asks the user to provide output file name and prints is only when
// It is a valid .ppm file
void printImage(ColorImageClass &inputImage, string &errorMessage);


#endif