#include<iostream>
#include<cstdlib>
#include"ColorImageClass.h"
#include"constants.h"
#include<fstream>
#include<string>
#include"checkPpmFileName.h"
#include"checkStreamState.h"
#include"printMenuOptions.h"
#include"drawRectangleOnImage.h"
#include"insertImage.h"
#include"printImage.h"
#include"insertPattern.h"
using namespace std;


// Programmer: Anhad Bhati
// Date: November 10, 2026
//
// Purpose: 
// This Program consists of basic implementation of image processing 
// techniques. We can read a .ppm image and perform the following:
// 1. Annotate and image by drawing a hollow or fillied rectangle
//    with the specified dimensions and positions.
// 2. Annotate and image with a pattern provided as file input
// 3. Insert another image provided as file input on top of the original image
// 4. Print the current image after all the previous modifications
// 
// The user will interact with the program using a menu system which prompts the
// user to provide specific inputs relating to the functionality they want to 
// to implement and to provide the necessary arguments to perform the 
// functionality. 
// Note: filenames with .ppm is expected when providing image files. 

//-------------------------MAIN FUNCTION-----------------------------------//

int main(int argc, char *argv[])
{
  // Common error message which will get passed around inside various
  // functions to recognize specific errors
  string errorMessage = "";

  // Checking for input fileName 
  if(argc < 2)
  {
    cout << ERROR_NO_INPUT_IMAGE << endl;
    exit(2);
  }

  string inputFileName = argv[1];

  // Checking for a valid .ppm extension in filename
  bool isValidFileName = checkPpmFileName(inputFileName, errorMessage);
  if(!isValidFileName)
  {
    cout << errorMessage << endl;
    exit(3);
  }

  ifstream inFile;

  inFile.open(inputFileName.c_str());
  if(inFile.fail())
  {
    cout << ERROR_OPEN_IMAGE_FILE << inputFileName << endl;
    inFile.close();
    exit(3);
  }


  ColorImageClass inputImage;
  
  bool isValidImage = inputImage.readImageFromFile(inFile, errorMessage);
  if(!isValidImage)
  {
    cout << errorMessage << endl;
    exit(3);
  }

  inFile.close();

  //  User input in main menu ranges 1-5, we initialize to 0 by default
  int userChoice = DEFAULT_USER_CHOICE;
  
  while(userChoice != EXIT_OPTION)
  {
    // Main menu display and input prompt
    printMenuOptions(MAIN_MENU_LENGTH, MAIN_MENU_OPTIONS);
    cout << PROMPT_MAIN_MENU; 

    // Check user choice range
    cin >> userChoice;
    if( !checkStreamState() || userChoice < 1 || userChoice > MAIN_MENU_LENGTH)
    {
      cout << ERROR_INVALID_MENU << endl;
      userChoice = 0;
    }
    else if(userChoice == EXIT_OPTION)
    {
      cout << PROGRAM_END_MESSAGE << endl;
      exit(0);
    }

    else if(userChoice == WRITE_IMAGE_OPTION)
    {
      printImage(inputImage, errorMessage);
    }
    else if(userChoice == INSERT_PATTERN_OPTION)
    {
      insertPattern(inputImage,errorMessage);
    }
    else if(userChoice == RECTANGLE_OPTION)
    {
      drawRectangleOnImage(inputImage);
    }
    else if(userChoice == INSERT_IMAGE_OPTION)
    {
      insertImage(inputImage, errorMessage);
    }
    else
    {
      cout << ERROR_INVALID_MENU << endl;
    }
  }
  exit(0);
}

//------------------------------------------------------------------------------