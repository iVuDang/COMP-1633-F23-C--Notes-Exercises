#include <iostream>

void print(int x)
{
     std::cout << x << '\n';
}

void print(double d)
{
     std::cout << d << '\n';
}

int main()
{
     print(5); // 5 is an int, so this matches print(int)
     print(6.7); // 6.7 is a double, so this matches print(double)

     return 0;
}

#include <iostream>

void print(int x, int y=4) // 4 is the default argument
{
    std::cout << "x: " << x << '\n';
    std::cout << "y: " << y << '\n';
}

int main()
{
    print(1, 2); // y will use user-supplied argument 2
    print(3); // y will use default argument 4

}

// x: 1
// y: 2
// x: 3
// y: 4

// void foo(int x = 5);   // ok
// void goo(int x ( 5 )); // compile error
// void boo(int x { 5 }); // compile error

#include <iostream>

void print(int x=10, int y=20, int z=30)
{
    std::cout << "Values: " << x << " " << y << " " << z << '\n';
}

int main()
{
    print(1, 2, 3); // all explicit arguments
    print(1, 2); // rightmost argument defaulted
    print(1); // two rightmost arguments defaulted
    print(); // all arguments defaulted

    return 0;
}

// Values: 1 2 3
// Values: 1 2 30
// Values: 1 20 30
// Values: 10 20 30


#include <iostream>

template <typename T>
T add(T x, T y)
{
	return x + y;
}

int main()
{
	std::cout << add(2, 3) << '\n';
	std::cout << add(1.2, 3.4) << '\n';

	return 0;
}

// 5
// 4.6



#include <iostream>

template <typename T>
T mult(T x, int y)
{
	return x * y;
}

int main()
{
	std::cout << mult(2, 3) << '\n';
	std::cout << mult(1.2, 3) << '\n';

	return 0;
}

// 6
// 3.6



#include <iostream>

template <typename T, typename U>
auto sub(T x, U y)
{
	return x - y;
}

/*
//If C++20 capable, you can use an abbreviated function template instead
auto sub(auto x, auto y)
{
	return x - y;
}
*/

int main()
{
	std::cout << sub(3, 2) << '\n';
	std::cout << sub(3.5, 2) << '\n';
	std::cout << sub(4, 1.5) << '\n';

	return 0;
}


// 1
// 1.5
// 2.5

