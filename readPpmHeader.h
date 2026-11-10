#ifndef READPPMHEADER_H
#define READPPMHEADER_H

#include<fstream>
#include<string>

using namespace std;

// Reads the ppm heeader and verifies if it has the correct format
bool readPpmHeader(ifstream &inFile, int &numRows, int &numCols,
                   string &errorMessage);

#endif