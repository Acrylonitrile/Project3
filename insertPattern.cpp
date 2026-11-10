#include"insertPattern.h"
#include"constants.h"
#include"chooseColorFromMenu.h"
#include"getTwoIntInputs.h"
#include"ColorImageClass.h"
#include<string>
#include<iostream>

using namespace std;

void insertPattern(ColorImageClass &inputImage, string &errorMessage)
{
    string patternFileName;
      bool isInputValid = false;

      cout << PROMPT_ENTER_PATTERN_FILE;
      cin >> patternFileName;
      while(!isInputValid)
      {
        int startRow, startCol;
        // validating position input
        cout << PROMPT_ENTER_PATTERN_POSITION;
        isInputValid = getTwoIntInputs(startRow,startCol);
        if(!isInputValid)
        {
          cout << ERROR_DATA << endl;
        }
        else
        {
          // choosing color from menu
          ColorClass patternColor;
          chooseColorFromMenu(patternColor, PROMPT_PATTERN_COLOR);

          // Reading pattern from file and validation
          PatternClass annotatePattern;
          bool isValidPattern = annotatePattern.readPatternFromFile
                                                (patternFileName,
                                                 errorMessage);
          if(!isValidPattern)
          {
            cout << errorMessage << endl;
          }
          else
          {
            // Insert in successful validation
            annotatePattern.setPatternColor(patternColor);
            inputImage.insertPattern(annotatePattern, startRow, startCol);
          }
        }
      }
}