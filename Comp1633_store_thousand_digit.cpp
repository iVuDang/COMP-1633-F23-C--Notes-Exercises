/*
  Write in pseudo-code the solution for the following problem. Read a number from the input into variable num. Determine and store the thousand digit of num into the variable thous.
*/

#include <iostream>
using namespace std; 

int main() {

  int num; 
  
  cout << "Enter a number: " << endl; 
  cin >> num; 

  int thous = (num / 1000) % 10; 

  cout << thous << endl; 

  return 0; 
}