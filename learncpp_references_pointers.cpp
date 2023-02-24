#include <iostream>

int main()
{
    // Our first fraction
    int num1 {};
    int den1 {};

    // Our second fraction
    int num2 {};
    int den2 {};

    // Used to eat the slash between the numerator and denominator
    char ignore {};

    std::cout << "Enter a fraction: ";
    std::cin >> num1 >> ignore >> den1;

    std::cout << "Enter a fraction: ";
    std::cin >> num2 >> ignore >> den2;

    std::cout << "The two fractions multiplied: "
        << num1 * num2 << '/' << den1 * den2 << '\n';

    return 0;
}


// Enter a fraction: 1/2
// Enter a fraction: 3/4
// The two fractions multiplied: 3/8

#include <iostream>

int main()
{
    int x { 5 }; // normal integer variable
    int& ref { x }; // ref is now an alias for variable x

    std::cout << x << ref << '\n'; // print 55

    x = 6; // x now has value 6

    std::cout << x << ref << '\n'; // prints 66

    ref = 7; // the object being referenced (x) now has value 7

    std::cout << x << ref << '\n'; // prints 77

    return 0;
}

#include <iostream>

int main()
{
    int x{ 1 };
    int& ref{ x };

    std::cout << x << ref << '\n'; //11

    int y{ 2 };
    ref = y;
    y = 3;

    std::cout << x << ref << '\n'; //22

    x = 4;

    std::cout << x << ref << '\n'; //44

    return 0;
}

#include <iostream>
#include <string>

void printValue(std::string y)
{
    std::cout << y << '\n';
} // y is destroyed here

int main()
{
    std::string x { "Hello, world!" }; // x is a std::string

    printValue(x); // x is passed by value (copied) into parameter y (expensive)

    return 0;
}


// While this program behaves like we expect, it’s also inefficient. Identically to the prior example, when printValue() is called, argument x is copied into printValue() parameter y. However, in this example, the argument is a std::string instead of an int, and std::string is a class type that is expensive to copy. And this expensive copy is made every time printValue() is called!

// We can do better.


#include <iostream>
#include <string>

void printValue(std::string& y) // type changed to std::string&
{
    std::cout << y << '\n';
} // y is destroyed here

int main()
{
    std::string x { "Hello, world!" };

    printValue(x); // x is now passed by reference into reference parameter y (inexpensive)

    return 0;
}


// Binding a reference is always inexpensive, and no copy of x needs to be made. Because a reference acts as an alias for the object being referenced, when printValue() uses reference y, it’s accessing the actual argument x (rather than a copy of x).

#include <iostream>

void addOne(int y) // y is a copy of x
{
    ++y; // this modifies the copy of x, not the actual object x
}

int main()
{
    int x { 5 };

    std::cout << "value = " << x << '\n';

    addOne(x);

    std::cout << "value = " << x << '\n'; // x has not been modified

    return 0;
}

// value = 5
// value = 5

#include <iostream>

void addOne(int& y) // y is bound to the actual object x
{
    ++y; // this modifies the actual object x
}

int main()
{
    int x { 5 };

    std::cout << "value = " << x << '\n';

    addOne(x);

    std::cout << "value = " << x << '\n'; // x has been modified

    return 0;
}

// value = 5
// value = 6

// the above example, x initially has value 5. When addOne(x) is called, reference parameter y is bound to argument x. When the addOne() function increments reference y, it’s actually incrementing argument x from 5 to 6 (not a copy of x). This changed value persists even after addOne() has finished executing.

// The ability for functions to modify the value of arguments passed in can be useful. Imagine you’ve written a function that determines whether a monster has successfully attacked the player. If so, the monster should do some amount of damage to the player’s health. If you pass your player object by reference, the function can directly modify the health of the actual player object that was passed in. If you pass the player object by value, you could only modify the health of a copy of the player object, which isn’t as useful.

#include <iostream>

// Function-like macro that evaluates to true if the type (or object) uses 2 or fewer memory addresses worth of memory
#define isSmall(T) (sizeof(T) <= 2 * sizeof(void*))

struct S
{
    double a, b, c;
};

int main()
{
    std::cout << std::boolalpha; // print true or false rather than 1 or 0
    std::cout << isSmall(int) << '\n'; // true
    std::cout << isSmall(double) << '\n'; // true
    std::cout << isSmall(S) << '\n'; // false

    return 0;
}

#include <iostream>

int main()
{
    int x{ 5 };
    std::cout << x << '\n';  // print the value of variable x
    std::cout << &x << '\n'; // print the memory address of variable x

    return 0;
}


// 5
// 0027FEA0


// The & symbol tends to cause confusion because it has different meanings depending on context:

