#include <iostream>
#include <cmath>
#include <cassert>
using namespace std;

double my_round (double);
void test_my_round (double, double);

int main ()
{
  test_my_round (2.0, 2.0);
  test_my_round (2.4, 2.0);
  test_my_round (2.5, 2.0);
  test_my_round (2.9, 3.0);

  return 0;
}


double my_round (double value)
{
  double answer;
  answer = floor (value + 0.5);
  return answer;
}


void test_my_round (double to_round, double expected)
{
    double actual_result = my_round (to_round);
    cout << "round(" << to_round << ") = "  << actual_result << " <-- expected: "
         << expected << endl;
    assert (actual_result == expected);
}
