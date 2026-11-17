#ifndef READPPMHEADER_H
#define READPPMHEADER_H

#include<fstream>
#include<string>

using namespace std;

bool readPpmHeader(ifstream &inFile, int &numRows, int &numCols,
                   string &errorMessage);

#endif