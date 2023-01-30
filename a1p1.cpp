// Name: Vu Dang
// email: vdang159@mtroyal.ca
// Course:     COMP 1633-00?
// Professor: Munima Jahan
// Assignment: 1 Part 1
// Due Date:   January 23, 2023
//
// Source File:  a1p1.cpp

/*
an id block listing your name, your MRU email address, your course/section numbe                                                                                                             r, your
instructor’s name, the assignment number, source file name and the submission da                                                                                                             te;
• a purpose section which summarizes, from the user’s perspective, what the prog                                                                                                             ram does
(not how). This should be one, or at maximum two, sentence(s) that clearly state                                                                                                              what the
program does;
• a details section which specifies the relevant program details required by som                                                                                                             eone looking at
the program for the first time: i.e. input, output, and any processing details t                                                                                                             hat are not easily
understandable, i.e. formulae used, etc;
• a list of any limitations or assumptions about the input;
• a list of any known bugs or assignment requirements which have not been fulfil                                                                                                             led.
*/


#include <iostream>
#include <algorithm>

#include <iomanip>
using namespace std;

void print_statement (int account_number, double credit_limit,
                      double open_balance, double total_purchases,
                      double total_payments, double interest_due,
                      double close_balance, double minimum_payment);

/*
------------------------------------------------------------
Function Name:  is_valid_length
Purpose: to return a boolean 1 (true) if there is 7 digits, otherwise 0 (false).                                                                                                              To check if valid account.
Details: takes the account number as an integer, and evaluates whether there are                                                                                                              7 digits
Inputs: account_number - the customers account number e.g. 1234566
Outputs: boolean, 0 or 1 e.g. 1 for 1234566
------------------------------------------------------------
*/

bool is_valid_length(int account_number){

  bool testSevenDigits = false;

  if ((account_number / 1000000 < 10) && (account_number / 1000000 > 0)){
    testSevenDigits = true;
  }

  return testSevenDigits;
}



/*
------------------------------------------------------------
Function Name:  extract_digit
Purpose: to return 1 digit integer value given an integer account number and des                                                                                                             ired digit position. To check if valid account.
Details: digit position starts at 0 from left to right, given an integer and des                                                                                                             ired position.
Inputs: account_number - account number
        digitPosition - position of integer to retrieve
        e.g. (1234566, 6)
Outputs: integer, e.g. 6 for 123456'6'
------------------------------------------------------------
*/
int extract_digit(int account_number, int digitPosition){

  int digit = 0; // only declare variable type once, in if statements only refer                                                                                                              to name

  if (digitPosition == 0){
    digit = (account_number / 1000000) % 10; // 1 for '1'234566
  }

  else if (digitPosition == 1){
    digit = (account_number / 100000) % 10; // 2 for 1'2'34566
  }

  else if (digitPosition == 2){
    digit = (account_number / 10000) % 10; // 3 for 12'3'4566
  }

  else if (digitPosition == 3){
    digit = (account_number / 1000) % 10; // 4 for 123'4'566
  }

  else if (digitPosition == 4){
    digit = (account_number / 100) % 10; // 5 for 1234'5'66
  }

  else if (digitPosition == 5){
    digit = (account_number / 10) % 10; // 6 for 12345'6'6
  }

  else
    digit = (account_number % 10); // 6 for 123456'6'

  return digit;

}


/*
------------------------------------------------------------
Function Name:  sum_six_digits
Purpose: to sum the preceding six digits in a specific way and returns an intege                                                                                                             r. To check if valid account.
Details: The calculation for ex. is 1*6 + 2*5 + 3*4 + 4*3 + 5*2 + 6*1 = 56 for 1                                                                                                             234566
Inputs: account_number - the customers account number e.g. 1234566
Outputs: integer, the sum of the preceding six digits in a specific way e.g. 56.                                                                                                             
------------------------------------------------------------
*/
int sum_six_digits(int account_number){

  int digit0 = (account_number / 1000000) % 10; // 1 for '1'234566

  int digit1 = (account_number / 100000) % 10; // 2 for 1'2'34566

  int digit2 = (account_number / 10000) % 10; // 3 for 12'3'4566

  int digit3 = (account_number / 1000) % 10; // 4 for 123'4'566

  int digit4 = (account_number / 100) % 10; // 5 for 1234'5'66

  int digit5 = (account_number / 10) % 10; // 6 for 12345'6'6

  int sumSixDigits = (digit0 * 6) + (digit1 * 5) + (digit2 * 4) + (digit3 * 3) +                                                                                                              (digit4 * 2) + (digit5 * 1); // 1*6 + 2*5 + 3*4 + 4*3 + 5*2 + 6*1 = 56 for 1234                                                                                                             566

  return sumSixDigits;

}


