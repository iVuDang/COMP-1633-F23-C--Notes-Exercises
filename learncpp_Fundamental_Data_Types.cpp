#include <iostream>

int main()
{
    std::cout << true << '\n'; // true evaluates to 1
    std::cout << !true << '\n'; // !true evaluates to 0

    bool b{false};
  
    std::cout << b << '\n'; // b is false, which evaluates to 0
    std::cout << !b << '\n'; // !b is true, which evaluates to 1
  
    return 0;
}


/*
1
0
0
1

*/

//------------------------------------------------------------------------------

#include <iostream>

int main()
{
    std::cout << true << '\n';
    std::cout << false << '\n';

    std::cout << std::boolalpha; // print bools as true or false

    std::cout << true << '\n';
    std::cout << false << '\n';
  
    return 0;
}

/*
1
0
true
false

*/
//------------------------------------------------------------------------------

#include <iostream>

int main()
{
	std::cout << std::boolalpha; // print bools as true or false

	bool b1 = 4 ; // copy initialization allows implicit conversion from int to bool
	std::cout << b1 << '\n';

	bool b2 = 0 ; // copy initialization allows implicit conversion from int to bool
	std::cout << b2 << '\n';


	return 0;
}


/*
true 

false 

*/

//------------------------------------------------------------------------------


#include <iostream>

int main()
{
	bool b{}; // default initialize to false
	std::cout << "Enter a boolean value: ";
	std::cin >> b;
	std::cout << "You entered: " << b << '\n';

	return 0;
}

/*

Enter a boolean value: 20
You entered: 1


*/

//------------------------------------------------------------------------------


#include <iostream>

int main()
{
	bool b{};
	std::cout << "Enter a true or false: ";

	// Allow the user to enter 'true' or 'false' for boolean values
	// This is case-sensitive, so True or TRUE will not work
	std::cin >> std::boolalpha;
	std::cin >> b;

	std::cout << "You entered: " << b << '\n';

	return 0;
}

/*

Enter a boolean value: true
You entered: 1

*/

//------------------------------------------------------------------------------


#include <iostream>

// returns true if x and y are equal, false otherwise
bool isEqual(int x, int y)
{
    return (x == y); // operator== returns true if x equals y, and false otherwise
}

int main()
{
    std::cout << "Enter an integer: ";
    int x{};
    std::cin >> x;

    std::cout << "Enter another integer: ";
    int y{};
    std::cin >> y;

    std::cout << std::boolalpha; // print bools as true or false

    std::cout << x << " and " << y << " are equal? ";
    std::cout << isEqual(x, y); // will return true or false

    return 0;
}


/*
Enter an integer: 5
Enter another integer: 5
5 and 5 are equal? true 


Enter an integer: 6
Enter another integer: 4
6 and 4 are equal? false 
*/

//------------------------------------------------------------------------------


#include <iostream>

int main()
{
    std::cout << "Enter an integer: ";
    int x {};
    std::cin >> x;

    if (x > 0)
        std::cout << "The value is positive\n";
    else if (x < 0)
        std::cout << "The value is negative\n";
    else
        std::cout << "The value is zero\n";

    return 0;
}

/*

Enter an integer: 4
The value is positive

Enter an integer: -3
The value is negative

Enter an integer: 0
The value is zero

*/

//------------------------------------------------------------------------------



#include <iostream>

// returns true if x and y are equal, false otherwise
bool isEqual(int x, int y)
{
    return (x == y); // operator== returns true if x equals y, and false otherwise
}

int main()
{
    std::cout << "Enter an integer: ";
    int x {};
    std::cin >> x;

    std::cout << "Enter another integer: ";
    int y {};
    std::cin >> y;

    std::cout << std::boolalpha; // print bools as true or false

    std::cout << x << " and " << y << " are equal? ";
    std::cout << isEqual(x, y); // will return true or false

    return 0;
}
Let’s improve this program using an if statement:

#include <iostream>

