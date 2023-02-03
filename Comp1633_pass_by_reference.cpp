#include <iostream>
using namespace std; 

// DECLARE PROTOTYPE
void swap(int &a, int &b); 

// FUNCTION with PROTOTYPE above
void swap(int &a, int &b){
  int temp; 
  
  temp = a; 
  a = b; 
  b = temp; 
  return; 
}

int main() {
  int x, y; 
  
  x = 2; 
  y = 5;
  
  cout << x << "," << y << endl; // 2, 5

  swap(x, y);

  cout << x << "." << y << endl; // 5, 2
  
  return 0; 
}