#include <iostream> // for std::cout

void doB() { std::cout << "In doB()\n"; }

void doA() {
  std::cout << "In doA()\n";

  doB();
}

// Definition of function main()
int main() {
  std::cout << "Starting main()\n";

  doA();
  doB();

  std::cout << "Ending main()\n";

  return 0;
}

/*

Starting main()
In doA()
In doB()
In doB()
Ending main()

*/


#include <iostream> // for std::cout

void doB()
{
    std::cout << "In doB()\n";
}


void doA()
{
    std::cout << "Starting doA()\n";

    doB();

    std::cout << "Ending doA()\n";
}

// Definition of function main()
int main()
{
    std::cout << "Starting main()\n";

    doA();

    std::cout << "Ending main()\n";

    return 0;
}

/*

Starting main()
Starting doA()
In doB()
Ending doA()
Ending main()

*/


#include <iostream> // for std::cout

void doPrint()
{
    std::cout << "In doPrint()\n";
}

// Definition of function main()
int main()
{
    std::cout << "Starting main()\n";
  
    doPrint(); // doPrint() called for the first time
    doPrint(); // doPrint() called for the second time
  
    std::cout << "Ending main()\n";

    return 0;
}

/*
Starting main()
In doPrint()
In doPrint()
Ending main()
*/


#include <iostream> // for std::cout

// Definition of user-defined function doPrint()
void doPrint() // doPrint() is the called function in this example
{
    std::cout << "In doPrint()\n";
}

// Definition of function main()
int main()
{
    std::cout << "Starting main()\n";
  
    doPrint(); // Interrupt main() by making a function call to doPrint().  main() is the caller.
  
    std::cout << "Ending main()\n"; // this statement is executed after doPrint() ends

    return 0;
}

/*
Starting main()
In doPrint()
Ending main()
*/



#include <iostream>

int main()
{
	// get a value from the user
	std::cout << "Enter an integer: ";
	int num{};
	std::cin >> num;

	// print the value doubled
	std::cout << num << " doubled is: " << num * 2 << '\n';

	return 0;
}


// This program doesn't work
#include <iostream>

void getValueFromUser()
{
 	std::cout << "Enter an integer: ";
	int input{};
	std::cin >> input;

}

int main()
{
	getValueFromUser(); // Ask user for input

	int num{}; // How do we get the value from getValueFromUser() and use it to initialize this variable?

	std::cout << num << " doubled is: " << num * 2 << '\n';

	return 0;
}

// DOES NOT WORK 



#include <iostream>

// int is the return type
// A return type of int means the function will return some integer value to the caller (the specific value is not specified here)
int returnFive()
{
    // the return statement indicates the specific value that will be returned
    return 5; // return the specific value 5 back to the caller
}

int main()
{
    std::cout << returnFive() << '\n'; // prints 5
    std::cout << returnFive() + 2 << '\n'; // prints 7

    returnFive(); // okay: the value 5 is returned, but is ignored since main() doesn't do anything with it

    return 0;
}



#include <iostream>

int getValueFromUser() // this function now returns an integer value
{
 	std::cout << "Enter an integer: ";
	int input{};
	std::cin >> input;

	return input; // return the value the user entered back to the caller
}

int main()
{
	int num { getValueFromUser() }; // initialize num with the return value of getValueFromUser()

	std::cout << num << " doubled is: " << num * 2 << '\n';

	return 0;
}



// REDUNDANT, need to apply DRY Don't Repeat Yourself 

#include <iostream>

int main()
{
	int x{};
	std::cout << "Enter an integer: ";
	std::cin >> x;

	int y{};
	std::cout << "Enter an integer: ";
	std::cin >> y;

	std::cout << x << " + " << y << " = " << x + y << '\n';

	return 0;
}

// BETTER - create function do do job, and call it twice

#include <iostream>

int getValueFromUser()
{
 	std::cout << "Enter an integer: ";
	int input{};
	std::cin >> input;

	return input;
}

int main()
{
    int x{ getValueFromUser() }; // first call to getValueFromUser
    int y{ getValueFromUser() }; // second call to getValueFromUser

    std::cout << x << " + " << y << " = " << x + y << '\n';

    return 0;
}



#include <iostream>

