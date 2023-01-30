#include <iostream>
using namespace std;

int main()
{
  int rate,
      time,
      distance;

  cout << "enter travel rate (km/h): ";
  cin >> rate;

  cout << "enter travel time (h): ";
  cin >> time;

  distance = rate * time;

  cout << endl
       << "travel distance is "
       << distance
       << "km"
       << endl;

  return 0;
}
