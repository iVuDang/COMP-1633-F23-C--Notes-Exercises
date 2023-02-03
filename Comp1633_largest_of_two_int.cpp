#include <iostream>
using namespace std; 

/*
Write the pseudo-code of an algorithm that reads two numbers from the input and prints the largest one.

In: first, second (two numbers)
Out: largest

variable = (condition) ? expressionTrue : expressionFalse;

  */

int main() {
  
  int first, second; 

  cout << "Enter a first and second number: " << endl;

  cin >> first >> second; 

  int largest = (first > second) ? first : second; 

  cout << "Largest number is: " << largest << endl; 

  return 0; 
}



// SOLUTION 2
int main() {
  
  int first, second, largest; 

  cout << "Enter a first and second number: " << endl;

  cin >> first >> second; 

  if (first > second){
    largest = first; 
  } else {
    largest = second; 
  }

  cout << "Largest number is: " << largest << endl; 

  return 0; 
}