/*
------------------------------------------------------------
Function Name:  last_digit_of_sum
Purpose: to return the last digit of the output from sum_six_digits function. To                                                                                                              check if valid account.
Inputs: result from sum_six_digits e.g. 56
Outputs: integer, the last digit e.g. 6 for 56.
------------------------------------------------------------
*/
int last_digit_of_sum(int account_number){

  int sum = sum_six_digits(account_number);
  int lastDigit = sum % 10; // 6 for 1234566

  return lastDigit;
}


/*
------------------------------------------------------------
Function Name: has_valid_check_digit
Purpose: to check if the last digit of sum is the same as the last digit of the                                                                                                              account number.
Inputs: account_number - the customers account number e.g. 1234566
Outputs: boolean, 0 or 1, e.g. 1 because 123456'6' == 5'6'
------------------------------------------------------------
*/
bool has_valid_check_digit(int account_number){
  int accLastDigit = extract_digit(account_number, 6);
  int sumLastDigit = last_digit_of_sum(account_number);

  bool equalLastDigit = (accLastDigit == sumLastDigit);

  return equalLastDigit;
}


/*
------------------------------------------------------------
Function Name: is_valid_account
Purpose: to return a boolean, true if both the length and the check digit are va                                                                                                             lid, otherwise false.
Inputs: results from functions is_valid_length, and has_valid_check_digit e.g. 1                                                                                                             234566
Outputs: boolean, 0 or 1 e.g. 1 for 1234566
------------------------------------------------------------
*/
bool is_valid_account(int account_number){
  bool validLength = is_valid_length(account_number) == 1;
  bool validCheckDigit = has_valid_check_digit(account_number) == 1;

  return validLength && validCheckDigit;
}


/*
------------------------------------------------------------
Function Name: read_and_process
Purpose: to return total purchases, total payments, and two boolean values.
Details: reads the monthly transaction record. The function will receive the acc                                                                                                             ount number. The account number will be validated and if found to be invalid, an                                                                                                              appropriate error message will be printed. Regardless of whether the account nu                                                                                                             mber is valid or not, the monthly transaction record will then be read. Also, re                                                                                                             gardless of whether or not the account number is valid, if the transaction error                                                                                                              item is a B, then an appropriate error message will be printed. The function wi                                                                                                             ll return the total purchases, the total payments and two Boolean values: a vali                                                                                                             d account flag and a valid transactions flag. Each should be set to true if the                                                                                                              respective item, account number or transaction record, is valid; otherwise the f                                                                                                             lag should be set to false.

Inputs:
int account_number - integer value, account number of customer
double& total_purchases - double value, total purchases made during month
double& total_payments - double value,total payments made during month

Outputs: the total purchases, the total payments and two Boolean values: a valid                                                                                                              account flag and a valid transactions flag
------------------------------------------------------------
*/

void read_and_process(int account_number, double& total_purchases, double& total                                                                                                             _payments, bool& transaction_flag, bool& account_flag){

  transaction_flag = true;
  account_flag = true;

  char transaction_error;

  cin >> total_purchases >> total_payments >> transaction_error; // reads the se                                                                                                             cond line by order

  bool valid_account = is_valid_account(account_number);

  if (valid_account == false)
  {
    cout << "Invalid account number" << endl;
    account_flag = false;
  }

  if (transaction_error == 'B'){
    cout << "Badly monthly transaction record" << endl;
    transaction_flag = false;
  }

  return;

}

double find_open_balance_minus_payments(double open_balance, double total_paymen                                                                                                             ts){

  double open_balance_minus_payments = open_balance - total_payments;

  return open_balance_minus_payments;
}


/*
------------------------------------------------------------
Function Name:  find_interest_owing
Purpose: to find interest owing for the month.
Detials: interest is charged on the starting balance minus total payments. If th                                                                                                             is amount is positive, the interest rate is 1.5%, otherwise no interest is charg                                                                                                             ed.

Inputs:
  double open_balance - opening balance owing on customers account
  double total_payments - payments made by customer for the month

Outputs: double, the closing balance of the account
------------------------------------------------------------
*/
double find_interest_owing(double open_balance, double total_payments){

  double open_balance_minus_payments = find_open_balance_minus_payments(open_bal                                                                                                             ance, total_payments);
  double interest_due = 0;

  if (open_balance_minus_payments > 0){
    interest_due = open_balance_minus_payments * 0.015;
  }
  else {
    interest_due = 0;
    }

  return interest_due;

}

