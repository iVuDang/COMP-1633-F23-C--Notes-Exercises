#include <iostream>

int getValue()
{
    std::cout << "Enter an integer: ";

    int x{};
    std::cin >> x;
    return x;
}

int main()
{
    std::cout << getValue() + (getValue() * getValue()); // a + (b * c)
    return 0;
}

/*
Enter an integer: 1
Enter an integer: 2
Enter an integer: 3
7
*/

//------------------------------------------------------------------------------


#include <iostream>

int main()
{
	std::cout << "Enter an integer: ";
	int x{};
	std::cin >> x;

	std::cout << "Enter another integer: ";
	int y{};
	std::cin >> y;

	std::cout << "The remainder is: " << x % y << '\n';

	if ((x % y) == 0)
		std::cout << x << " is evenly divisible by " << y << '\n';
	else
		std::cout << x << " is not evenly divisible by " << y << '\n';

	return 0;
}


// Enter an integer: 6
// Enter another integer: 3
// The remainder is: 0
// 6 is evenly divisible by 3

// Enter an integer: 6
// Enter another integer: 4
// The remainder is: 2
// 6 is not evenly divisible by 4

// Enter an integer: 2
// Enter another integer: 4
// The remainder is: 2
// 2 is not evenly divisible by 4

// A remainder of 2 might be a little non-obvious at first, but it’s simple: 2 / 4 is 0 (using integer division) remainder 2. Whenever the second number is larger than the first, the second number will divide the first 0 times, so the first number will be the remainder.

// * Modulus calculation formula: (Quotient × Divisor) + Remainder = Dividend
// (4 * 0) + 2 = 2

// The modulus operator can also work with negative operands. x % y always returns results with the sign of x.

// Enter an integer: -6
// Enter another integer: 4
// The remainder is: -2
// -6 is not evenly divisible by 4

// Enter an integer: 6
// Enter another integer: -4
// The remainder is: 2
// 6 is not evenly divisible by -4

// In both cases, you can see the remainder takes the sign of the first operand.

//------------------------------------------------------------------------------

// Write a program that asks the user to input an integer, and tells the user whether the number is even or odd. Write a function called isEven() that returns true if an integer passed to it is even, and false otherwise. Use the modulus operator to test whether the integer parameter is even.

// Hint: You’ll need to use if statements and the comparison operator (==) for this program. See lesson 4.9 -- Boolean values if you need a refresher on how to do this.

// Your program should match the following output:

// Enter an integer: 5
// 5 is odd

#include <iostream>

bool isEven(int x)
{
    // if x % 2 == 0, 2 divides evenly into our number, which means it must be an even number
    return (x % 2) == 0;                    // returns true or false 
}


int main()
{
    std::cout << "Enter an integer: ";
    int x{};
    std::cin >> x;

    if (isEven(x))                          // boolean return function 
        std::cout << x << " is even\n";
    else
        std::cout << x << " is odd\n";

    return 0;
}


//------------------------------------------------------------------------------

// ++x	Increment x, then return x
// x++	Copy x, then increment x, then return the copy

#include <iostream>

int main()
{
    int x { 5 };
    int y = ++x; // x is incremented to 6, x is evaluated to the value 6, and 6 is assigned to y

    std::cout << x << ' ' << y << '\n';
    return 0;
}


// This prints:

// 6 6


#include <iostream>

int main()
{
    int x { 5 };
    int y = x++; // x is incremented to 6, copy of original x is evaluated to the value 5, and 5 is assigned to y

    std::cout << x << ' ' << y << '\n';
    return 0;
}


// This prints:

// 6 5


//------------------------------------------------------------------------------

#include <iostream>

int main()
{
    int x{ 5 };
    int y{ 5 };
    std::cout << x << ' ' << y << '\n';                   // 5 5
  
    std::cout << ++x << ' ' << --y << '\n'; // prefix    // 6 4
  
    std::cout << x << ' ' << y << '\n';                  // 6 4
  
    std::cout << x++ << ' ' << y-- << '\n'; // postfix   // 6 4
  
    // changes don’t show up until the next line, when x and y are evaluated again.
    std::cout << x << ' ' << y << '\n';                  // 7 3

    return 0;
}


//------------------------------------------------------------------------------


#include <iostream>

int main()
{
    int x{ 1 };
    int y{ 2 };

    std::cout << (++x, ++y) << '\n'; // increment x and y, evaluates to the right operand

    return 0;
}

//------------------------------------------------------------------------------



// One thing to be wary of is that logical NOT has a very high level of precedence. New programmers often make the following mistake:

#include <iostream>

int main()
{
    int x{ 5 };
    int y{ 7 };

    if (!x > y)
        std::cout << x << " is not greater than " << y << '\n';
    else
        std::cout << x << " is greater than " << y << '\n';

    return 0;
}

// This program prints:

// 5 is greater than 7

// But x is not greater than y, so how is this possible? The answer is that because the logical NOT operator has higher precedence than the greater than operator, the expression ! x > y actually evaluates as (!x) > y. Since x is 5, !x evaluates to 0, and 0 > y is false, so the else statement executes!

// The correct way to write the above snippet is:

#include <iostream>

int main()
{
    int x{ 5 };
    int y{ 7 };

    if (!(x > y))
        std::cout << x << " is not greater than " << y << '\n';
    else
        std::cout << x << " is greater than " << y << '\n';

    return 0;
}

// This way, x > y will be evaluated first, and then logical NOT will flip the Boolean result.


//------------------------------------------------------------------------------

