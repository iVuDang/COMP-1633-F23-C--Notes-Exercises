#include <iostream>
#include <cmath>
using namespace std;

int main ()
{
  double inNum, outNum;

  cout << "enter num: ";
  cin >> inNum;
  outNum = round (inNum);
  cout << "round(" << inNum << ") = " << outNum << endl;

  return 0;
}
