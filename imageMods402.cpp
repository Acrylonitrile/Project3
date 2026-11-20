#include<iostream>
#include<cstdlib>
#include"ColorImageClass.h"
#include"constants.h"
#include<fstream>
#include<string>
#include"checkPpmFileName.h"
#include"printMenuOptions.h"
#include"getSingleString.h"
#include"getSingleIntInput.h"
#include"checkRange.h"
#include"PatternClass.h"
#include"RectangleClass.h"
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
  if(argc < MIN_ARGC)
  {
    cout << ERROR_NO_INPUT_IMAGE << endl;
    exit(EXIT_CODE_INPUT_ERROR);
  }
 
  string inputFileName = argv[FILENAME_INDEX];

  // Checking for a valid .ppm extension in filename
  bool isValidFileName = checkPpmFileName(inputFileName, errorMessage);
  if(!isValidFileName)
  {
    cout << errorMessage << endl;
    exit(EXIT_CODE_FILE_ERROR);
  }

  ifstream inFile;

  inFile.open(inputFileName.c_str());
  if(inFile.fail())
  {
    cout << ERROR_OPEN_IMAGE_FILE << inputFileName << endl;
    inFile.close();
    exit(EXIT_CODE_FILE_ERROR);
  }


  ColorImageClass inputImage;
  
  bool isValidImage = inputImage.readImageFromFile(inFile, errorMessage);
  if(!isValidImage)
  {
    cout << errorMessage << endl;
    exit(EXIT_CODE_FILE_ERROR);
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
    bool isChoiceValid = getSingleIntInput(userChoice);
    if(!isChoiceValid || 
       !checkRange(userChoice, MIN_MENU_CHOICE, MAIN_MENU_LENGTH))
    {
      cout << ERROR_INVALID_MENU << endl;
      userChoice = DEFAULT_USER_CHOICE;
    }
    //----------------------------- WRITE IMAGE---------------------------------
    else if(userChoice == WRITE_IMAGE_OPTION)
    {
      bool isValidFile = false;
      // Validating File name
      while (!isValidFile)
      {
        string outFileName;
        cout << PROMPT_OUTPUT_FILENAME;

        if (!getSingleString(outFileName) ||
            !checkPpmFileName(outFileName, errorMessage))
        {
          cout << ERROR_INVALID_PPM << endl;
        }
        else
        {
          ofstream outFile;
          outFile.open(outFileName.c_str());
          if (outFile.fail())
          {
            cout << ERROR_OPEN_IMAGE_FILE + outFileName << endl;
          }
          else
          { 
          isValidFile = true;
          inputImage.printImage(outFile);
          }
        }
      }
    }
    //------------------------INSERT PATTERN------------------------------------
    else if(userChoice == INSERT_PATTERN_OPTION)
    {
      string patternFileName;
      cout << PROMPT_ENTER_PATTERN_FILE;
      getSingleString(patternFileName);

      PatternClass annotatePattern;
      annotatePattern.readPatternAttributes();

      ifstream inFile;
      inFile.open(patternFileName.c_str());
      if (inFile.fail())
      {
        cout << ERROR_OPEN_PATTERN_FILE + patternFileName << endl;
        inFile.close();
      }
      else
      {
        if(!annotatePattern.readPatternFromFile(inFile, errorMessage))
        {
          cout << errorMessage << endl;
        }
        else
        {
          // Insert in successful validation
          inputImage.insertPattern(annotatePattern);
        }
      }
    }
    //----------------------------- INSERT RECTANGLE ---------------------------
    else if(userChoice == RECTANGLE_OPTION)
    {
      RectangleClass rectangle;
      if(rectangle.readRectanglefromInput(errorMessage))
      {
        inputImage.insertRectangle(rectangle);
      }
      else
      {
        cout << errorMessage << endl;
      }
    }
    //----------------------------- INSERT IMAGE -------------------------------
    else if(userChoice == INSERT_IMAGE_OPTION)
    {
      string annotateFileName;
      cout << PROMPT_INSERT_IMAGE_NAME;
      getSingleString(annotateFileName);
      ifstream inFile;

      bool isValidFileName = checkPpmFileName(annotateFileName, errorMessage);
      if (!isValidFileName)
      {
        cout << errorMessage << endl;
      }
      else
      {
        // .ppm extension has been verified
        ColorImageClass annotateImage;
        annotateImage.readImageAttributes();

        inFile.open(annotateFileName.c_str());
        // handling bad filename
        if (inFile.fail())
        {
          cout << ERROR_OPEN_IMAGE_FILE << annotateFileName << endl;
        }
        else
        {
          // read image and verifies that it has the proper values
          if (!annotateImage.readImageFromFile(inFile, errorMessage))
          {
            cout << errorMessage << endl;
          }
          else
          {
            inputImage.insertImage(annotateImage);
          }
        }
      }
    }
    else if(userChoice != EXIT_OPTION)
    {
      cout << ERROR_INVALID_MENU << endl;
    }
  }
  cout << PROGRAM_END_MESSAGE << endl;
  return 0;
}

//------------------------------------------------------------------------------