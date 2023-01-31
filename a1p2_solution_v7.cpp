// Name:       Vu Dang
// email:      vdang159@mtroyal.ca
// Course:     COMP 1633-001
// Instructor: Munima Jahan
// Assignment: 1 Part 2
// Due Date:   January 30, 2023
//
// Source File:  a1p1_solution.cpp
//
// Purpose:  This program generates a month-end statement for a store's credit
//           card for a single customer account
//
// Details:
//
//   Input:  The customer's information is stored in a file and consists of
//           two records (lines). The first is a header record with the format
//           of:
//              account_number  starting_balance  credit_limit
//           The second is a transaction record with the format of:
//              monthly_purchases monthly_payment error
//
//   Output: The program will generate a month-end statment for the
//           customer whether or not the account informatio is valid.
//
//           The month-end statement will consist of the customer's account
//           number, credit limit, starting balance, total purchases, total
//           payments, interest charges, ending balance and minimum payment.
//
// Assumptions & Limitations:
//    The items in the data file are all numeric values. All money amounts
//    are real values that should be positive with the exception of the
//    starting balance which could be negative indicating the customer has
//    a credit due to an overpayment. The account number and error are integer
//    values.
//    The program will generate erroneous results if non-numeric values are input.

//------------------------------------------------------------------------------
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;


bool is_valid_account (int account_number);
bool is_valid_length (int account_number);
bool has_valid_check_digit (int account_number);
int extract_digit (int number, int position);


void update_account (double open_balance, double credit_limit,
                     double total_purchases, double total_payments,
                     double& close_balance, double& interest_owed,
                     double& minimum_payment);
void print_statement (int account_number, double credit_limit, double open_balance,
                      double total_purchases, double total_payments,
                      double interest_due, double close_balance,
                      double minimum_payment);

void read_and_total (int transaction_account_number,
                    char transaction_code,
                    double transaction_amount,
                    double& total_purchases, // pass by ref
                    double& total_payments, // pass by ref
                    int& line_number, // pass by ref
                    int og_account_number,
                    int& error_count, // pass by ref
                    bool& account_validity); // pass by ref

void read_and_process (int transaction_account_number,
                      char transaction_code,
                      double transaction_amount,
                      double& total_purchases, // pass by ref.
                      double& total_payments, // pass by ref.
                      int& line_number, // pass by ref.
                      int og_account_number,
                      int& error_count, // pass by ref.
                      bool& account_validity);

void read_and_ignore(int transaction_account_number,
                    char transaction_code,
                    double transaction_amount,
                    int& line_number);

int main ()
{
  int transaction_account_number;              // account number
  int og_account_number;

  double open_balance;             // opening balance
  double credit_limit;             // credit limit for customer
  double total_payments;           // payments made on account
  double total_purchases;          // charges to account
  double minimum_payment;          // minimum payment
  double interest_due;             // interest accrued
  double close_balance;            // ending balance

  int line_number = 0;
  int error_count = 0;
  int account_count = 0;

  bool account_validity;
  char transaction_code;
  double transaction_amount;


  cin >> og_account_number >> open_balance >> credit_limit;
  account_count++;
  line_number++;

  while(!cin.eof()){
    read_and_process (transaction_account_number,
                      transaction_code,
                      transaction_amount,
                      total_purchases, // pass by ref.
                      total_payments, // pass by ref.
                      line_number, // pass by ref.
                      og_account_number,
                      error_count, // pass by ref.
                      account_validity);
      if (account_validity == true) {
        update_account (open_balance,
                      credit_limit,
                      total_purchases,
                      total_payments,
                      close_balance,
                      interest_due,
                      minimum_payment);

        print_statement (og_account_number,
                        credit_limit,
                        open_balance,
                        total_purchases,
                        total_payments,
                        interest_due,
                        close_balance,
                        minimum_payment);
      }
      cin >> og_account_number >> open_balance >> credit_limit;
    account_count++;
    line_number++;
    }
  cout << endl;
  cout << endl;
  return 0;
}


//------------------------------------------------------------
// Function Name:  update_account
// Purpose: to compute dollar amounts for one customer's
//          month-end credit card statement
//
// Details:
// 1. Interest is calculated at a rate of 1.5% on the opening balance
//    less any payments for the month.
// 2. The minimum payment is based on the closing balance.  If
//    the customer still owes money, the minimum payment is calulated
//    at a rate of 10% or $10.00, whichever is greater
//
//
// Inputs: open_balance - amount owing at beginning of month
//         creditLImit - maximum borrowing limit
//         total_purchases - sum of purchase transactions for the month
//         total_payments - sum of payment transactions for the month
// Output: close_balance - amount owing at end of month
//         interest_due - interest on overdue balance
//         minimum_payment - minimum amount to be paid by customer
//
//------------------------------------------------------------