// returns true if x and y are equal, false otherwise
bool isEqual(int x, int y)
{
    return (x == y); // operator== returns true if x equals y, and false otherwise
}

int main()
{
    std::cout << "Enter an integer: ";
    int x {};
    std::cin >> x;

    std::cout << "Enter another integer: ";
    int y {};
    std::cin >> y;

    if (isEqual(x, y))                         // this function returns a boolean
        std::cout << x << " and " << y << " are equal\n";
    else
        std::cout << x << " and " << y << " are not equal\n";

    return 0;
}

//------------------------------------------------------------------------------


#include <iostream>

bool isPrime(int x)
{
    if (x == 2) // if user entered 2, the digit is prime
        return true;
    else if (x == 3) // if user entered 3, the digit is prime
        return true;
    else if (x == 5) // if user entered 5, the digit is prime
        return true;
    else if (x == 7) // if user entered 7, the digit is prime
        return true;

    return false; // if the user did not enter 2, 3, 5, 7, the digit must not be prime
}

int main()
{
    std::cout << "Enter a number 0 through 9: ";
    int x {};
    std::cin >> x;

    if ( isPrime(x) )
        std::cout << "The digit is prime\n";
    else
        std::cout << "The digit is not prime\n";

    return 0;
}

/*

Enter a number 0 through 9: 5
The digit is prime

*/


// MORE EFFICIENT METHODS

// A. Using the logical OR (||) operator (5.7 -- Logical operators):

bool isPrime(int x)
{
    return (x == 2 || x == 3 || x == 5 || x == 7); // if user entered 2 or 3 or 5 or 7 the digit is prime
}

int main()
{
    std::cout << "Enter a number 0 through 9: ";
    int x {};
    std::cin >> x;

    if ( isPrime(x) )
        std::cout << "The digit is prime\n";
    else
        std::cout << "The digit is not prime\n";

    return 0;
}


// B. Using a switch statement (7.4 -- Switch statement basics):

bool isPrime(int x)
{
    switch (x)
    {
        case 2: // if the user entered 2
        case 3: // or if the user entered 3
        case 5: // or if the user entered 5
        case 7: // or if the user entered 7
            return true; // then the digit is prime
    }

    return false; // otherwise the digit must not be prime
}


int main()
{
    std::cout << "Enter a number 0 through 9: ";
    int x {};
    std::cin >> x;

    if ( isPrime(x) )
        std::cout << "The digit is prime\n";
    else
        std::cout << "The digit is not prime\n";

    return 0;
}

// C. Ternary Operator
// variable = (condition) ? expressionTrue : expressionFalse;  

//------------------------------------------------------------------------------


// We don’t need the if-statement in isAllowedToTakeFunRide(). The expression height > 140.0 evaluates to a bool, which can be directly returned.

bool isAllowedToTakeFunRide()
{
  std::cout << "How tall are you? (cm)\n";

  double height{};
  std::cin >> height;

  return (height > 140.0);
}


// You never need an if-statement of the form:

if (condition)
  return true;
else
  return false;


// This can be replaced by the single statement return condition.


//------------------------------------------------------------------------------


// A character can be a single letter, number, symbol, or whitespace.

#include <iostream>

int main()
{
    std::cout << "Input a keyboard character: ";

    char ch{};
    std::cin >> ch;
    std::cout << "You entered: " << ch << '\n';

    return 0;
}


/*

Input a keyboard character: r
You entered: r

*/

//------------------------------------------------------------------------------


#include <iostream>

int main()
{
    std::cout << "Input a keyboard character: "; // assume the user enters "abcd" (without quotes)

    char ch{};
    std::cin >> ch; // ch = 'a', "bcd" is left queued.
    std::cout << "You entered: " << ch << '\n';

    // Note: The following cin doesn't ask the user for input, it grabs queued input!
    std::cin >> ch; // ch = 'b', "cd" is left queued.
    std::cout << "You entered: " << ch << '\n';

    return 0;
}


