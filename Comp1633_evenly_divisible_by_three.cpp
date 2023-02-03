#include <iostream>
using namespace std;

/*
Write a sentinel loop that counts the number of values, entered by the user,
that are evenly divisible by 3 until the value -99 is entered.
*/

int main() {

  int num;

  int count = 0;

  cout << "Enter values (-99 to stop): " << endl;
  cin >> num;

  while (num != -99) {
    if ((num % 3) == 0) {
      count = count + 1;
    }
    cin >> num;
  }

  cout << "The number of values divisible by 3 are: " << count << endl;

  return 0;
}