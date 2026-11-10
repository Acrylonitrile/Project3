#ifndef CHOOSECOLORFROMMENU_H
#define CHOOSECOLORFROMMENU_H

#include"ColorClass.h"
#include<string>

// Prints a menu of colors to choose from, since the menu is required in
// all th functionalities, except with different promptMessage at the end.
// The chosen color is then stored in the object inColor
// User has to input a number between 1-5
void chooseColorFromMenu(ColorClass &inColor, string promptMessage);

#endif