/*
Input a keyboard character: abcd
You entered: a
You entered: b

*/

//------------------------------------------------------------------------------


// Escape sequences

// There are some characters in C++ that have special meaning. These characters are called escape sequences. An escape sequence starts with a ‘\’ (backslash) character, and then a following letter or number.

// You’ve already seen the most common escape sequence: '\n', which can be used to embed a newline in a string of text:

#include <iostream>

int main()
{
    std::cout << "First line\nSecond line\n";
    return 0;
}

// This outputs:

// First line
// Second line
// Another commonly used escape sequence is '\t', which embeds a horizontal tab:

#include <iostream>

int main()
{
    std::cout << "First part\tSecond part";
    return 0;
}
// Which outputs:

// First part        Second part
// Three other notable escape sequences are:
// \’ prints a single quote
// \” prints a double quote
// \\ prints a backslash

//------------------------------------------------------------------------------

#include <iostream>

int main()
{
    std::cout << "\"This is quoted text\"\n";
    std::cout << "This string contains a single backslash \\\n";
    std::cout << "6F in hex is char '\x6F'\n";
    return 0;
}


// Prints:

// "This is quoted text"
// This string contains a single backslash \
// 6F in hex is char 'o'

//------------------------------------------------------------------------------


#include <iostream>

int main()
{
    char ch{ 97 }; // 97 is ASCII code for 'a'
    std::cout << ch << " has value " << static_cast<int>(ch) << '\n'; // print value of variable ch as an int

    return 0;
}

// a has value 97

//------------------------------------------------------------------------------


#include <iostream>
#include <string>

int main()
{
    std::string name { "Alex" };
    std::cout << "My name is: " << name << '\n';

    return 0;
}

// My name is: Alex

//------------------------------------------------------------------------------


#include <string> // For std::string and std::getline
#include <iostream>

int main()
{
    std::cout << "Enter your full name: ";
    std::string name{};
    std::getline(std::cin >> std::ws, name); // read a full line of text into name

    std::cout << "Enter your age: ";
    std::string age{};
    std::getline(std::cin >> std::ws, age); // read a full line of text into age

    std::cout << "Your name is " << name << " and your age is " << age << '\n';

    return 0;
}


// Now our program works as expected:

// Enter your full name: John Doe
// Enter your age: 23
// Your name is John Doe and your age is 23

// The std::ws input manipulator tells std::cin to ignore any leading whitespace before extraction. Leading whitespace is any whitespace character (spaces, tabs, newlines) that occur at the start of the string.

//------------------------------------------------------------------------------


#include <iostream>
#include <string>

int main()
{
    std::string name{ "Alex" };
    std::cout << name << " has " << name.length() << " characters\n";

    return 0;
}


// Alex has 4 characters

//------------------------------------------------------------------------------


// Write a program that asks the user to enter their full name and their age. As output, tell the user the sum of their age and the number of letters in their name (use the std::string::length() member function to get the length of the string). For simplicity, count any spaces in the name as a letter.

// Sample output:

// Enter your full name: John Doe
// Enter your age: 32
// Your age + length of name is: 40
// Reminder: std::string::length() returns an unsigned int. You should static_cast this to an int before adding the age so you don’t mix signed and unsigned values.



#include <iostream>
#include <string>

int main()
{
    std::cout << "Enter your full name: ";
    std::string name{};
    std::getline(std::cin >> std::ws, name); // read a full line of text into name

    std::cout << "Enter your age: ";
    int age{}; // age needs to be an integer, not a string, so we can do math with it
    std::cin >> age;

    // age is signed, and name.length() is unsigned -- we shouldn't mix these
    // We'll convert name.length() to a signed value
    int letters{ static_cast<int>(name.length()) }; // get number of letters in name (including spaces)
    std::cout << "Your age + length of name is: " << age + letters << '\n';

    return 0;
}


//------------------------------------------------------------------------------


