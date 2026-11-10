all: imageMods402.exe

imageMods402.o: imageMods402.cpp ColorImageClass.h constants.h checkPpmFileName.h checkStreamState.h printMenuOptions.h drawRectangleOnImage.h insertImage.h printImage.h insertPattern.h getSingleIntInput.h validateSingleInt.h
	g++ -std=c++98 -Wall -c imageMods402.cpp -o imageMods402.o

clipValue.o: clipValue.cpp
	g++ -std=c++98 -Wall -c clipValue.cpp -o clipValue.o

validateSingleInt.o: validateSingleInt.cpp getSingleIntInput.h
	g++ -std=c++98 -Wall -c validateSingleInt.cpp -o validateSingleInt.o

validateTwoInts.o: validateTwoInts.cpp getTwoIntInputs.h
	g++ -std=c++98 -Wall -c validateTwoInts.cpp -o validateTwoInts.o

chooseColorFromMenu.o: chooseColorFromMenu.cpp constants.h ColorClass.h getSingleIntInput.h printMenuOptions.h getSingleIntInput.h
	g++ -std=c++98 -Wall -c chooseColorFromMenu.cpp -o chooseColorFromMenu.o

printMenuOptions.o: printMenuOptions.cpp
	g++ -std=c++98 -Wall -c printMenuOptions.cpp -o printMenuOptions.o

getSingleString.o: getSingleString.cpp constants.h
	g++ -std=c++98 -Wall -c getSingleString.cpp -o getSingleString.o

getSingleIntInput.o: getSingleIntInput.cpp constants.h
	g++ -std=c++98 -Wall -c getSingleIntInput.cpp -o getSingleIntInput.o 

getTwoIntInputs.o: getTwoIntInputs.cpp constants.h
	g++ -std=c++98 -Wall -c getTwoIntInputs.cpp -o getTwoIntInputs.o

checkStreamState.o: checkStreamState.cpp
	g++ -std=c++98 -Wall -c checkStreamState.cpp -o checkStreamState.o

readPpmHeader.o: readPpmHeader.cpp constants.h checkRange.h
	g++ -std=c++98 -Wall -c readPpmHeader.cpp -o readPpmHeader.o

checkPpmFileName.o: checkPpmFileName.cpp
	g++ -std=c++98 -Wall -c checkPpmFileName.cpp -o checkPpmFileName.o

checkRange.o: checkRange.cpp
	g++ -std=c++98 -Wall -c checkRange.cpp -o checkRange.o

ColorClass.o: ColorClass.cpp clipValue.h checkRange.h constants.h
	g++ -std=c++98 -Wall -c ColorClass.cpp -o ColorClass.o

RowColumnClass.o: RowColumnClass.cpp constants.h
	g++ -std=c++98 -Wall -c RowColumnClass.cpp -o RowColumnClass.o

PatternClass.o: PatternClass.cpp constants.h checkRange.h ColorClass.h RowColumnClass.h
	g++ -std=c++98 -Wall -c PatternClass.cpp -o PatternClass.o

ColorImageClass.o: ColorImageClass.cpp constants.h ColorClass.h RowColumnClass.h PatternClass.h readPpmHeader.h checkPpmFileName.h PatternClass.h
	g++ -std=c++98 -Wall -c ColorImageClass.cpp -o ColorImageClass.o

drawRectangleOnImage.o: drawRectangleOnImage.cpp constants.h ColorImageClass.h printMenuOptions.h getTwoIntInputs.h getSingleIntInput.h chooseColorFromMenu.h validateSingleInt.h validateTwoInts.h
	g++ -std=c++98 -Wall -c drawRectangleOnImage.cpp -o drawRectangleOnImage.o

insertImage.o: insertImage.cpp constants.h checkPpmFileName.h getTwoIntInputs.h chooseColorFromMenu.h ColorImageClass.h getSingleString.h validateTwoInts.h
		g++ -std=c++98 -Wall -c insertImage.cpp -o insertImage.o

insertPattern.o: insertPattern.cpp constants.h chooseColorFromMenu.h getTwoIntInputs.h ColorImageClass.h getSingleString.h
    g++ -std=c++98 -Wall -c insertPattern.cpp -o insertPattern.o

printImage.o: printImage.cpp constants.h checkPpmFileName.h ColorImageClass.h getSingleString.h
	g++ -std=c++98 -Wall -c printImage.cpp -o printImage.o

imageMods402.exe: clipValue.o chooseColorFromMenu.o printMenuOptions.o getSingleIntInput.o getTwoIntInputs.o checkStreamState.o readPpmHeader.o checkPpmFileName.o checkRange.o ColorClass.o RowColumnClass.o PatternClass.o ColorImageClass.o drawRectangleOnImage.o insertImage.o insertPattern.o printImage.o getSingleString.o validateSingleInt.o validateTwoInts.o imageMods402.o 
	g++ -std=c++98 clipValue.o chooseColorFromMenu.o printMenuOptions.o getSingleIntInput.o getTwoIntInputs.o checkStreamState.o readPpmHeader.o checkPpmFileName.o checkRange.o ColorClass.o RowColumnClass.o PatternClass.o ColorImageClass.o drawRectangleOnImage.o insertImage.o insertPattern.o printImage.o getSingleString.o validateSingleInt.o validateTwoInts.o imageMods402.o -o imageMods402.exe 

clean:
	rm -f *.o *.exe