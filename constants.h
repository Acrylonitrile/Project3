#ifndef CONSTANTS_H
#define CONSTANTS_H

#include<string>
using namespace std;

const int DEFAULT_USER_CHOICE = 0;
const int MIN_DIMENSION_VALUE = 1;
const int MAX_DIMENSION_VALUE = 2000;
const string PPM_IDENTIFIER_STRING = "P3";

const string ERROR_NO_INPUT_IMAGE = 
            "Error: No Input Image provided";

const string ERROR_DATA = 
            "Invalid data entered";
const string ERROR_OPEN_PATTERN_FILE = 
            "Error: Unable to open pattern file: ";
const string ERROR_OPEN_IMAGE_FILE = 
            "Error: Unable to open image file: ";
const string ERROR_INVALID_MENU = 
            "Invalid menu option!";
const string ERROR_INVALID_PPM = 
            "Invalid .ppm file name!";
const string ERROR_INVALID_COLORS = 
            "Invalid or insufficient color values provided";
const string ERROR_COLOR_OUT_OF_RANGE = 
            "Color Value out of range";
const string ERROR_EXTRA_VALUES = 
            "Values provided exceed (width * height * 3)";
const string ERROR_INCORRECT_DIMENSIONS = 
            "Error: Incorrect dimensions provided";
const string ERROR_INCORRECT_MAGIC_NUM = "Invalid magic number, expected " + 
                                         PPM_IDENTIFIER_STRING + " but got ";
const string ERROR_INCORRECT_MAX_COLOR = 
            "Invalid maximum color value provided";
const string ERROR_NO_HEADER = 
            "Error: No header provided";
const string ERROR_DIMENSIONS = 
            "Error: Dimensions must be between 1 and 2000";


const string PROGRAM_END_MESSAGE = "Thank you for using this program";

const int MAIN_MENU_LENGTH = 5;

const string MAIN_MENU_OPTIONS[MAIN_MENU_LENGTH] = 
                              {
                                "1. Annotate image with rectangle",
                                "2. Annotate image with pattern from file",
                                "3. Insert another image",
                                "4. Write out current image",
                                "5. Exit the program"
                              };

const int RECTANGLE_OPTION = 1;
const int INSERT_PATTERN_OPTION = 2;
const int INSERT_IMAGE_OPTION = 3;
const int WRITE_IMAGE_OPTION = 4;
const int EXIT_OPTION = 5;

const string PROMPT_MAIN_MENU = "Enter int for main menu choice: ";

 
const int NUM_RECTANGLE_OPTIONS = 3;
const string RECTANGLE_MENU_OPTIONS[NUM_RECTANGLE_OPTIONS] =
                              {
                                "1. Specify upper left and lower right corners of rectangle",
                                "2. Specify upper left corner and dimensions of rectangle" ,
                                "3. Specify extent from center of rectangle"
                              };

const int RECTANGLE_CORNER_OPTION = 1;
const int RECTANGLE_DIMENSIONS_OPTION = 2;
const int RECTANGLE_CENTRE_OPTION = 3;

const string PROMPT_RECTANGLE_OPTION = 
             "Enter int for rectangle specification method: ";

const string RECTANGLE_OPTION_1 = 
                        "1. Specify upper left and lower right corners of rectangle";
const string PROMPT_RECTANGLE_INPUT_1_1 = 
                        "Enter upper left corner row and column: ";
const string PROMPT_RECTANGLE_INPUT_1_2 = 
                        "Enter lower right corner row and column: ";

const string RECTANGLE_OPTION_2 = 
                        "2. Specify upper left corner and dimensions of rectangle";
const string PROMPT_RECTANGLE_INPUT_2_1 = 
                        "Enter upper left corner row and column: ";
const string PROMPT_RECTANGLE_INPUT_2_2 = 
                        "Enter int for number of rows: ";
const string PROMPT_RECTANGLE_INPUT_2_3 = 
                        "Enter int for number of columns: ";

const string PROMPT_RECTANGLE_INPUT_3_1 = 
                        "Enter rectangle center row and column: ";
const string PROMPT_RECTANGLE_INPUT_3_2 = 
                        "Enter int for half number of rows: ";
const string PROMPT_RECTANGLE_INPUT_3_3 = 
                        "Enter int for half number of columns: ";

const string PROMPT_RECTANGLE_COLOR = 
                        "Enter int for rectangle color: ";

const int NUM_FILL_OPTIONS = 2;
const string RECTANGLE_FILL_OPTIONS[NUM_FILL_OPTIONS] = 
                        {
                            "1. No",
                            "2. Yes"
                        };

const int FILL_YES = 2;
const int FILL_NO = 1;

const string PROMPT_RECTANGLE_FILL = 
                        "Enter int for rectangle fill option: ";

const int COLOR_MENU_LENGTH = 5;
const string COLOR_MENU_OPTIONS[COLOR_MENU_LENGTH] = 
                               {
                                 "1. Red",
                                 "2. Green",
                                 "3. Blue",
                                 "4. Black",
                                 "5. White"
                               };

const int NUM_RED_OPTION = 1;
const int NUM_GREEN_OPTION = 2;
const int NUM_BLUE_OPTION = 3;
const int NUM_BLACK_OPTION = 4;
const int NUM_WHITE_OPTION = 5;

const string PROMPT_INSERT_IMAGE_NAME = 
                        "Enter string for file name of PPM image to insert: ";
const string PROMPT_INSERT_IMAGE_POSITION = 
                        "Enter upper left corner to insert image row and column: ";
const string PROMPT_TRANSPARENCY_COLOR = 
                        "Enter int for transparecy color: ";

const string PROMPT_ENTER_PATTERN_FILE = 
                        "Enter string for file name containing pattern: ";
const string PROMPT_ENTER_PATTERN_POSITION = 
                        "Enter upper left corner of pattern row and column: ";
const string PROMPT_PATTERN_COLOR = 
                        "Enter int for pattern color: ";

const string PROMPT_OUTPUT_FILENAME = 
                        "Enter string for PPM file name to output: ";
   

const string PPM_FILE_EXTENSION = ".ppm";

const int NUM_IGNORE = 200;

const int MAX_NUM_PIXELS = 2000;
const int MIN_NUM_PIXELS = 1;



const int MIN_PATTERN_VALUE = 0;
const int MAX_PATTERN_VALUE = 1;   

const int MIN_COLOR_VALUE = 0;
const int MAX_COLOR_VALUE = 255;

const int INITIAL_ROW_VALUE = -99999;
const int INITIAL_COL_VALUE = -99999;

const int IMG_MIN_ROW_INDEX = 0;
const int IMG_MIN_COL_INDEX = 0;

#endif