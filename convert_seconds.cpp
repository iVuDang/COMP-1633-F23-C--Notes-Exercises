#include <iostream>
using namespace std; 

int main() {
  int seconds, minutes, hours;
  
  cout << "Please enter amount of seconds" << endl; 
  cin >> seconds; 

  minutes = seconds/60;
  hours = minutes/60; 

  cout << seconds << " seconds is the same as " << int(hours) << "h:" << int(minutes%60) << "m:" << int(seconds%60) << "s." << endl; 

return 0; 
}