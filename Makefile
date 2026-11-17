all: imageMods402.exe

imageMods402.o: imageMods402.cpp ColorImageClass.h constants.h checkPpmFileName.h printMenuOptions.h drawRectangleOnImage.h insertImage.h printImage.h insertPattern.h getSingleIntInput.h
	g++ -std=c++98 -Wall -c imageMods402.cpp -o imageMods402.o

clipValue.o: clipValue.cpp clipValue.h
	g++ -std=c++98 -Wall -c clipValue.cpp -o clipValue.o

validateSingleInt.o: validateSingleInt.cpp validateSingleInt.h getSingleIntInput.h
	g++ -std=c++98 -Wall -c validateSingleInt.cpp -o validateSingleInt.o

validateTwoInts.o: validateTwoInts.cpp validateTwoInts.h getTwoIntInputs.h
	g++ -std=c++98 -Wall -c validateTwoInts.cpp -o validateTwoInts.o

chooseColorFromMenu.o: chooseColorFromMenu.cpp chooseColorFromMenu.h constants.h ColorClass.h getSingleIntInput.h printMenuOptions.h getSingleIntInput.h
	g++ -std=c++98 -Wall -c chooseColorFromMenu.cpp -o chooseColorFromMenu.o

printMenuOptions.o: printMenuOptions.cpp printMenuOptions.h
	g++ -std=c++98 -Wall -c printMenuOptions.cpp -o printMenuOptions.o

getSingleString.o: getSingleString.cpp getSingleString.h constants.h
	g++ -std=c++98 -Wall -c getSingleString.cpp -o getSingleString.o

getSingleIntInput.o: getSingleIntInput.cpp getSingleIntInput.h constants.h
	g++ -std=c++98 -Wall -c getSingleIntInput.cpp -o getSingleIntInput.o 

getTwoIntInputs.o: getTwoIntInputs.cpp getTwoIntInputs.h constants.h
	g++ -std=c++98 -Wall -c getTwoIntInputs.cpp -o getTwoIntInputs.o

readPpmHeader.o: readPpmHeader.cpp readPpmHeader.h constants.h checkRange.h
	g++ -std=c++98 -Wall -c readPpmHeader.cpp -o readPpmHeader.o

checkPpmFileName.o: checkPpmFileName.cpp checkPpmFileName.h
	g++ -std=c++98 -Wall -c checkPpmFileName.cpp -o checkPpmFileName.o

checkRange.o: checkRange.cpp checkRange.h
	g++ -std=c++98 -Wall -c checkRange.cpp -o checkRange.o

ColorClass.o: ColorClass.cpp ColorClass.h clipValue.h checkRange.h constants.h
	g++ -std=c++98 -Wall -c ColorClass.cpp -o ColorClass.o

RowColumnClass.o: RowColumnClass.cpp RowColumnClass.h constants.h
	g++ -std=c++98 -Wall -c RowColumnClass.cpp -o RowColumnClass.o

PatternClass.o: PatternClass.cpp PatternClass.h constants.h checkRange.h ColorClass.h RowColumnClass.h
	g++ -std=c++98 -Wall -c PatternClass.cpp -o PatternClass.o

ColorImageClass.o: ColorImageClass.cpp ColorImageClass.h constants.h ColorClass.h RowColumnClass.h PatternClass.h readPpmHeader.h checkPpmFileName.h PatternClass.h
	g++ -std=c++98 -Wall -c ColorImageClass.cpp -o ColorImageClass.o

drawRectangleOnImage.o: drawRectangleOnImage.cpp drawRectangleOnImage.h constants.h ColorImageClass.h printMenuOptions.h getTwoIntInputs.h getSingleIntInput.h chooseColorFromMenu.h validateSingleInt.h validateTwoInts.h
	g++ -std=c++98 -Wall -c drawRectangleOnImage.cpp -o drawRectangleOnImage.o

insertImage.o: insertImage.cpp insertImage.h constants.h checkPpmFileName.h getTwoIntInputs.h chooseColorFromMenu.h ColorImageClass.h getSingleString.h validateTwoInts.h
		g++ -std=c++98 -Wall -c insertImage.cpp -o insertImage.o

insertPattern.o: insertPattern.cpp insertPattern.h constants.h chooseColorFromMenu.h getTwoIntInputs.h ColorImageClass.h getSingleString.h
		g++ -std=c++98 -Wall -c insertPattern.cpp -o insertPattern.o

printImage.o: printImage.cpp printImage.h constants.h checkPpmFileName.h ColorImageClass.h getSingleString.h
	g++ -std=c++98 -Wall -c printImage.cpp -o printImage.o

imageMods402.exe: clipValue.o chooseColorFromMenu.o printMenuOptions.o getSingleIntInput.o getTwoIntInputs.o readPpmHeader.o checkPpmFileName.o checkRange.o ColorClass.o RowColumnClass.o PatternClass.o ColorImageClass.o drawRectangleOnImage.o insertImage.o insertPattern.o printImage.o getSingleString.o validateSingleInt.o validateTwoInts.o imageMods402.o 
	g++ -std=c++98 -Wall clipValue.o chooseColorFromMenu.o printMenuOptions.o getSingleIntInput.o getTwoIntInputs.o readPpmHeader.o checkPpmFileName.o checkRange.o ColorClass.o RowColumnClass.o PatternClass.o ColorImageClass.o drawRectangleOnImage.o insertImage.o insertPattern.o printImage.o getSingleString.o validateSingleInt.o validateTwoInts.o imageMods402.o -o imageMods402.exe 

clean:
	rm -f *.o *.exe