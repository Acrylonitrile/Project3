all: imageMods402.exe

imageMods402.o: imageMods402.cpp ColorImageClass.h constants.h checkPpmFileName.h printMenuOptions.h getSingleString.h getSingleIntInput.h checkRange.h RectangleClass.h
	g++ -std=c++98 -Wall -c imageMods402.cpp -o imageMods402.o

clipValue.o: clipValue.cpp clipValue.h
	g++ -std=c++98 -Wall -c clipValue.cpp -o clipValue.o

validateSingleInt.o: validateSingleInt.cpp validateSingleInt.h getSingleIntInput.h
	g++ -std=c++98 -Wall -c validateSingleInt.cpp -o validateSingleInt.o

validateTwoInts.o: validateTwoInts.cpp validateTwoInts.h getTwoIntInputs.h
	g++ -std=c++98 -Wall -c validateTwoInts.cpp -o validateTwoInts.o

printMenuOptions.o: printMenuOptions.cpp printMenuOptions.h
	g++ -std=c++98 -Wall -c printMenuOptions.cpp -o printMenuOptions.o

getSingleString.o: getSingleString.cpp getSingleString.h constants.h
	g++ -std=c++98 -Wall -c getSingleString.cpp -o getSingleString.o

getSingleIntInput.o: getSingleIntInput.cpp getSingleIntInput.h constants.h
	g++ -std=c++98 -Wall -c getSingleIntInput.cpp -o getSingleIntInput.o 

getTwoIntInputs.o: getTwoIntInputs.cpp getTwoIntInputs.h constants.h
	g++ -std=c++98 -Wall -c getTwoIntInputs.cpp -o getTwoIntInputs.o

checkPpmFileName.o: checkPpmFileName.cpp checkPpmFileName.h
	g++ -std=c++98 -Wall -c checkPpmFileName.cpp -o checkPpmFileName.o

checkRange.o: checkRange.cpp checkRange.h
	g++ -std=c++98 -Wall -c checkRange.cpp -o checkRange.o

ColorClass.o: ColorClass.cpp ColorClass.h clipValue.h checkRange.h constants.h printMenuOptions.h getSingleIntInput.h
	g++ -std=c++98 -Wall -c ColorClass.cpp -o ColorClass.o

RowColumnClass.o: RowColumnClass.cpp RowColumnClass.h constants.h
	g++ -std=c++98 -Wall -c RowColumnClass.cpp -o RowColumnClass.o

RectangleClass.o: RectangleClass.cpp RectangleClass.h ColorClass.h RowColumnClass.h RowColumnClass.h validateSingleInt.h validateTwoInts.h getSingleIntInput.h printMenuOptions.h checkRange.h constants.h
	g++ -std=c++98 -Wall -c RectangleClass.cpp -o RectangleClass.o

PatternClass.o: PatternClass.cpp PatternClass.h constants.h checkRange.h ColorClass.h RowColumnClass.h validateSingleInt.h validateTwoInts.h getSingleString.h printMenuOptions.h
	g++ -std=c++98 -Wall -c PatternClass.cpp -o PatternClass.o

ColorImageClass.o: ColorImageClass.cpp ColorImageClass.h constants.h ColorClass.h RowColumnClass.h PatternClass.h checkPpmFileName.h PatternClass.h checkRange.h validateTwoInts.h RectangleClass.h
	g++ -std=c++98 -Wall -c ColorImageClass.cpp -o ColorImageClass.o

imageMods402.exe: clipValue.o printMenuOptions.o getSingleIntInput.o getTwoIntInputs.o checkPpmFileName.o checkRange.o ColorClass.o RowColumnClass.o RectangleClass.o PatternClass.o ColorImageClass.o getSingleString.o validateSingleInt.o validateTwoInts.o imageMods402.o 
	g++ -std=c++98 -Wall clipValue.o printMenuOptions.o getSingleIntInput.o getTwoIntInputs.o checkPpmFileName.o checkRange.o ColorClass.o RowColumnClass.o RectangleClass.o PatternClass.o ColorImageClass.o getSingleString.o validateSingleInt.o validateTwoInts.o imageMods402.o -o imageMods402.exe 

clean:
	rm -f *.o *.exe