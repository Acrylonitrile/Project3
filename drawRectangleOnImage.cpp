#include"drawRectangleOnImage.h"
#include"ColorImageClass.h"
#include"printMenuOptions.h"
#include"checkStreamState.h"
#include"getTwoIntInputs.h"
#include"getSingleIntInput.h"
#include"chooseColorFromMenu.h"
#include"constants.h"
#include<iostream>

using namespace std;

void drawRectangleOnImage(ColorImageClass &inputImage)
{
  int inputOption;
  // variable to keep track of whether all the inputs are satisfactory
  bool isValidOption = false;
  while(!isValidOption)
  {
    // Prints menu for user to choose how to provide inputs
    printMenuOptions(NUM_RECTANGLE_OPTIONS,RECTANGLE_MENU_OPTIONS);
    cout << PROMPT_RECTANGLE_OPTION;
    cin >> inputOption;

    // Error in case of out of bounds input of failed stream
    if(!checkStreamState() || inputOption < 1 || 
       inputOption > NUM_RECTANGLE_OPTIONS)
    {
      cout << ERROR_INVALID_MENU << endl;
    }
    else 
    {
      isValidOption = true;
    }
  }

  // There are the 4 fundamental quantitites calculated in different ways
  // depending on what quantities the user provides
  int height, width, startRow, startCol;

  bool isValidInput = false;
  while(!isValidInput)
  {
    // When user speifies the opposite corners
    if(inputOption == RECTANGLE_CORNER_OPTION)
    {
      int upLeftRow, upLeftCol, lowRightRow, lowRightCol;

      cout << PROMPT_RECTANGLE_INPUT_1_1;
      if(getTwoIntInputs(upLeftRow, upLeftCol))
      {
        cout << PROMPT_RECTANGLE_INPUT_1_2;
        if(getTwoIntInputs(lowRightRow,lowRightCol))
        {

          // Checks in case the lower right point is not actually
          // lower right to the first point
          startRow = upLeftRow;
          startCol = upLeftCol;
          height = lowRightRow - upLeftRow;
          width = lowRightCol - upLeftCol;
          if(height > 0 || width > 0)
          {
            isValidInput = true;
          }
        }
      }
    }

    // When one corner and width height are specified
    else if(inputOption == RECTANGLE_DIMENSIONS_OPTION)
    {
      cout << PROMPT_RECTANGLE_INPUT_2_1;
      if(getTwoIntInputs(startRow,startCol))
      {
        cout << PROMPT_RECTANGLE_INPUT_2_2;
        // Checking for bad input or non positive height ot width 
        // provided
        if(getSingleIntInput(height) && height > 0)
        {
          cout << PROMPT_RECTANGLE_INPUT_2_3;
          if(getSingleIntInput(width) && width > 0)
          {
            isValidInput = true;
          }
        }
      }
    }

    // When user specified the center and half of width and height
    else if(inputOption == RECTANGLE_CENTRE_OPTION)
    {
      int rowCenter, colCenter, halfWidth, halfHeight;
      cout << PROMPT_RECTANGLE_INPUT_3_1;
      if(getTwoIntInputs(rowCenter, colCenter))
      {
        cout << PROMPT_RECTANGLE_INPUT_3_2;
        if(getSingleIntInput(halfHeight) && halfHeight > 0)
        {
          cout << PROMPT_RECTANGLE_INPUT_3_3;
          if(getSingleIntInput(halfWidth) && halfWidth > 0)
          {
            isValidInput = true;
            height = 2 * halfHeight;
            width = 2 * halfWidth;
            startRow = rowCenter - halfHeight;
            startCol = colCenter - halfWidth;
          }
        }
      }
    }
    if(!isValidInput)
    {
      cout << ERROR_DATA << endl;
    }
  }
  
  // Makes the used choose the color which they want to use
  ColorClass rectangleColor;
  chooseColorFromMenu(rectangleColor, PROMPT_RECTANGLE_COLOR);

  // Makes the user choose the fill options, and checks for bad input
  bool isValidFillValue = false;
  int fillValue;
  while(!isValidFillValue)
  {
    printMenuOptions(NUM_FILL_OPTIONS, RECTANGLE_FILL_OPTIONS);
    cout << PROMPT_RECTANGLE_FILL;
    isValidFillValue = getSingleIntInput(fillValue) &&
                       (fillValue == FILL_NO || fillValue == FILL_YES);
    if(!isValidFillValue)
    {
      cout << ERROR_DATA;
    }
  }
  bool isFilled = (fillValue == FILL_YES);
  
  // Finally performs insertion after validation is completed
  PatternClass rectangle;
  rectangle.initializePattern(height,width);
  rectangle.setToRectangle(isFilled);
  rectangle.setPatternColor(rectangleColor);
  
  inputImage.insertPattern(rectangle, startRow, startCol);
}