// Write the following program: The user is asked to enter 2 floating point numbers (use doubles). The user is then asked to enter one of the following mathematical symbols: +, -, *, or /. The program computes the answer on the two numbers the user entered and prints the results. If the user enters an invalid symbol, the program should print nothing.

// Example of program:

// Enter a double value: 6.2
// Enter a double value: 5
// Enter one of the following: +, -, *, or /: *
// 6.2 * 5 is 31


#include <iostream>

double getDouble()
{
    std::cout << "Enter a double value: ";
    double x{};
    std::cin >> x;
  
    return x;
}


char getOperator()
{
    std::cout << "Enter one of the following: +, -, *, or / ";
    char operation{};
    std::cin >> operation;
  
    return operation;
}


void printResult(double x, char operation, double y)
{
    if (operation == '+')
        std::cout << x << " + " << y << " is " << x + y << '\n';
      
    else if (operation == '-')
        std::cout << x << " - " << y << " is " << x - y << '\n';
      
    else if (operation == '*')
        std::cout << x << " * " << y << " is " << x * y << '\n';
      
    else if (operation == '/')
        std::cout << x << " / " << y << " is " << x / y << '\n';
}


int main()
{
    double x { getDouble() };                // return function
    double y { getDouble() };                // return function

    char operation { getOperator() };        // return function

    printResult(x, operation, y);            // void function, apply arguments  

    return 0;
}


//------------------------------------------------------------------------------


// Write a short program to simulate a ball being dropped off of a tower. To start, the user should be asked for the height of the tower in meters. Assume normal gravity (9.8 m/s2), and that the ball has no initial velocity (the ball is not moving to start). Have the program output the height of the ball above the ground after 0, 1, 2, 3, 4, and 5 seconds. The ball should not go underneath the ground (height 0).

// Use a function to calculate the height of the ball after x seconds. The function can calculate how far the ball has fallen after x seconds using the following formula: distance fallen = gravity_constant * x_seconds2 / 2

// Desired output:

// Enter the height of the tower in meters: 100
// At 0 seconds, the ball is at height: 100 meters
// At 1 seconds, the ball is at height: 95.1 meters
// At 2 seconds, the ball is at height: 80.4 meters
// At 3 seconds, the ball is at height: 55.9 meters
// At 4 seconds, the ball is at height: 21.6 meters
// At 5 seconds, the ball is on the ground.


#include <iostream>

// gets height from user and returns it
double getTowerHeight()
{
	std::cout << "Enter the height of the tower in meters: ";
	double towerHeight{};
	std::cin >> towerHeight;
  
	return towerHeight;
}

// Returns height from ground after "seconds" seconds
double calculateHeight(double towerHeight, int seconds)
{
	constexpr double gravity{ 9.8 };

	// Using formula: [ s = u * t + (a * t^2) / 2 ], here u(initial velocity) = 0
	const double distanceFallen{ (gravity * (seconds * seconds)) / 2.0 };
	const double currentHeight{ towerHeight - distanceFallen };

	return currentHeight;
}


// Prints height every second till ball has reached the ground
void printHeight(double height, int seconds)
{
	if (height > 0.0)
		std::cout << "At " << seconds << " seconds, the ball is at height: " << height << " meters\n";
	else
		std::cout << "At " << seconds << " seconds, the ball is on the ground.\n";
}


void calculateAndPrintHeight(double towerHeight, int seconds)
{
	const double height{ calculateHeight(towerHeight, seconds) };
  
	printHeight(height, seconds);
}



int main()
{
	const double towerHeight{ getTowerHeight() };

	calculateAndPrintHeight(towerHeight, 0);
	calculateAndPrintHeight(towerHeight, 1);
	calculateAndPrintHeight(towerHeight, 2);
	calculateAndPrintHeight(towerHeight, 3);
	calculateAndPrintHeight(towerHeight, 4);
	calculateAndPrintHeight(towerHeight, 5);

	return 0;
}


//------------------------------------------------------------------------------











