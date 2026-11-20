#ifndef CHECKPPMFILENAME_H
#define CHECKPPMFILENAME_H

#include<string>
using namespace std;

// Programmer: Anhad Bhati
// Date: November 10, 2026
//
// Purpose:
// This function validates whether a filename is a valid .ppm file


bool checkPpmFileName(const string &fileName, string &errorMessage);

#endif