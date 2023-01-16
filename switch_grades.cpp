#include <iostream>
using namespace std; 

int main() {

  int grade; // type and variable name, to instantize 
  
  cout << "Enter grade out of 100: ";
  cin >> grade; // places entered value into our variable 'grade'

  int grade_10 = grade/10; 

  switch(grade_10) {  

    case 10:
    case 9:
      cout << "The grade is A" << endl; 
      break;
    
    case 8: 
      cout << "The grade is B" << endl; 
      break;

    case 7:
      cout << "The grade is C" << endl;
      break;
    
    case 6: 
      cout << "The grade is D" << endl; 
      break;

    default:
      cout << "The grade is F" << endl;   
      break;
  } // ends switch function 

  return 0; 
}



/*
CITATIONS / NOTES 
https://www.w3schools.com/cpp/cpp_switch.asp


The switch expression is evaluated once
The value of the expression is compared with the values of each case
If there is a match, the associated block of code is executed
The break and default keywords are optional, and will be described later in this chapter

int day = 4;
switch (day) {
  case 1:
    cout << "Monday";
    break;
  case 2:
    cout << "Tuesday";
    break;
  case 3:
    cout << "Wednesday";
    break;
  case 4:
    cout << "Thursday";
    break;
  case 5:
    cout << "Friday";
    break;
  case 6:
    cout << "Saturday";
    break;
  case 7:
    cout << "Sunday";
    break;
}
// Outputs "Thursday" (day 4)

*/ 