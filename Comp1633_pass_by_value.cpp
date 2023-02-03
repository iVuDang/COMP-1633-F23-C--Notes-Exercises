#include <iostream>
using namespace std;

void swap(int a, int b);

void swap(int a, int b) {
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

  cout << x << "," << y << endl; // 2,5

  swap(x, y);

  cout << x << "," << y << endl; // 2,5

  return 0;
}
