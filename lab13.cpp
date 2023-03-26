// LAB 13 - MAKE FILE, main.cpp vs functions file vs. prototypes file. 
// makefile - simple
testProg: main.o util.o makefile
        g++ main.o util.o -o testProg

main.o: main.cpp util.h
        g++ -c main.cpp

util.o: util.cpp util.h
        g++ -c util.cpp

// makefile - variables 
TARGET=testProg
MODULES=main.o util.o
CPPFLAGS=-ansi -pedantic-errors -Wall -Wconversion

$(TARGET): $(MODULES)
        g++ $(MODULES) -o $(TARGET)

main.o:  main.cpp util.h
        g++ $(CPPFLAGS) -c main.cpp

util.o:  util.cpp util.h
        g++ $(CPPFLAGS) -c util.cpp

// main.cpp - the outline which calls upon the functions
#include <iostream>
#include "util.h"
using namespace std;

int main()
{
  cout << "Hello world!" << endl;
  util();

  return 0;
}

// util.h - contains the prototypes for the functions in util.cpp
void util();
 
// util.cpp - the functions, with the prototypes in util.h and called in main.cpp 
#include <iostream>
#include "util.h"
using namespace std;

void util()
{
  cout << "Hi, I'm in util." << endl;

  return;
}



