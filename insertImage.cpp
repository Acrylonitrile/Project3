#include"insertImage.h"
#include"constants.h"
#include"checkPpmFileName.h"
#include"getTwoIntInputs.h"
#include"chooseColorFromMenu.h"
#include"ColorImageClass.h"
#include<iostream>
#include<fstream>
#include<string>

using namespace std;


void insertImage(ColorImageClass &inputImage, string &errorMessage)
{
    string annotateFileName;
    cout << PROMPT_INSERT_IMAGE_NAME;
    cin >> annotateFileName;
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

        cout << PROMPT_INSERT_IMAGE_POSITION;

        // starting row and column input
        isInputValid = getTwoIntInputs(startRow, startCol);
        if(!isInputValid)
        {
        cout << ERROR_DATA << endl;
        }
        else
        {

        // Choosing transparency coor
        ColorClass transparencyColor;
        chooseColorFromMenu(transparencyColor, PROMPT_TRANSPARENCY_COLOR);

        isInputValid = true;
        inFile.open(annotateFileName);
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

      
}