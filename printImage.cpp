#include"printImage.h"
#include"constants.h"
#include"checkPpmFileName.h"
#include"ColorImageClass.h"
#include"getSingleString.h"
#include<iostream>
#include<string>

using namespace std;

// Programmer: Anhad Bhati
// Date: November 10, 2026
//
// Purpose: 
// Called when user desires to print the current image on a ppm file. 
// Asks the user to provide output file name and prints is only when
// It is a valid .ppm file

void printImage(ColorImageClass &inputImage, string &errorMessage)
{
    bool isValidInput = false;
      while(!isValidInput)
      {
        string outFileName;
        cout << PROMPT_OUTPUT_FILENAME;

        if(!getSingleString(outFileName) || 
           !checkPpmFileName(outFileName, errorMessage))
        {
          cout << ERROR_INVALID_PPM << endl;
        }
        else{
          isValidInput = true;
          bool hasPrinted = inputImage.printImage(outFileName, errorMessage);
          if(!hasPrinted){
            cout << errorMessage << endl;
          }
        }
      }
}