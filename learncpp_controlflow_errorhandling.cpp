#include <iostream>

void printDigitName(int x) {
  switch (x) {
  case 1:
    std::cout << "One";
    return;
  case 2:
    std::cout << "Two";
    return;
  case 3:
    std::cout << "Three";
    return;
  default:
    std::cout << "Unknown";
    return;
  }
}

int main() {
  printDigitName(2);
  std::cout << '\n';

  return 0;
}

// Two
// Prefer switch statements over if-else chains when there is a choice.
// Each set of statements underneath a label should end in a break statement or
// a return statement. This includes the statements underneath the last label in
// the switch.

// thus, without a break or return, execution will overflow into subsequent
// cases.
#include <iostream>

int main() {
  switch (2) {
  case 1:                   // Does not match
    std::cout << 1 << '\n'; // Skipped
  case 2:                   // Match!
    std::cout << 2 << '\n'; // Execution begins here
  case 3:
    std::cout << 3 << '\n'; // This is also executed
  case 4:
    std::cout << 4 << '\n'; // This is also executed
  default:
    std::cout << 5 << '\n'; // This is also executed
  }

  return 0;
}

// This program outputs the following:

// 2
// 3
// 4
// 5

//------------------------------------------------------------------------------

// Write a function called calculate() that takes two integers and a char representing one of the following mathematical operations: +, -, *, /, or % (modulus). Use a switch statement to perform the appropriate mathematical operation on the integers, and return the result. If an invalid operator is passed into the function, the function should print an error. For the division operator, do an integer division.

// Hint: “operator” is a keyword, variables can’t be named “operator”.


#include <iostream>

int calculate(int x, int y, char op)
{
    switch (op)
    {
        case '+':
            return x + y;
        case '-':
            return x - y;
        case '*':
            return x * y;
        case '/':
            return x / y;
        case '%':
            return x % y;
        default:
            std::cerr << "calculate(): Unhandled case\n";
            return 0;
    }
}

int main()
{
    std::cout << "Enter an integer: ";
    int x{};
    std::cin >> x;

    std::cout << "Enter another integer: ";
    int y{};
    std::cin >> y;

    std::cout << "Enter a mathematical operator (+, -, *, /, or %): ";
    char op{};
    std::cin >> op;

    std::cout << x << ' ' << op << ' ' << y << " is " << calculate(x, y, op) << '\n';

    return 0;
}

//------------------------------------------------------------------------------

#include <iostream>

int main()
{
    int count{ 1 };
    while (count <= 10)
    {
        std::cout << count << ' ';
        ++count;
    }

    std::cout << "done!\n";

    return 0;
}

// 1 2 3 4 5 6 7 8 9 10 done!

//------------------------------------------------------------------------------


#include <iostream>

// Iterate through every number between 1 and 50
int main()
{
    int count{ 1 };
    while (count <= 50)
    {
        // print the number (pad numbers under 10 with a leading 0 for formatting purposes)
        if (count < 10)
        {
            std::cout << '0';
        }

        std::cout << count << ' ';

        // if the loop variable is divisible by 10, print a newline
        if (count % 10 == 0)
        {
            std::cout << '\n';
        }

        // increment the loop counter
        ++count;
    }

    return 0;
}

// 01 02 03 04 05 06 07 08 09 10
// 11 12 13 14 15 16 17 18 19 20
// 21 22 23 24 25 26 27 28 29 30
// 31 32 33 34 35 36 37 38 39 40
// 41 42 43 44 45 46 47 48 49 50

//------------------------------------------------------------------------------


#include <iostream>

int main()
{
    // outer loops between 1 and 5
    int outer{ 1 };
    while (outer <= 5)
    {
        // For each iteration of the outer loop, the code in the body of the loop executes once

        // inner loops between 1 and outer
        int inner{ 1 };
        while (inner <= outer)
        {
            std::cout << inner << ' ';
            ++inner;
        }

        // print a newline at the end of each row
        std::cout << '\n';
        ++outer;
    }

    return 0;
}

// 1 
// 1 2 
// 1 2 3 
// 1 2 3 4 
// 1 2 3 4 5 


// First, we have an outer loop (with loop variable outer) that will loop 5 times (with outer having values 1, 2, 3, 4, and 5 successively).

