#ifndef CHECKPPMFILENAME_H
#define CHECKPPMFILENAME_H

#include<string>
using namespace std;

// Takes string filename and checks for .ppm extention. names shorter than
bool checkPpmFileName(const string &fileName, string &errorMessage);

#endif