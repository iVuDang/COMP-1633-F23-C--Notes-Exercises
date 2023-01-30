// File:    lab3_q9.cpp
// Purpose: converts a temperature in Fahrenheit to Celcius
//          but treats temperatures as integer values

#include <iostream>
using namespace std;

int main()
{
  int
    fahr, celcius;


  cout << "Enter a temp in Fahrenheit: ";
  cin >> fahr;

  celcius = 5 / 9 * (fahr - 32);

  cout << fahr << " degrees Fahrenheit is "
       << celcius << " degrees Celcius" << endl;

  return 0;
}
