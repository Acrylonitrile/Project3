#include "insertPattern.h"
#include "constants.h"
#include "chooseColorFromMenu.h"
#include "ColorImageClass.h"
#include "getSingleString.h"
#include "validateTwoInts.h"
#include <string>
#include <iostream>

using namespace std;

// Programmer: Anhad Bhati
// Date: November 10, 2026
//
// Purpose:
// Called when the used chooses to insert a pattern. Will prompt the user
// to input the name of the pattern file, desired color and position, verifies
// it having the proper input and then performs the insertion
// Unlike ppm files, pattern files are not assumed to have proper file etension
// as it was not specified in the requirements but headers will be verified

void insertPattern(ColorImageClass &inputImage, string &errorMessage)
{
  string patternFileName;

  cout << PROMPT_ENTER_PATTERN_FILE;
  getSingleString(patternFileName);

  int startRow, startCol;
  // reading and validating position input
  validateTwoInts(startRow, startCol,
                  PROMPT_ENTER_PATTERN_POSITION,
                  ERROR_DATA);

  // choosing color from menu
  ColorClass patternColor;
  chooseColorFromMenu(patternColor, PROMPT_PATTERN_COLOR);

  // Reading pattern from file and validation
  PatternClass annotatePattern;
  bool isValidPattern = annotatePattern.readPatternFromFile(
                                        patternFileName,
                                        errorMessage
                                        );
  if (!isValidPattern)
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