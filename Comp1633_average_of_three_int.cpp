#include <iostream>
using namespace std; 

/* 
Write the pseudo-code of an algorithm that reads three numbers from the input and prints the average.

In: first, second, third (three numbers)

Out: average

*/ 

int main() {
  
  int first, second, third, average; 

  cout << "Enter three numbers: " << endl; 
  cin >> first >> second >> third; 

  average = (first + second + third) / 3; 

  cout << "The average is: " << average << endl; 
  
  return 0;
}


// SOLUTION 2
#include <iostream>
using namespace std; 

/* 
Write the pseudo-code of an algorithm that reads three numbers from the input and prints the average.

In: first, second, third (three numbers)

Out: average

*/ 

int main() {

  int num, average; 
  int count = 0 ;
  int total = 0; 

  while (count < 3){
    cout << "Enter a number: " << endl; 
    cin >> num; 
    
    total = total + num; 
    
    count = count + 1; 
  }

  average = total / 3;
  cout << "The average is: " << average << endl; 

  return 0;
  
}