#include"insertImage.h"
#include"constants.h"
#include"checkPpmFileName.h"
#include"validateTwoInts.h"
#include"chooseColorFromMenu.h"
#include"ColorImageClass.h"
#include"getSingleString.h"
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

using namespace std;

// Programmer: Anhad Bhati
// Date: November 10, 2026
//
// Purpose: 
// This function is called when the used chooses the insert image option
// Asks the user to provide output file name and validates it as a 
// valid .ppm file
// On successfull validation, prompts the user to input position and 
// choose transparency color and validates those inputs as well

void insertImage(ColorImageClass &inputImage, string &errorMessage)
{
    string annotateFileName;
    cout << PROMPT_INSERT_IMAGE_NAME;
    getSingleString(annotateFileName);
    ifstream inFile;

    
    bool isValidFileName = checkPpmFileName(annotateFileName, errorMessage);
    if(!isValidFileName)
    {
    cout << errorMessage << endl;
    }
    else
    {
        // .ppm extensino has been verified
        bool isInputValid = false;
        
        while(!isInputValid)
        {
            int startRow, startCol;
            // starting row and column input
            validateTwoInts(startRow,startCol, 
                            PROMPT_ENTER_PATTERN_POSITION,
                            ERROR_DATA);


            // Choosing transparency coor
            ColorClass transparencyColor;
            chooseColorFromMenu(transparencyColor, PROMPT_TRANSPARENCY_COLOR);

            isInputValid = true;
            inFile.open(annotateFileName.c_str());
            // handling bad filename
            if(inFile.fail())
            {
                cout << ERROR_OPEN_IMAGE_FILE << annotateFileName << endl;
            }
            else
            {

                ColorImageClass annotateImage;
                // reads image and verifies that it has the proper values
                bool isValidImage = annotateImage.readImageFromFile(
                                                inFile,errorMessage
                                                );
                if(!isValidImage)
                {
                cout << errorMessage << endl;
                }
                else
                {
                inputImage.insertImage(annotateImage, 
                                    startRow, startCol,       
                                    transparencyColor);
                }
            }
        }
    }

      
}