// On the first iteration of the outer loop, outer has value 1, and then the outer loop body executes. Inside the body of the outer loop, we have another loop with loop variable inner. The inner loop iterates from 1 to outer (which has value 1), so this inner loop will execute once, printing the value 1. Then we print a newline, and increment outer to 2.

// On the second iteration of the outer loop, outer has value 2, and then the outer loop body executes. Inside the body of the outer loop, inner iterates from 1 to outer (which now has value 2), so this inner loop will execute twice, printing the values 1 and 2. Then we print a newline, and increment outer to 3.

// This process continues, with the inner loop printing 1 2 3, 1 2 3 4, and 1 2 3 4 5 on successive passes. Eventually, outer is incremented to 6, and because the outer loop condition (outer <= 5) is then false, the outer loop is finished. Then the program ends.

  
//------------------------------------------------------------------------------

#include <iostream>

int main()
{
    char myChar{ 'a' };
    while (myChar <= 'z')
    {
        std::cout << myChar << ' ' << static_cast<int>(myChar) << '\n';
        ++myChar;
    }

    return 0;
}


// a 97
// b 98
// c 99
// d 100
// e 101
// f 102
// g 103
// h 104
// i 105
// j 106
// k 107
// l 108
// m 109
// n 110
// o 111
// p 112
// q 113
// r 114
// s 115
// t 116
// u 117
// v 118
// w 119
// x 120
// y 121
// z 122

//------------------------------------------------------------------------------


#include <iostream>

// Loop between 5 and 1
int main()
{
	int outer{ 5 };
	while (outer >= 1)
	{
		// loop between outer and 1
		int inner{ outer };
		while (inner >= 1)
        {
			std::cout << inner-- << ' ';
        }

		// print a newline at the end of each row
		std::cout << '\n';
		--outer;
	}

	return 0;
}


// 5 4 3 2 1 
// 4 3 2 1 
// 3 2 1 
// 2 1 
// 1 
  
//------------------------------------------------------------------------------


// Thanks to Shiva for this solution
#include <iostream>

int main()
{
	// There are 5 rows, we can loop from 1 to 5
	int outer{ 1 };

	while (outer <= 5)
	{
		// Row elements appear in descending order, so start from 5 and loop through to 1
		int inner{ 5 };

		while (inner >= 1)
		{
			// The first number in any row is the same as the row number
			// So number should be printed only if it is <= the row number, space otherwise
			if (inner <= outer)
				std::cout << inner << ' '; // print the number and a single space
			else
				std::cout << "  "; // don't print a number, but print two spaces

			--inner;
		}

		// A row has been printed, move to the next row
		std::cout << '\n';

		++outer;
	}

	return 0;
}

//         1 
//       2 1 
//     3 2 1 
//   4 3 2 1 
// 5 4 3 2 1

//------------------------------------------------------------------------------


// for (init-statement; condition; end-expression)
//    statement;


#include <iostream>

int main()
{
    for (int count{ 1 }; count <= 10; ++count)
        std::cout << count << ' ';

    std::cout << '\n';

    return 0;
}


// 1 2 3 4 5 6 7 8 9 10 


/*

{ // note the block here
    init-statement; // used to define variables used in the loop
    while (condition)
    {
        statement; 
        end-expression; // used to modify the loop variable prior to reassessment of the condition
    }
} // variables defined inside the loop go out of scope here

*/

//------------------------------------------------------------------------------


#include <iostream>

int main()
{
    { // the block here ensures block scope for count
        int count{ 1 }; // our init-statement
        while (count <= 10) // our condition
        {
            std::cout << count << ' '; // our statement
            ++count; // our end-expression
        }
    }

    std::cout << '\n';
}

// 1 2 3 4 5 6 7 8 9 10 

//------------------------------------------------------------------------------




#include <iostream>

int main()
{
    for (int count{ 0 }; count <= 10; count += 2)
        std::cout << count << ' ';

    std::cout << '\n';

    return 0;
}


// 0 2 4 6 8 10

//------------------------------------------------------------------------------


#include <iostream>

int main()
{
	for (char c{ 'a' }; c <= 'e'; ++c) // outer loop on letters
	{
		std::cout << c; // print our letter first

		for (int i{ 0 }; i < 3; ++i) // inner loop on all numbers
			std::cout << i;

		std::cout << '\n';
	}

	return 0;
}


// a012
// b012
// c012
// d012
// e012