/*
------------------------------------------------------------
Function Name:  find_new_balance
Purpose: to find the closing balance for the month.
Detials: the new balance is the starting balance minus total payments plus total                                                                                                              purchases plus interest.

Inputs:
  double open_balance - opening balance owing on customers account
  double total_payments - payments made by customer for the month
  double total_purchases - total purchases during the month

Outputs: double, the closing balance of the account
------------------------------------------------------------
*/
double find_new_balance(double open_balance, double total_purchases, double tota                                                                                                             l_payments){

  double open_balance_minus_payments = find_open_balance_minus_payments(open_bal                                                                                                             ance, total_payments);
  double interest_due = find_interest_owing(open_balance, total_payments);

  double close_balance = open_balance_minus_payments + total_purchases + interes                                                                                                             t_due;

  return close_balance;

}


/*
------------------------------------------------------------
Function Name:  find_minimum_payment
Purpose: receives an opening balance, credit limit, total purchases and total pa                                                                                                             yments. The function calculates and returns the interest owed, new balance and m                                                                                                             inimum payment due
Details: the minimum payment due is calculated using the new balance as follows:                                                                                                             

  zero, if the new balance is less than $10

  10% of the new balance or $10.00 whichever is greater, if the new balance is s                                                                                                             till within the credit limit

  the minimum payment as calculated above plus the amount by which the credit li                                                                                                             mit has been exceeded, if the new balance is over the credit limit

Inputs:
  double open_balance - opening balance owing on customers account
  double total_payments - payments made by customer for the month
  double total_purchases - total purchases during the month
  double credit_limit - credit limit of the account

Outputs: double, the minimum payment required for that month
------------------------------------------------------------
*/
double find_minimum_payment(double open_balance, double credit_limit, double tot                                                                                                             al_purchases, double total_payments){

  double close_balance = find_new_balance(open_balance, total_purchases, total_p                                                                                                             ayments);
  double greater_of_interest = 10 > (0.1 * close_balance) ? 10 : (0.1 * close_ba                                                                                                             lance);

  double credit_limit_excess = 0;
  double minimum_payment = 0;

  if (close_balance > credit_limit) {
    credit_limit_excess = close_balance - credit_limit;
      } else {
    credit_limit_excess = 0;
      }

  if (close_balance < 10){
    minimum_payment = 0;
  } else {
    minimum_payment =  greater_of_interest + credit_limit_excess;
  }

  return minimum_payment;

}

void update_account(double open_balance, double credit_limit, double total_purch                                                                                                             ases, double total_payments, double& interest_due, double& new_balance, double&                                                                                                              minimum_payment){

    interest_due = find_interest_owing(open_balance, total_payments);

    new_balance = find_new_balance(open_balance, total_purchases, total_payments                                                                                                             );

    minimum_payment = find_minimum_payment(open_balance, credit_limit, total_pur                                                                                                             chases, total_payments);

    return;
}




int main(){
     int account_number;

     double credit_limit, open_balance, total_purchases, total_payments, interes                                                                                                             t_due, close_balance, minimum_payment;

     bool transaction_flag, account_flag;

     cin >> account_number >> open_balance >> credit_limit;

     read_and_process(account_number, total_purchases, total_payments, transacti                                                                                                             on_flag, account_flag);

     if (transaction_flag && account_flag){
     update_account(open_balance, credit_limit,
                    total_purchases, total_payments,
                    interest_due, close_balance, minimum_payment);

     print_statement(account_number, credit_limit,
                         open_balance, total_purchases,
                         total_payments, interest_due,
                         close_balance, minimum_payment);
     } else {
     cout << "*** Account " << account_number << " - statement not printed due t                                                                                                             o errors *** " << endl;
     }

    return 0;
}


//------------------------------------------------------------
// Function Name:  print_statement
// Purpose: to print a month-end credit card statement
//
// Details:
//    All quantities are printed as dollar amounts with
//    exactly 2 digits after the decimal point.
//
//    The bill consists of 8 lines of output. Each line starts with a
//    title, whose field width is 20 characters. Titles are left justified.
//    The item on the first line following the title is the customer's
//    account number. It is left justified and follows the title field
//    immediately.
//    On the remaining 7 lines the item following the title is a dollar
//    value. All dollar values are right justified and in a field of
//    width 8.
//
// Inputs: credit_limit - the customer's credit limit
//         open_balance - amount owing at beginning of month
//         total_purchases - sum of purchase transactions for the month
//         total_payments - sum of payment transactions for the month
//         interest_due - interest on overdue balance
//         close_balance - amount owing at end of month
//         minimum_payment - minimum amount to be paid by customer
//
//------------------------------------------------------------

