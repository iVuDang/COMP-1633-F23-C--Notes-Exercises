#include <iostream>

int main()
{
    int x { 5 };

    std::cout << x; // 5 

    return 0;
}


#include <iostream>  // for std::cout and std::cin

int main()
{
    std::cout << "Enter a number: "; // ask user for a number

    int x{ }; // define variable x to hold user input (and zero-initialize it)
    std::cin >> x; // get number from keyboard and store it in variable x

    std::cout << "You entered " << x << '\n';
    return 0;
}



#include <iostream>  // for std::cout and std::cin
using namespace std; 

int main()
{
    cout << "Enter two numbers separated by a space: ";

    int x{ }; // define variable x to hold user input (and zero-initialize it)
    int y{ }; // define variable y to hold user input (and zero-initialize it)
  
    cin >> x >> y; // get two numbers and store in variable x and y respectively

    cout << "You entered " << x << " and " << y << '\n';

    return 0;
}


#include <iostream>

void doNothing(int&) // Don't worry about what & is for now, we're just using it to trick the compiler into thinking variable x is used
{
}

int main()
{
    // define an integer variable named x
    int x; // this variable is uninitialized

    doNothing(x); // make the compiler think we're assigning a value to this variable

    // print the value of x to the screen (who knows what we'll get, because x is uninitialized)
    std::cout << x << '\n';

    return 0;
}




#include <iostream>

int main()
{
    std::cout << 1 + 2 << '\n';

    return 0;
}



// five() is a function that returns the value 5
int five()
{
    return 5;
}

int main()
{
    int a{ 2 };             // initialize variable a with literal value 2
    int b{ 2 + 3 };         // initialize variable b with computed value 5
    int c{ (2 * 3) + 4 };   // initialize variable c with computed value 10
    int d{ b };             // initialize variable d with variable value 5
    int e{ five() };        // initialize variable e with function return value 5

    return 0;
}


#include <iostream>

int main()
{
	std::cout << 2 + 3 << '\n'; //5 

	int x{ 6 };
	int y{ x - 2 };
	std::cout << y << '\n'; //4

	int z{ };
	z = x;
	std::cout << z - x << '\n'; //0

	return 0;
}



// https://www.learncpp.com/cpp-tutorial/developing-your-first-program/

/*
The not-good solution

#include <iostream>

// worst version
int main()
{
	std::cout << "Enter an integer: ";

	int num{ };
	std::cin >> num;

	num = num * 2; // double num's value, then assign that value back to num

	std::cout << "Double that number is: " << num << '\n';

	return 0;
}
In this solution, we use an expression to multiply num by 2, and then assign that value back to num. From that point forward, num will contain our doubled number.

Why this is a bad solution:

Before the assignment statement, num contains the user’s input. After the assignment, it contains a different value. That’s confusing.
We overwrote the user’s input by assigning a new value to the input variable, so if we wanted to extend our program to do something else with that input value later (e.g. triple the user’s input), it’s already been lost.
The mostly-good solution

#include <iostream>

// less-bad version
int main()
{
	std::cout << "Enter an integer: ";

	int num{ };
	std::cin >> num;

	int doublenum{ num * 2 }; // define a new variable and initialize it with num * 2
	std::cout << "Double that number is: " << doublenum << '\n'; // then print the value of that variable here

	return 0;
}
This solution is pretty straightforward to read and understand, and resolves both of the problems encountered in the worst solution.

The primary downside here is that we’re defining a new variable (which adds complexity) to store a value we only use once. We can do better.

*/

The preferred solution

#include <iostream>

// preferred version
int main()
{
	std::cout << "Enter an integer: ";

	int num{ };
	std::cin >> num;

	std::cout << "Double that number is: " <<  num * 2 << '\n'; // use an expression to multiply num * 2 at the point where we are going to print it

	return 0;
}



#include <iostream>

int main()
{
	std::cout << "Enter an integer: ";

	int num{ };
	std::cin >> num;

	std::cout << "Double " << num << " is: " << num * 2 << '\n';
	std::cout << "Triple " << num << " is: " << num * 3 << '\n';

	return 0;
}


