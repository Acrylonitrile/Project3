#include"printImage.h"
#include"constants.h"
#include"checkPpmFileName.h"
#include"ColorImageClass.h"
#include<iostream>
#include<string>

using namespace std;

void printImage(ColorImageClass &inputImage, string &errorMessage)
{
    bool isValidInput = false;
      while(!isValidInput)
      {
        string outFileName;
        cout << PROMPT_OUTPUT_FILENAME;
        cin >> outFileName;

        if(cin.fail() || !checkPpmFileName(outFileName, errorMessage))
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