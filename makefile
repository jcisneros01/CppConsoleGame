run: main.cpp game.cpp  space.cpp basegateroom.cpp shipgateroom.cpp shipresearchroom.cpp shipbridge.cpp shipengineeringroom.cpp  shipobservationroom.cpp validateInput.cpp
	g++ -std=c++0x main.cpp game.cpp  space.cpp basegateroom.cpp shipgateroom.cpp shipresearchroom.cpp shipbridge.cpp shipengineeringroom.cpp  shipobservationroom.cpp validateInput.cpp -o run
clean:
	rm -f *.o run
zip:
	zip -l lib.zip  ./*.cpp ./*.hpp ./Makefile 