// When following a type name, & denotes an lvalue reference: int& ref.
// When used in a unary context in an expression, & is the address-of operator: std::cout << &x.
// When used in a binary context in an expression, & is the Bitwise AND operator: std::cout << x & y.

// The dereference operator (*) (also occasionally called the indirection operator) returns the value at a given memory address as an lvalue:

#include <iostream>

int main()
{
    int x{ 5 };
    std::cout << x << '\n';  // print the value of variable x
    std::cout << &x << '\n'; // print the memory address of variable x

    std::cout << *(&x) << '\n'; // print the value at the memory address of variable x (parentheses not required, but make it easier to read)

    return 0;
}

// 5
// 0x7fff19101130
// 5

// The address-of operator (&) and dereference operator (*) work as opposites: address-of gets the address of an object, and dereference gets the object at an address.

int main()
{
    int x { 5 };    // normal variable
    int& ref { x }; // a reference to an integer (bound to x)

    int* ptr;       // a pointer to an integer

    return 0;
}


#include <iostream>

int main()
{
    int x{ 5 };
    std::cout << x << '\n'; // print the value of variable x

    int* ptr{ &x }; // ptr holds the address of x
    std::cout << *ptr << '\n'; // use dereference operator to print the value at the address that ptr is holding (which is x's address)

    return 0;
}

// 5
// 5
// ptr is holding the address of x, so we say that ptr is “pointing to” x


int main()
{
    int i{ 5 };
    double d{ 7.0 };

    int* iPtr{ &i };     // ok: a pointer to an int can point to an int object
    int* iPtr2 { &d };   // not okay: a pointer to an int can't point to a double
    double* dPtr{ &d };  // ok: a pointer to a double can point to a double object
    double* dPtr2{ &i }; // not okay: a pointer to a double can't point to an int
}

#include <iostream>

int main()
{
    int x{ 5 };
    int* ptr{ &x }; // ptr initialized to point at x

    std::cout << *ptr << '\n'; // print the value at the address being pointed to (x's address)

    int y{ 6 };
    ptr = &y; // // change ptr to point at y

    std::cout << *ptr << '\n'; // print the value at the address being pointed to (y's address)

    return 0;
}

// 5
// 6

// In the above example, we define pointer ptr, initialize it with the address of x, and dereference the pointer to print the value being pointed to (5). We then use the assignment operator to change the address that ptr is holding to the address of y. We then dereference the pointer again to print the value being pointed to (which is now 6).


#include <iostream>

int main()
{
    int x{ 5 };
    int* ptr{ &x }; // initialize ptr with address of variable x

    std::cout << x << '\n';    // print x's value
    std::cout << *ptr << '\n'; // print the value at the address that ptr is holding (x's address)

    *ptr = 6; // The object at the address held by ptr (x) assigned value 6 (note that ptr is dereferenced here)

    std::cout << x << '\n';
    std::cout << *ptr << '\n'; // print the value at the address that ptr is holding (x's address)

    return 0;
}

// 5
// 5
// 6
// 6

// In this example, we define pointer ptr, initialize it with the address of x, and then print the value of both x and *ptr (5). Because *ptr returns an lvalue, we can use this on the left hand side of an assignment statement, which we do to change the value being pointed at by ptr to 6. We then print the value of both x and *ptr again to show that the value has been updated as expected.


#include <iostream>

int main()
{
    int x{ 5 };
    int& ref { x };  // get a reference to x
    int* ptr { &x }; // get a pointer to x

    std::cout << x;
    std::cout << ref;  // use the reference to print x's value (5)
    std::cout << *ptr << '\n'; // use the pointer to print x's value (5)

    ref = 6; // use the reference to change the value of x
    std::cout << x;
    std::cout << ref;  // use the reference to print x's value (6)
    std::cout << *ptr << '\n'; // use the pointer to print x's value (6)

    *ptr = 7; // use the pointer to change the value of x
    std::cout << x;
    std::cout << ref;  // use the reference to print x's value (7)
    std::cout << *ptr << '\n'; // use the pointer to print x's value (7)

    return 0;
}


// This program prints:

// 555
// 666
// 777

// References must be initialized, pointers are not required to be initialized (but should be).

// References are not objects, pointers are.

// References can not be reseated (changed to reference something else), pointers can change what they are pointing at.

// References must always be bound to an object, pointers can point to nothing (we’ll see an example of this in the next lesson).

// References are “safe” (outside of dangling references), pointers are inherently dangerous (we’ll also discuss this in the next lesson).

// Pointers are variables that hold a memory address. They can be dereferenced using the dereference operator (*) to retrieve the value at the address they are holding.


#include <iostream>