int return7()
{
    return 7;
}

int return9()
{
    return 9;
}

int main()
{
    std::cout << return7() + return9() << '\n'; // 16

    return 0;
}



/* 

program compiles but does not produce any output. 
The return values from the functions are not used for anything 
(and are thus discarded).

#include <iostream>

int return7()
{
    return 7;
}

int return9()
{
    return 9;
}

int main()
{
    return7();
    return9();

    return 0;
}


*/ 



#include <iostream>

// void means the function does not return a value to the caller
void printHi()
{
    std::cout << "Hi" << '\n';

    // This function does not return a value so no return statement is needed
}

int main()
{
    printHi(); // okay: function printHi() is called, no value is returned

    return 0;
}




#include <iostream>

void print() // note: void return type
{
    std::cout << "A";

    return; // the function will return to the caller here (note: no return value)

    std::cout << "B"; // this will never be printed
}

int main()
{
    print();

    return 0;
}

// A


#include <iostream>

int print() // note: return type of int
{
    std::cout << "A";

    return 5; // the function will return to the caller here

    std::cout << "B"; // this will never be printed
}

int main()
{
    std::cout << print(); // print() returns value 5, which will be print to the console

    return 0;
}


// A5'




#include <iostream>

void printA()
{
    std::cout << "A\n";
}

void printB()
{
    std::cout << "B\n";
}

int main()
{
    printA();
    printB();

    return 0;
}

// A
// B





#include <iostream>

int getValueFromUser()
{
 	std::cout << "Enter an integer: ";
	int input{};
	std::cin >> input;

	return input;
}

int main()
{
	int num { getValueFromUser() };

	std::cout << num << " doubled is: " << num * 2 << '\n';

	return 0;
}


// Output line into its own function
#include <iostream>

int getValueFromUser()
{
 	std::cout << "Enter an integer: ";
	int input{};
	std::cin >> input;

	return input;
}

void printDouble(int value)       // This function now has an integer parameter
{
	std::cout << value << " doubled is: " << value * 2 << '\n';
}

int main()
{
	int num { getValueFromUser() }; // We set up an integer parameter

	printDouble(num);               // Called upon our void function, and applied integer parameter 

	return 0;
}

// More concise - putting the return function as parameter within the void function as an argument
#include <iostream>

int getValueFromUser()
{
 	std::cout << "Enter an integer: ";
	int input{};
	std::cin >> input;

	return input;                              // this is the 'int value' parameter, can put into void function
}

void printDouble(int value)
{
	std::cout << value << " doubled is: " << value * 2 << '\n';
}

int main()
{
	printDouble(getValueFromUser());

	return 0;
}



#include <iostream>

int getValueFromUser()
{
 	std::cout << "Enter an integer: ";
	int input{};
	std::cin >> input;

	return input;
}

void printDouble(int value) // This function now has an integer parameter
{
	std::cout << value << " doubled is: " << value * 2 << '\n';
}

int main()
{
	int num { getValueFromUser() };

	printDouble(num);

	return 0;
}



#include <iostream>

int getValueFromUser()
{
 	std::cout << "Enter an integer: ";
	int input{};
	std::cin >> input;

	return input;
}

void printDouble(int value) // This function now has an integer parameter
{
	std::cout << value << " doubled is: " << value * 2 << '\n';
}

int main()
{
	int num { getValueFromUser() };

	printDouble(num);

	return 0;
}


//------------------------------------------------------------------------------



#include <iostream>

// This function has two integer parameters, one named x, and one named y
// The values of x and y are passed in by the caller
void printValues(int x, int y)
{
    std::cout << x << '\n';
    std::cout << y << '\n';
}

int main()
{
    printValues(6, 7); // This function call has two arguments, 6 and 7

    return 0;
}

// 6
// 7


//------------------------------------------------------------------------------



#include <iostream>

// add() takes two integers as parameters, and returns the result of their sum
// The values of x and y are determined by the function that calls add()
int add(int x, int y)
{
    return x + y;
}

// main takes no parameters
int main()
{
    std::cout << add(4, 5) << '\n'; // Arguments 4 and 5 are passed to function add()
    return 0;
}

// 9 


//------------------------------------------------------------------------------


#include <iostream>

