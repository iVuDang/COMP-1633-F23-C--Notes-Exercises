#include <iostream>
using namespace std;

int main() {

  int grade; 
  
  cout << "Enter number out of 100 for grade: "; // character outputs 'cout' a string 
  cin >> grade; // if character input 'cin' follows a cout, changes cout similar to 'input()' function in python

  if (grade < 60) {
    cout << 'F' << endl; 
  }
    
  else if (grade < 70) {
    cout << 'D' << endl; 
  }

  else if (grade < 80) {
    cout << 'C' << endl; 
  }

  else if (grade < 90){
    cout << 'B' << endl; 
  }

  else cout << 'A' << endl; 

  return 0; 
}

/*
PYTHON

def main():
    grade = 85

    if (grade < 60):
        print('F')
    elif (grade < 70):
        print('D')
    elif grade < 80:
        print('C')
    elif grade < 90:
        print('B')
    else:
        print('A')

main()

*/


/*
CITATIONS 

https://www.w3schools.com/cpp/cpp_user_input.asp

https://runestone.academy/ns/books/published/cpp4python/Control_Structures/conditionals.html

*/

