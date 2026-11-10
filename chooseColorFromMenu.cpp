#include"constants.h"
#include"ColorClass.h"
#include<iostream>
#include<string>
#include"printMenuOptions.h"
#include"getSingleIntInput.h"

using namespace std;

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