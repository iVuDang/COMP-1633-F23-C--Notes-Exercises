#include <iostream>
#include <cmath>
using namespace std;

double my_round (double value);

int main ()
{
  double inNum, outNum;

  cout << "enter num: ";
  cin >> inNum;
  outNum = my_round (inNum);
  cout << "round(" << inNum << ") = " << outNum << endl;

  return 0;
}

double my_round (double value)
{
  double answer;

  answer = floor(value + 0.5);

  return answer;
}