void  update_account (double open_balance,
                      double credit_limit,
                      double total_purchases,
                      double total_payments,
                      double& close_balance,
                      double& interest_due,
                      double& minimum_payment)
{
  const double interestRate = 1.5;
  const double PERCENT = 100.0;
  const double payRate = 10.0;
  const double minimumAmount = 10.0;

  double owing;                   // total owing
  double possibleMinimum_payment; // temporary for calculation of minimum
                                  // payment

  owing = open_balance - total_payments;
  if (owing > 0)
  {
    interest_due = interestRate / PERCENT * owing;
  }
  else
  {
    interest_due = 0.0;
  }
  close_balance = open_balance - total_payments + total_purchases
    + interest_due;
  if (close_balance < 10)
  {
    minimum_payment = 0;
  }
  else
  {
    possibleMinimum_payment = payRate / PERCENT * close_balance;
    if (possibleMinimum_payment > minimumAmount)
    {
      minimum_payment = possibleMinimum_payment;
    }
    else
    {
      minimum_payment = minimumAmount;
    }

    if (close_balance > credit_limit)
    {
      minimum_payment = minimum_payment + (close_balance - credit_limit);
    }
  }
  return;
}

//------------------------------------------------------------
// Function Name:  print_statement
// Purpose: to print a month-end credit card statement
//
// Details:
//    Since all quantities printed are dollar amounts,
//    the proper format must be used:  exactly 2 digits after
//    the decimal point
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

// REMOVE THIS cout statement
//  cout << endl;
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

// ADD THESE TWO cout statements
  cout << endl;
  cout << endl;

  cout.unsetf(ios::left);
  cout.unsetf(ios::right);
  return;
}

//------------------------------------------------------------
// Function Name:  is_valid_account
// Purpose: to determine whether an account number, is valid
//          or not
//
// Inputs: acct - an integer representing an account number
//                to be validated
//
// Return:  returns TRUE if acct is valid, FALSE otherwise
//
// Details
// A valid number must meet the following criteria:
//      - exactly 7 digits in length
//      - the sum the left-most 6 digits of the account # times
//        the digit's position
//      - the units (right-most) digit of the account # must equal
//        the units digit of the sum
//
//------------------------------------------------------------


bool is_valid_account (int account_number)
{
  bool valid = true;

  valid = is_valid_length(account_number);
  if (valid)
  {
    valid = has_valid_check_digit(account_number);
  }

  return valid;
}

bool is_valid_length (int account_number)
{
  bool good_length = true;

  if (account_number < 1000000 || account_number > 9999999)
  {
    good_length = false;
  }

  return good_length;
}

bool has_valid_check_digit (int account_number)
{
  int position, digit, digit0;
  int sum;
  int check_digit;
  bool valid = true;

  digit0 = account_number % 10;

  position = 1;
  sum = 0;

  digit = extract_digit(account_number, position);
  sum = sum + digit * position;

  position = position + 1;
  digit = extract_digit(account_number, position);
  sum = sum + digit * position;

  position = position + 1;
  digit = extract_digit(account_number, position);
  sum = sum + digit * position;

  position = position + 1;
  digit = extract_digit(account_number, position);
  sum = sum + digit * position;

  position = position + 1;
  digit = extract_digit(account_number, position);
  sum = sum + digit * position;

  position = position + 1;
  digit = extract_digit(account_number, position);
  sum = sum + digit * position;

  check_digit = sum % 10;
  if (digit0 != check_digit)
  {
    valid = false;
  }

  return valid;
}

int extract_digit (int number, int position)
{
  int digit;

  digit = number / static_cast <int> (pow (10,position)) % 10;

  return digit;
}



//------------------------------------------------------------ NEW CODE ADDED ------------------------------------------------------------


/*
------------------------------------------------------------
2. & 3. Write a function read_and_total
Function Name:  read_and_total
Purpose: pass back the sum of all purchases and payments

Details:
Read a series of transaction records until the sentinel record is encountered. It will pass back the sum of all purchases and payments
Once read_and_total correctly processes a series of valid transaction records, modify it to handle each of the possible transaction record errors.
Do this one error at a time. Upon detecting an error, an appropriate message should be output.
There should be no need to change the is_valid_account function.
In the event of an invalid account in a header record, the transaction records for this customer need to be read and ignored. This should be done by a function called read_and_ignore. (Again when first creating this function, you can ignore line numbers.)


Inputs: int transaction_account_number // account number in transaction records
        char transaction_code // the S or M for code in transaction records
        double transaction_amount // transaction amount in transaction records
        double& total_payments, // pass by reference for total payments made in month
        bool& total_purchases, // pass by reference for total purchases made in month
        int& line_number, // pass by reference for line number where current code is
        int og_account_number // account number in the header
        int& error_count, // pass by reference for how many errors accumulated so far
        bool& account_validity) { // pass by value whether the account is valid or not

Output:
The sum of transaction amounts with 'S' or with  'M'.
The error messages produced should look something like:
Error in line #3 - non-matching account number 8234566
Error in line #3 - invalid transaction code ‘Q’
Error in line #4 - invalid transaction amount -99.99
Error in line #5 - invalid transaction code ‘A’


------------------------------------------------------------
*/
//------------------------------------------------------------------------------
void read_and_total (int transaction_account_number,
                    char transaction_code,
                    double transaction_amount,
                    double& total_purchases, // pass by value
                    double& total_payments, // pass by value
                    int& line_number, // pass by value
                    int og_account_number,
                    int& error_count, // pass by value
                    bool& account_validity) { // pass by value

  const int SENTINEL_1 = -1;
  const double SENTINEL_3 = -1;
  const char SENTINEL_2 = 'X';

  cin >> transaction_account_number 
        >> transaction_code 
        >> transaction_amount;
  line_number++; // counts the line of header

  while((transaction_account_number != SENTINEL_1) 
        && (transaction_code != SENTINEL_2) 
        && (transaction_amount != SENTINEL_3)){

    // account number header agrees to records?
    if (transaction_account_number != og_account_number) {
      cout << "Error in line #" 
      << line_number 
      << " - non-matching account number " 
      << transaction_account_number 
      << endl;
      error_count++;
      account_validity = false;
    }

    // transaction codes are either 'S' or 'M?
    if (transaction_code == 'S') {
      total_purchases += transaction_amount;
      }
    else if(transaction_code == 'M'){
      total_payments += transaction_amount;
    } else {
      cout << "Error in line #"
      << line_number 
      << " - invalid transaction code ‘" 
      << transaction_code 
      << "’" << endl;
      error_count++;
      account_validity = false;
    }

    // transaction amounts are positive?
    if (transaction_amount < 0) {
      cout << "Error in line #"<< line_number 
      << " - invalid transaction amount -" 
      << transaction_amount 
      << endl;
      error_count++;
      account_validity = false;
    } // ends if

    cin >> transaction_account_number 
    >> transaction_code 
    >> transaction_amount;
    line_number++;
  } // ends while loop

  return;
} // ends read_and_total function



