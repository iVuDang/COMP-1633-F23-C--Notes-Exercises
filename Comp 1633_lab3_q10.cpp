#include <iostream>
using namespace std;

const int SECONDS_IN_HOUR = 3600;
const int SECONDS_IN_MINUTE = 60;

int main()
{
  int startingSeconds,
    remainingSeconds,
      minutes,
      hours;

  cout << "seconds: ";
  cin >> startingSeconds;

  hours = startingSeconds / SECONDS_IN_HOUR;
  remainingSeconds = startingSeconds % SECONDS_IN_HOUR;

  minutes = remainingSeconds / SECONDS_IN_MINUTE;
  remainingSeconds = remainingSeconds % SECONDS_IN_MINUTE;

  cout << hours << "h:"
       << minutes << "m:"
       << remainingSeconds << "s"
       << endl;

  return 0;
}
