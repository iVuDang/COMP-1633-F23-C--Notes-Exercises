// LAB 6 - DECISIONS
// ex.1
#include <iostream>

using namespace std;

int main()
{
  bool a = false;
  bool b = true;
  bool c = true;

  if (a || !b && c)
    cout << "whole expression is true" << endl;
  else
    cout << "whole expression is false" << endl;

  return 0;
}


// ex. 5
#include <iostream>
using namespace std;

int main()
{
  char choice;
  bool sensor;
  int timer;

  cout << "Does the sensor detect a car on Slow Street? (y/n): ";
  cin >> choice;
  sensor = (choice == 'y' || choice == 'Y');

  cout << "What is the value of the timer? (>= 0): ";
  cin >> timer;

  // (1) develop a suitable Boolean expression, and insert it as the test below
  // (2) test your work by running the program for a variety of combinations

  if ( your condition)
    cout << "Slow gets a green" << endl;
  else
    cout << "Slow gets a red" << endl;

  return 0;
}


// ex.7
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
  double x;
  double num1;
  double num2;

  x = 1234.5678;
  num1 = x / 1000 - 1;
  num2 = 0.2345678;

  cout << num1 << " == " << num2 << endl;
  if (num1 == num2)
    cout << "they're equal!" << endl;
  else
    cout << "they're NOT equal!" << endl;

  cout << endl << endl;

  x = 1234.5679;
  num1 = x / 1000 - 1;
  num2 = 0.2345678;

  cout << num1 << " == " << num2 << endl;
  if (num1 == num2)
    cout << "they're equal!" << endl;
  else
    cout << "they're NOT equal!" << endl;

  return 0;


