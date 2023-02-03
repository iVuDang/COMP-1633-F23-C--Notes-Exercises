#include <iostream>
using namespace std; 


/* 
Write the pseudo-code of an algorithm that calculates the amount your bank account will have in 3 years assuming that you do not take any money out or put any money in other than the annual interest. The current amount is $100, the annual interest rate is 3%.

In:

Data: current_balance, interest_rate
*/

int main() {

  double interest;
  
  double const INT_RATE = 0.03;
  double balance = 100;

  // 1st year
  interest = balance * INT_RATE;
  balance = balance + interest; 

  // 2nd year
  interest = balance * INT_RATE; 
  balance = balance + interest; 

  // 3rd year 
  interest = balance * INT_RATE; 
  balance = balance + interest; 

  cout << "Balance of 100 with 3% interest after 3 years: " << balance << endl; 

  return 0;

}



// SOLUTION 2
#include <iostream>
using namespace std; 


/* 
Write the pseudo-code of an algorithm that calculates the amount your bank account will have in 3 years assuming that you do not take any money out or put any money in other than the annual interest. The current amount is $100, the annual interest rate is 3%.

In:

Data: current_balance, interest_rate
*/

int main() {

  double interest; 
  double balance = 100;
  int count = 0; 

  while (count < 3){
    interest = balance * 0.03; 
    balance = balance + interest; 
    count = count + 1; 
  }

  cout << "Balance of 100 with 3% interest after 3 years: " << balance << endl; 

  return 0;

}