#include"constants.h"
#include"ColorClass.h"
#include<iostream>
#include<string>
#include"printMenuOptions.h"
#include"getSingleIntInput.h"

using namespace std;

// Prints a menu of colors to choose from, since the menu is required in
// all th functionalities, except with different promptMessage at the end.
// The chosen color is then stored in the object inColor
// User has to input a number between 1-5

void chooseColorFromMenu(ColorClass &inputColor, string promptMessage)
{
  int colorChoice;
  bool isValidColorChoice = false;
  while(!isValidColorChoice)
  {
    printMenuOptions(COLOR_MENU_LENGTH, COLOR_MENU_OPTIONS);
    cout << promptMessage;

    // checking for bad input or input out of desired range
    if(!getSingleIntInput(colorChoice) || 
        colorChoice < 1 || colorChoice > COLOR_MENU_LENGTH)
    {
      cout << ERROR_INVALID_MENU << endl;
    }
    else
    {
      isValidColorChoice = true;
    }
  }
  inputColor.setToUserOption(colorChoice);
}