void print_statement (int account_number,
                      double credit_limit,
                      double open_balance,
                      double total_purchases,
                      double total_payments,
                      double interest_due,
                      double close_balance,
                      double minimum_payment)
{
  const int TITLE_FIELD_WIDTH = 20;
  const int VALUE_FIELD_WIDTH = 8;
  const int DECIMAL_PLACES = 2;

  cout << endl;
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(DECIMAL_PLACES);

  cout << endl;
  cout << left << setw(TITLE_FIELD_WIDTH) << "Account Number:"
       << account_number << endl;
  cout << left << setw(TITLE_FIELD_WIDTH) << "Credit Limit:"
       << right << setw(VALUE_FIELD_WIDTH) <<  credit_limit << endl;
  cout << left << setw(TITLE_FIELD_WIDTH) << "Starting Balance:"
       << right << setw(VALUE_FIELD_WIDTH) <<  open_balance << endl;
  cout << left << setw(TITLE_FIELD_WIDTH) << "Total Purchases:"
       << right << setw(VALUE_FIELD_WIDTH) <<  total_purchases << endl;
  cout << left << setw(TITLE_FIELD_WIDTH) << "Total Payments:"
       << right << setw(VALUE_FIELD_WIDTH) <<  total_payments << endl;
  cout << left << setw(TITLE_FIELD_WIDTH) << "Interest:"
       << right << setw(VALUE_FIELD_WIDTH) <<  interest_due << endl;
  cout << left << setw(TITLE_FIELD_WIDTH) << "Month End Balance:"
       << right << setw(VALUE_FIELD_WIDTH) <<  close_balance << endl;
  cout << left << setw(TITLE_FIELD_WIDTH) << "Minimum Payment:"
       << right << setw(VALUE_FIELD_WIDTH) <<  minimum_payment << endl;

  cout.unsetf(ios::left);
  cout.unsetf(ios::right);
  return;
}

/*
// For input:
1234566 623.45 2000.00
402.10 100.00 G


// The given function will generate the following output:
Account Number: 1234566
Credit Limit:   2000.00
Starting Balance:       623.45
Total Purchases:        402.10
Total Payments: 100.00
Interest:       7.85
Month End Balance:      933.40
Minimum Payment:        93.34


// For input:

6543211 0.0 1000.00
200.00 0 B

The output generated will be:

Bad monthly transaction record
*** Account 6543211 - statement not printed due to errors ***


// For input:

1234567 0.0 1000.00
200.00 0 B

The output generated will be:

Invalid account number
Bad monthly transaction record
*** Account 1234567 - statement not printed due to errors ***

The above invalid account number error message would be use if only an invalid a                                                                                                             ccount number error occurs.




// Rules
You are allowed to use decisions (the if-else statement).

You are NOT allowed to use repetition (loops) as these have not been covered.

Your account_number must be an integer type variable.

You can use the <cmath> library but make sure you are following the requirements                                                                                                              and restrictions mentioned in the specification.

Two data files have been placed in the a1 directory in the INS class directory,                                                                                                              called test1.dat and test2.dat. To see the expected results you can use them in                                                                                                              the given working program (a1p1.exe).

The specs clearly state the account number can NOT have any leading zeros. So do                                                                                                             n't try to use an account number with leading zeros. (Also, because the account                                                                                                              number is an integer any leading zeros will be ignored.)

Digit positions in numbers ALWAYS start with position 0 on the right hand side,                                                                                                              i.e. the units digit is in position 0.

In this course, global variables are not allowed. Constants (using const) may be                                                                                                              declared globally or locally. Global constants
are encouraged e.g. GST used in several functions.

the standards in this course allow at most one return statement for each functio                                                                                                             n. (Often text books give simple examples with 2 returns but this is not
allowed!)



// Test 1
3211232 100.00 2000.00
50.00 100.00 G

// Test 2
9182734 1500.00 5000.00
1500.00 500.00 G



// Test 3
For input:

6543211 0.0 1000.00
200.00 0 B

The output generated will be:

Bad monthly transaction record
*** Account 6543211 - statement not printed due to errors ***



// Test 4

1234567 0.0 1000.00
200.00 0 B

The output generated will be:

Invalid account number
Bad monthly transaction record
*** Account 1234567 - statement not printed due to errors ***


*/


/*
CITATIONS
Received help from John for read_and_ process function.
Received help for length function from Zach.

CITATIONS
https://stackoverflow.com/questions/4261589/how-do-i-split-an-int-into-its-digit                                                                                                             s

5 is 12345 % 10
4 is 12345 / 10 % 10
3 is 12345 / 100 % 10
2 is 12345 / 1000 % 10
1 is 12345 / 10000 % 10



// To extract the digit 4
int digit = (account_number / 1000) % 10

1234566 / 1000 = 1234.566

1234.566 % 10 = 4.566 (in C++, when stated int, this would just round to 4)
123 × 10 + 4.566 = 1234.566



// To extract the digit 6
int digit = (account_number % 10)

123456 × 10 + 6 = 1234566

*/
