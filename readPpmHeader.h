#ifndef READPPMHEADER_H
#define READPPMHEADER_H

#include<fstream>
#include<string>

using namespace std;

// Programmer: Anhad Bhati
// Date: November 10, 2026
//
// Purpose:
// Reads the ppm heeader and verifies if it has the correct format

bool readPpmHeader(ifstream &inFile, int &numRows, int &numCols,
                   string &errorMessage);

#endif