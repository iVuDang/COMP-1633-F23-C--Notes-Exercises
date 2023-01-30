#include <iostream>
using namespace std;

int main()
{
  double fahr, celcius;


  cout << "Enter a temp in Fahrenheit: ";
  cin >> fahr;

  celcius = 5 / 9.0 * (fahr - 32);

  cout << fahr << " degrees Fahrenheit is "
       << celcius << " degrees Celcius" << endl;

  return 0;
}