//------------------------------------------------------------------------------

#include <iostream>

int main()
{
    int sum{ 0 };

    // Allow the user to enter up to 10 numbers
    for (int count{ 0 }; count < 10; ++count)
    {
        std::cout << "Enter a number to add, or 0 to exit: ";
        int num{};
        std::cin >> num;

        // exit loop if user enters 0
        if (num == 0)
            break; // exit the loop now

        // otherwise add number to our sum
        sum += num;
    }

    // execution will continue here after the break
    std::cout << "The sum of all the numbers you entered is: " << sum << '\n';

    return 0;
}


// Enter a number to add, or 0 to exit: 5
// Enter a number to add, or 0 to exit: 2
// Enter a number to add, or 0 to exit: 1
// Enter a number to add, or 0 to exit: 0
// The sum of all the numbers you entered is: 8


//------------------------------------------------------------------------------


#include <iostream>

int main()
{
    while (true) // infinite loop
    {
        std::cout << "Enter 0 to exit or any other integer to continue: ";
        int num{};
        std::cin >> num;

        // exit loop if user enters 0
        if (num == 0)
            break;
    }

    std::cout << "We're out!\n";

    return 0;
}

// Enter 0 to exit or any other integer to continue: 5
// Enter 0 to exit or any other integer to continue: 3
// Enter 0 to exit or any other integer to continue: 0
// We're out!

//------------------------------------------------------------------------------

#include <iostream>

int breakOrReturn()
{
    while (true) // infinite loop
    {
        std::cout << "Enter 'b' to break or 'r' to return: ";
        char ch{};
        std::cin >> ch;

        if (ch == 'b')
            break; // execution will continue at the first statement beyond the loop

        if (ch == 'r')
            return 1; // return will cause the function to immediately return to the caller (in this case, main())
    }

    // breaking the loop causes execution to resume here

    std::cout << "We broke out of the loop\n";

    return 0;
}

int main()
{
    int returnValue{ breakOrReturn() };
    std::cout << "Function breakOrReturn returned " << returnValue << '\n';

    return 0;
}

// Enter 'b' to break or 'r' to return: r
// Function breakOrReturn returned 1
  
// Enter 'b' to break or 'r' to return: b
// We broke out of the loop
// Function breakOrReturn returned 0

//------------------------------------------------------------------------------

#include <iostream>

int main()
{
    for (int count{ 0 }; count < 10; ++count)
    {
        // if the number is divisible by 4, skip this iteration
        if ((count % 4) == 0)
            continue; // go to next iteration

        // If the number is not divisible by 4, keep going
        std::cout << count << '\n';

        // The continue statement jumps to here
    }

    return 0;
}

// 1
// 2
// 3
// 5
// 6
// 7
// 9

// use of a continue statement causes prescribed iterations to be skipped 
//------------------------------------------------------------------------------


// break and continue can help make loops more readable by keeping the number of nested blocks down and reducing the need for complicated looping logic.
#include <iostream>

int main()
{
    int count{ 0 }; // count how many times the loop iterates
    bool keepLooping { true }; // controls whether the loop ends or not
    while (keepLooping)
    {
        std::cout << "Enter 'e' to exit this loop or any other character to continue: ";
        char ch{};
        std::cin >> ch;

        if (ch == 'e')
            keepLooping = false;
        else
        {
            ++count;
            std::cout << "We've iterated " << count << " times\n";
        }
    }

    return 0;
}


// Here’s a version that’s easier to understand, using a break statement:

#include <iostream>

int main()
{
    int count{ 0 }; // count how many times the loop iterates
    while (true) // loop until user terminates
    {
        std::cout << "Enter 'e' to exit this loop or any other character to continue: ";
        char ch{};
        std::cin >> ch;

        if (ch == 'e')
            break;

        ++count;
        std::cout << "We've iterated " << count << " times\n";
    }

    return 0;
}


//------------------------------------------------------------------------------

#include <iostream>

void compare(int x, int y)
{
    if (x > y)
        std::cout << x << " is greater than " << y << '\n'; // case 1
    else if (x < y)
        std::cout << x << " is less than " << y << '\n'; // case 2
    else
        std::cout << x << " is equal to " << y << '\n'; // case 3
}

int main()
{
    std::cout << "Enter a number: ";
    int x{};
    std::cin >> x;

    std::cout << "Enter another number: ";
    int y{};
    std::cin >> y;

    compare(x, y);

    return 0;
}

