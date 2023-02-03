#include <iostream>
using namespace std; 

/*
Write in pseudo-code the solution for the following problem. Read the age of a person and determine the number of years left to work until retirement. Use the formula 65-age to determine the years left to be worked. Print the result.

In: age (assume integer)
Out: years to work
*/


int main(){

  int age; 

  cout << "Enter your age: " << endl; 
  cin >> age;

  int years_to_work = 65 - age;

  cout << "If you are below 65 years old, you have remaining years to work: " << years_to_work << endl; 

  return 0;
}