#include <iostream>
#include <math.h> 
using namespace std; 

/*
9. Write the pseudo-code of an algorithm that given the lengths of two sides of a right triangle, computes the length of the hypotenuse. (Use Pythagorean Theorem from geometry.)

In: base and height

Out: hypotenuse

Pythagorean Theorem =

a^2 + b^2 = c^2 
c = sqrt(a^2 + b^2)

*/

int main() {
  
  double base, height, hypotenuse; 

  cout << "Enter the base and height of a right angle triangle: " << endl; 
  cin >> base >> height; 

  hypotenuse = sqrt((base*base) + (height*height)); 

  cout << "The hypotenuse is: " << hypotenuse << endl; 

  return 0; 
}