int add(int x, int y)
{
    return x + y;
}

int multiply(int z, int w)
{
    return z * w;
}

int main()
{
    std::cout << add(4, 5) << '\n'; // within add() x=4, y=5, so x+y=9
    std::cout << add(1 + 2, 3 * 4) << '\n'; // within add() x=3, y=12, so x+y=15

    int a{ 5 };
    std::cout << add(a, a) << '\n'; // evaluates (5 + 5)

    std::cout << add(1, multiply(2, 3)) << '\n'; // evaluates 1 + (2 * 3)
    std::cout << add(1, add(2, 3)) << '\n'; // evaluates 1 + (2 + 3)

    return 0;
}


/*
9
15
10
7
6
  */


//------------------------------------------------------------------------------

#include <iostream>

int add(int x, int y, int z)
{
    return x + y + z;
}

int multiply(int x, int y)
{
    return x * y;
}

int main()
{
    std::cout << multiply(add(1, 2, 3), 4) << '\n';     // 24
    return 0;
}

//------------------------------------------------------------------------------


#include <iostream>

int add(int x, int y, int z)
{
    return x + y + z;
}

int multiply(int x, int y)
{
    return x * y;
}

int main()
{
    std::cout << multiply(add(1, 2, 3), 4) << '\n';     // 24
    return 0;
}


//------------------------------------------------------------------------------


#include <iostream>

int add(int x, int y) // x and y are created and enter scope here
{
    // x and y are visible/usable within this function only
    return x + y;
} // y and x go out of scope and are destroyed here

int main()
{
    int a{ 5 }; // a is created, initialized, and enters scope here
    int b{ 6 }; // b is created, initialized, and enters scope here

    // a and b are usable within this function only
    std::cout << add(a, b) << '\n'; // calls function add() with x=5 and y=6, // 11

    return 0;
} // b and a go out of scope and are destroyed here


/*

Execution starts at the top of main.
main variable a is created and given value 5.
main variable b is created and given value 6.
Function add is called with argument values 5 and 6.
add parameters x and y are created and initialized with values 5 and 6 respectively.
The expression x + y is evaluated to produce the value 11.
add copies the value 11 back to caller main.
add parameters y and x are destroyed.
main prints 11 to the console.
main returns 0 to the operating system.
main variables b and a are destroyed.

*/


//------------------------------------------------------------------------------

#include <iostream>

void doIt(int x)
{
    int y{ 4 };
    std::cout << "doIt: x = " << x << " y = " << y << '\n';

    x = 3;
    std::cout << "doIt: x = " << x << " y = " << y << '\n';
}

int main()
{
    int x{ 1 };
    int y{ 2 };

    std::cout << "main: x = " << x << " y = " << y << '\n';

    doIt(x);

    std::cout << "main: x = " << x << " y = " << y << '\n';

    return 0;
}

/*
main: x = 1 y = 2
doIt: x = 1 y = 4
doIt: x = 3 y = 4
main: x = 1 y = 2
Here’s what happens in this program:

execution starts at the top of main
main‘s variable x is created and initialized with value 1
main‘s variable y is created and initialized with value 2
std::cout prints main: x = 1 y = 2
doIt is called with argument 1
doIt‘s parameter x is created and initialized with value 1
doIt’s variable y is created and initialized with value 4
doIt prints doIt: x = 1 y = 4
doIt‘s variable x is assigned the new value 3
std::cout prints doIt: x = 3 y = 4
doIt‘s y and x are destroyed
std::cout prints main: x = 1 y = 2
main returns 0 to the operating system
main‘s y and x are destroyed
Note that even though doIt‘s variables x and y had their values initialized or assigned to something different than main‘s, main‘s x and y were unaffected because they are different variables.


*/


//------------------------------------------------------------------------------



#include <iostream>

void doIt(int x)
{
    int y{ 4 };
    std::cout << "doIt: x = " << x << " y = " << y << '\n';

    x = 3;
    std::cout << "doIt: x = " << x << " y = " << y << '\n';
}

int main()
{
    int x{ 1 };
    int y{ 2 };

    std::cout << "main: x = " << x << " y = " << y << '\n';

    doIt(x);

    std::cout << "main: x = " << x << " y = " << y << '\n';

    return 0;
}