int main()
{
	short value{ 7 }; // &value = 0012FF60
	short otherValue{ 3 }; // &otherValue = 0012FF54

	short* ptr{ &value };

	std::cout << &value << '\n';   // 0x7ffc79ff383c
	std::cout << value << '\n';    // 7
	std::cout << ptr << '\n';      // 0x7ffc79ff383c
	std::cout << *ptr << '\n';     // 7
	std::cout << '\n';

	*ptr = 9;

	std::cout << &value << '\n';    // 0x7ffc79ff383c
	std::cout << value << '\n';     // 9
	std::cout << ptr << '\n';       // 0x7ffc79ff383c
	std::cout << *ptr << '\n';      // 9
	std::cout << '\n';

	ptr = &otherValue;

	std::cout << &otherValue << '\n';  // 0x7ffc79ff383a 
	std::cout << otherValue << '\n';   // 3
	std::cout << ptr << '\n';          // 0x7ffc79ff383a
	std::cout << *ptr << '\n';         // 3
	std::cout << '\n';

	std::cout << sizeof(ptr) << '\n';
	std::cout << sizeof(*ptr) << '\n';

	return 0;
}


// What’s wrong with this snippet of code?

int value{ 45 };
int* ptr{ &value }; // declare a pointer and initialize with address of value
*ptr = &value; // assign address of value to ptr

// The first line contains a standard variable definition, along with an initialization value. Nothing special here.

// In the second line, we’re defining a new pointer named ptr, and initializing it with the address of value. Remember that in this context, the asterisk is part of the pointer declaration syntax, not a dereference. So this line is fine.

// On line three, the asterisk represents a dereference, which is used to get the value that a pointer is pointing to. So this line says, “retrieve the value that ptr is pointing to (an integer), and overwrite it with the address of value (an address). That doesn’t make any sense -- you can’t assign an address to an integer!
  
// The third line should be:

// ptr = &value;

#include <iostream>

int main()
{
    int x{ 5 };
    std::cout << x << '\n'; // print the value of variable x

    int* ptr{ &x }; // ptr holds the address of x
    std::cout << *ptr << '\n'; // use dereference operator to print the value at the address that ptr is holding (which is x's address)

    return 0;
}
// The above example prints:

// 5
// 5


#include <iostream>

int main()
{
    int* ptr {}; // ptr is a null pointer, and is not holding an address

    int x { 5 };
    ptr = &x; // ptr now pointing at object x (no longer a null pointer)

    std::cout << *ptr << '\n'; // print value of x through dereferenced ptr

    return 0;
}

// 5


int main()
{
    int x { 5 };
    int* ptr { &x }; // ptr is a normal (non-const) pointer

    int y { 6 };
    ptr = &y; // we can point at another value

    *ptr = 7; // we can change the value at the address being held

    return 0;
}


#include <iostream>
#include <string>

void printByValue(std::string val) // The function parameter is a copy of str
{
    std::cout << val << '\n'; // print the value via the copy
}

void printByReference(const std::string& ref) // The function parameter is a reference that binds to str
{
    std::cout << ref << '\n'; // print the value via the reference
}

int main()
{
    std::string str{ "Hello, world!" };

    printByValue(str); // pass str by value, makes a copy of str
    printByReference(str); // pass str by reference, does not make a copy of str

    return 0;
}

// Hello, world!
// Hello, world!


#include <iostream>
#include <string>

void printByValue(std::string val) // The function parameter is a copy of str
{
    std::cout << val << '\n'; // print the value via the copy
}

void printByReference(const std::string& ref) // The function parameter is a reference that binds to str
{
    std::cout << ref << '\n'; // print the value via the reference
}

int main()
{
    std::string str{ "Hello, world!" };

    printByValue(str); // pass str by value, makes a copy of str
    printByReference(str); // pass str by reference, does not make a copy of str

    return 0;
}

// Hello, world!
// Hello, world!


#include <iostream>
#include <string>

void printByValue(std::string val) // The function parameter is a copy of str
{
    std::cout << val << '\n'; // print the value via the copy
}

void printByReference(const std::string& ref) // The function parameter is a reference that binds to str
{
    std::cout << ref << '\n'; // print the value via the reference
}

void printByAddress(const std::string* ptr) // The function parameter is a pointer that holds the address of str
{
    std::cout << *ptr << '\n'; // print the value via the dereferenced pointer
}

int main()
{
    std::string str{ "Hello, world!" };

    printByValue(str); // pass str by value, makes a copy of str
    printByReference(str); // pass str by reference, does not make a copy of str
    printByAddress(&str); // pass str by address, does not make a copy of str

    return 0;
}

#include <iostream>

void changeValue(int* ptr) // note: ptr is a pointer to non-const in this example
{
    *ptr = 6; // change the value to 6
}

int main()
{
    int x{ 5 };

    std::cout << "x = " << x << '\n';

    changeValue(&x); // we're passing the address of x to the function

    std::cout << "x = " << x << '\n';

    return 0;
}

// x = 5
// x = 6


