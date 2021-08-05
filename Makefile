CXX = g++
CXXFLAGS = -std=c++11 -Wall

OBJECTS = game.o question.o question_bank.o
HEADERS = $(shell find . -path ./test -prune -o -name "*.hpp" -print)

main: main.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJECTS): $(HEADERS)

testBuild: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -Itest/catch/catch.hpp -o test/TestCase $(OBJECTS) test/TestCase.cpp

test: clean testBuild
	test/TestCase --success

clean:
	$(RM) *.o *.gch core main test/TestCase