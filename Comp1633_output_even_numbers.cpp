#include <iostream>
using namespace std; 

/*
Write a loop that outputs all the even numbers between 1 and 100
  */

int main() {
  for (int i = 2; i <= 100; i += 2){
    cout << i << endl; 
  }
  return 0; 
}


// SOLUTION 2
#include <iostream>
using namespace std; 

/*
Write a loop that outputs all the even numbers between 1 and 100
  */

int main() {
  for (int i = 1; i <= 100; i++){
    
    if (i % 2 == 0){
      cout << i << endl;
    }
    
  }
  return 0;
}