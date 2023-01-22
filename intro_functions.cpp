// CITATION
// https://runestone.academy/ns/books/published/cpp4python/Functions/DefiningFunctions.html

#include <iostream>
using namespace std;

int timesTwo(int num){
  return num*2;
}

int main(){
  cout << timesTwo(5) << endl; // enter a parameter of 5 into our function timesTwo

  return 0;
}

// 10


#include <iostream>
using namespace std; 

void timesTwoVoid(int num){
  cout << num*2 << endl; 
}


int main(){
  timesTwoVoid(5);

  return 0;
}

// 10


/*
The timesTwoVoid function behaves very similarly to timesTwo. 
However, there is one key difference between them. 

Instead of the int in timesTwo, timesTwoVoid has a void in front of its function definition. Unlike timesTwo, timesTwoVoid is a non-fruitful function meaning it does not return a value even though it can still print something out.

*/



// returns the square root of a number as a double
#include <iostream>
using namespace std;

double squareroot(double n) { /*return type double which indicates
                                that a decimal is being returned*/
      double root = n / 2;

      for (int i = 0; i < 20; i++) {
                root = (.5) * (root + (n / root));
      }

      return root;
}


int main() {
      cout << squareroot(9) << endl;
      cout << squareroot(4563) << endl;

      return 0;
}


// 3
// 67.55



// function that retuns outputs number of steps wallked
#include <iostream>
using namespace std;

void dogWalk(int steps) {
  for (int step = 0; step < steps; step++) {
    cout << "dog walked " << step << " steps!" << endl;
  }
}

int main() {
  dogWalk(11);

  return 0;
}

// dog walked 0 steps!
// dog walked 1 steps!
// dog walked 2 steps!
// dog walked 3 steps!
// dog walked 4 steps!
// dog walked 5 steps!
// dog walked 6 steps!
// dog walked 7 steps!
// dog walked 8 steps!
// dog walked 9 steps!
// dog walked 10 steps!


// -----------------------------------------------------------------------------------------------------------


// PARAMETER PASSING 

#include <iostream>
using namespace std;

// swap_values() function definition
// Interchanges the values located by variable1 and variable2.

// Notice that this function does not return anything!
void swap_values(int &variable1, int &variable2) {
    int temp;           // temporary storage for swap

    temp = variable1;
    variable1 = variable2;
    variable2 = temp;
}


int main( ) {
    int first_num, second_num;
    first_num = 7;
    second_num = 8;

    cout << "Two numbers before swap function: 1) " << first_num << " 2) " << second_num << endl;
    swap_values(first_num, second_num);
  
    cout << "The numbers after swap function: 1) " << first_num << " 2) " << second_num;

    return 0;
}


// Two numbers before swap function: 1) 7 2) 8
// The numbers after swap function: 1) 8 2) 7


// demonstrates the difference between pass-by-value
// and pass-by-reference functions.
#include <iostream>
using namespace std;

void func1(int var1, int var2){
    int temp;
    temp = var1;
    var1 = var2;
    var2 = temp;
}

void func2(int &var1, int &var2){
    int temp;
    temp = var1;
    var1 = var2;
    var2 = temp;
}

int main(){
    int num1 = 2;
    int num2 = 3;

    func1(num1, num2);
    cout << "results of func1:" << endl;
    cout << "num1: " << num1 << ", num2: " << num2 << endl;
  
    func2(num1, num2);
    cout << "results of func2:" << endl;
    cout << "num1: " << num1 << ", num2: " << num2 << endl;

    return 0;
}

// results of func1:
// num1: 2, num2: 3

// results of func2:
// num1: 3, num2: 2

/*
func1 is a pass-by-value value function, meaning that the values passed into the function are copies of the original variables.


func2 void func2(int &var1, int &var2), is a pass-by-reference function, meaning that the values passed into the function are the direct memory references of the original variables.

The "&" passes the location where the two variables are stored, resulting in the two variables switching memory references.

*/


// -----------------------------------------------------------------------------------------------------------

// FUNCTION OVERLOADING 

// demonstrates how function overloading works
// by changing the parameters on the inputs.
#include <iostream>
using namespace std;

void myfunct(int n) {
     cout << "1 parameter: " << n <<endl;
}


void myfunct(int n, int m) {
     cout << "2 parameters: " << n;
     cout << " and " << m <<endl;
}


int main() {

    myfunct(4);
    myfunct(5, 6);
    myfunct(100);

    return 0;
}


// 1 parameter: 4
// 2 parameters: 5 and 6
// 1 parameter: 100


/*
Helps keep consintency in the way your functions are named across your program.
Functions that do similar tasks differ based on parameters rather than by name.
A function in essence can fulfill multiple tasks depending on the parameters.
*/