/*
------------------------------------------------------------
4. Write a function called read_and_ignore
Function Name:  read_and_ignore
Purpose: if account is invalid, read and ignore transaction records.

Details:
In the event of an invalid account number the corresponding transaction records need to be read and ignored (since this is an invalid account, no error checking of the transaction records is required).

Inputs:
      int transaction_account_number // account number in transaction records
      char transaction_code // the S or M for code in transaction records
      double transaction_amount // transaction amount in transaction records
      int& line_number, // pass by reference for line number where current code is

Output: n/a - read and ignore transaction records. To count the line number if there is an invalid account.

------------------------------------------------------------
*/
//------------------------------------------------------------------------------

void read_and_ignore(int transaction_account_number,
                    char transaction_code,
                    double transaction_amount,
                    int& line_number) {

  const int SENTINEL_1 = -1;
  const double SENTINEL_3 = -1;
  const char SENTINEL_2 = 'X';

  while((transaction_account_number != SENTINEL_1) 
  && (transaction_code != SENTINEL_2) 
  && (transaction_amount != SENTINEL_3)) {
    cin >> transaction_account_number 
    >> transaction_code 
    >> transaction_amount;
    line_number++;
  }
  return;
}



/*
------------------------------------------------------------
1. Modify the read_and_process function

Function Name:  read_and_process
Purpose:

Details:
a) to process transaction records generating total payments and total purchases,
b) to handle errors in the transaction records and
c) to read and ignore all transaction records in the event of an invalid customer account number.

We will use a helper function (read_and_total function) - to do a) and b) for us.


Inputs: int transaction_account_number // account number in transaction records
        char transaction_code // the S or M for code in transaction records
        double transaction_amount // transaction amount in transaction records
        double& total_payments, // pass by reference for total payments made in month
        bool& total_purchases, // pass by reference for total purchases made in month
        int& line_number, // pass by reference for line number where current code is
        int og_account_number // account number in the header
        int& error_count, // pass by reference for how many errors accumulated so far
        bool& account_validity) { // pass by value whether the account is valid or not


Output:
If the account number is valid then the transaction records need to be totaled
In the event of an invalid account number in the header record, the following error message should be output:

Error in line #number - invalid account number account_number


------------------------------------------------------------
*/


void read_and_process (int transaction_account_number,
                      char transaction_code,
                      double transaction_amount,
                      double& total_purchases, // pass by ref.
                      double& total_payments, // pass by ref.
                      int& line_number, // pass by ref.
                      int og_account_number,
                      int& error_count, // pass by ref.
                      bool& account_validity) { // pass by ref.

  account_validity = true;

  if (is_valid_account(og_account_number)){
      read_and_total (transaction_account_number,
                    transaction_code,
                    transaction_amount,
                    total_purchases, // pass by value
                    total_payments, // pass by value
                    line_number, // pass by value
                    og_account_number,
                    error_count, // pass by value
                    account_validity);
  } else {
    cout << "Error in line #" 
    << line_number 
    << " - invalid account number " 
    << transaction_account_number 
    << endl;
    error_count++;
    account_validity = false;
    read_and_ignore(transaction_account_number,
                    transaction_code,
                    transaction_amount,
                    line_number);
  }

  return;
}



/*
CITATIONS:

Help from John, Johnny, Marusa


https://stackoverflow.com/questions/13148692/c-linked-list-reading-data-from-a-file-with-a-sentinel

https://stackoverflow.com/questions/16568149/while-loop-with-multiple-conditions-in-c

*/