/*
main: x = 1 y = 2
doIt: x = 1 y = 4
doIt: x = 3 y = 4
main: x = 1 y = 2
Here’s what happens in this program:

execution starts at the top of main
main‘s variable x is created and initialized with value 1
main‘s variable y is created and initialized with value 2
std::cout prints main: x = 1 y = 2
doIt is called with argument 1
doIt‘s parameter x is created and initialized with value 1
doIt’s variable y is created and initialized with value 4
doIt prints doIt: x = 1 y = 4
doIt‘s variable x is assigned the new value 3
std::cout prints doIt: x = 3 y = 4
doIt‘s y and x are destroyed
std::cout prints main: x = 1 y = 2
main returns 0 to the operating system
main‘s y and x are destroyed
Note that even though doIt‘s variables x and y had their values initialized or assigned to something different than main‘s, main‘s x and y were unaffected because they are different variables.


*/


//------------------------------------------------------------------------------


#include <iostream>
int add(int x, int y, int z);

int main()
{
    std::cout << "3 + 4 + 5 = " << add(3, 4, 5) << '\n'; // 12
    return 0;
}

int add(int x, int y, int z)
{
    return x + y + z;
}


//------------------------------------------------------------------------------


#include <iostream>

int getInteger()
{
	std::cout << "Enter an integer: ";
	int x{};
	std::cin >> x;
  
	return x;
}

int main()
{
	int x{ getInteger() };
	int y{ getInteger() };

	std::cout << x << " + " << y << " is " << x + y << '\n';
	return 0;
}


//------------------------------------------------------------------------------


#include <iostream> // imports the declaration of std::cout

using namespace std; // makes std::cout accessible as "cout"

int cout() // defines our own "cout" function in the global namespace
{
    return 5;
}

int main()
{
    cout << "Hello, world!"; // Compile error!  Which cout do we want here?  The one in the std namespace or the one we defined above?

    return 0;
}


//------------------------------------------------------------------------------

/*
A function named “readNumber” should be used to get (and return) a single integer from the user.
A function named “writeAnswer” should be used to output the answer. This function should take a single parameter and have no return value.
A main() function should be used to glue the above functions together.

*/

#include <iostream>

int readNumber()
{
    std::cout << "Enter a number: ";
    int x {};
    std::cin >> x;
  
    return x;
}


void writeAnswer(int x)
{
    std::cout << "The answer is " << x << '\n';
}



int main()
{
    int x { readNumber() };
    int y { readNumber() };
  
    writeAnswer(x + y); // using operator+ to pass the sum of x and y to writeAnswer()
  
    return 0;
}

//------------------------------------------------------------------------------

/*
Modify the program you wrote in exercise #1 so that readNumber() and
writeAnswer() live in a separate file called “io.cpp”. Use a forward declaration
to access them from main().
*/

// io.cpp:

#include <iostream>

int readNumber() {
  std::cout << "Enter a number: ";
  int x{};
  std::cin >> x;

  return x;
}

void writeAnswer(int x) { std::cout << "The answer is " << x << '\n'; }

// main.cpp:

// these are the forward declarations for the functions in io.cpp

int readNumber();        // prototype - returns a value
void writeAnswer(int x); //  print statement, set up a parameter

int main() {
  int x{readNumber()};
  int y{readNumber()};

  writeAnswer(x + y); // calls our void function, apply our arguments

  return 0;
}

//------------------------------------------------------------------------------


/*
  uses a header file (named io.h) to access the functions instead of using forward declarations directly in your code (.cpp) files. Make sure your header file uses header guards.
  */

// io.h:

#ifndef IO_H
#define IO_H

int readNumber();
void writeAnswer(int x);

#endif


// io.cpp:
#include "io.h"
#include <iostream>

int readNumber()
{
    std::cout << "Enter a number: ";
    int x {};
    std::cin >> x;
  
    return x;
}

void writeAnswer(int x)
{
    std::cout << "The answer is " << x << '\n';
}


//main.cpp:
#include "io.h"

int main()
{
    int x { readNumber() };
    int y { readNumber() };
  
    writeAnswer(x+y);
  
    return 0;
}


//------------------------------------------------------------------------------