//------------------------------------------------------------------------------

#include <iostream>

bool isLowerVowel(char c)
{
    switch (c)
    {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
        return true;
    default:
        return false;
    }
}

// returns the number of the test that failed, or 0 if all tests passed
int testVowel()
{
    if (!isLowerVowel('a')) return 1;
    if (isLowerVowel('q')) return 2;

    return 0;
}

int main()
{
    return 0;
}
//------------------------------------------------------------------------------

#include <iostream>
#include <limits>

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

double getDouble()
{
    while (true) // Loop until user enters a valid input
    {
        std::cout << "Enter a double value: ";
        double x{};
        std::cin >> x;

        // Check for failed extraction
        if (!std::cin) // has a previous extraction failed?
        {
            // yep, so let's handle the failure
            std::cin.clear(); // put us back in 'normal' operation mode
            ignoreLine(); // and remove the bad input
            std::cerr << "Oops, that input is invalid.  Please try again.\n";
        }
        else
        {
            ignoreLine(); // remove any extraneous input
            return x;
        }
    }
}

char getOperator()
{
    while (true) // Loop until user enters a valid input
    {
        std::cout << "Enter one of the following: +, -, *, or /: ";
        char operation{};
        std::cin >> operation;
        ignoreLine(); // // remove any extraneous input

        // Check whether the user entered meaningful input
        switch (operation)
        {
        case '+':
        case '-':
        case '*':
        case '/':
            return operation; // return it to the caller
        default: // otherwise tell the user what went wrong
            std::cerr << "Oops, that input is invalid.  Please try again.\n";
        }
    } // and try again
}

void printResult(double x, char operation, double y)
{
    switch (operation)
    {
    case '+':
        std::cout << x << " + " << y << " is " << x + y << '\n';
        break;
    case '-':
        std::cout << x << " - " << y << " is " << x - y << '\n';
        break;
    case '*':
        std::cout << x << " * " << y << " is " << x * y << '\n';
        break;
    case '/':
        std::cout << x << " / " << y << " is " << x / y << '\n';
        break;
    default: // Being robust means handling unexpected parameters as well, even though getOperator() guarantees operation is valid in this particular program
        std::cerr << "Something went wrong: printResult() got an invalid operator.\n";
    }
}

int main()
{
    double x{ getDouble() };
    char operation{ getOperator() };
    double y{ getDouble() };

    printResult(x, operation, y);

    return 0;
}



#include <iostream>
#include <random> // for std::mt19937

int main()
{
	std::mt19937 mt{}; // Instantiate a 32-bit Mersenne Twister

	// Print a bunch of random numbers
	for (int count{ 1 }; count <= 40; ++count)
	{
		std::cout << mt() << '\t'; // generate a random number

		// If we've printed 5 numbers, start a new row
		if (count % 5 == 0)
			std::cout << '\n';
	}

	return 0;
}


// 3499211612  581869302   3890346734  3586334585  545404204
// 4161255391  3922919429  949333985   2715962298  1323567403
// 418932835   2350294565  1196140740  809094426   2348838239
// 4264392720  4112460519  4279768804  4144164697  4156218106
// 676943009   3117454609  4168664243  4213834039  4111000746
// 471852626   2084672536  3427838553  3437178460  1275731771
// 609397212   20544909    1811450929  483031418   3933054126
// 2747762695  3402504553  3772830893  4120988587  2163214728


#include <iostream>
#include <random> // for std::mt19937 and std::uniform_int_distribution

int main()
{
	std::mt19937 mt{};

	// Create a reusable random number generator that generates uniform numbers between 1 and 6
	std::uniform_int_distribution die6{ 1, 6 }; // for C++14, use std::uniform_int_distribution<> die6{ 1, 6 };

	// Print a bunch of random numbers
	for (int count{ 1 }; count <= 40; ++count)
	{
		std::cout << die6(mt) << '\t'; // generate a roll of the die here

		// If we've printed 10 numbers, start a new row
		if (count % 10 == 0)
			std::cout << '\n';
	}

	return 0;
}

// 3       1       3       6       5       2       6       6       1       2
// 2       6       1       1       6       1       4       5       2       5
// 6       2       6       2       1       3       5       4       5       6
// 1       4       2       3       1       2       2       6       2       1






