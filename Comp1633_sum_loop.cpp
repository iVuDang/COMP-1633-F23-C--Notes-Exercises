#include <iostream>
using namespace std;

/*
Write a loop that calculates the sum of the numbers 21, 22, 23, .., 39. The sum
is to be written out after the loop terminates
*/

int main() {
  int sum = 0;
  int n;

  cout << "Enter number of integers to sum: " << endl; // Determines the n amount of integers to sum
  cin >> n;

  for (int i = 1; i <= n; i++) {
    int num;
    cout << "Enter integer " << i << ": " << endl; // Specific integers to sum
    cin >> num;
    sum = sum + num;
  }

  cout << "The sum of the numbers is: " << sum << endl;

  return 0;
}