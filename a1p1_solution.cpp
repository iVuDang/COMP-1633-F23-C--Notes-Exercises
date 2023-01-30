// Name:       I.M.A. Student
// email:
// Course:     COMP 1633-00?
// Instructor:
// Assignment: 1 Part 1
// Due Date:   January 23, 2023
//
// Source File:  a1p1.cpp
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


#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void read_and_process (int account_number, double& total_purchases,
                       double& total_payments, bool& valid_account,
                       bool& valid_transactions);
void update_account (double open_balance, double credit_limit,
                     double total_purchases, double total_payments,
                     double& close_balance, double& interest_owed,
                     double& minimum_payment);
void print_statement (int account_number, double credit_limit, double open_balance,
                      double total_purchases, double total_payments,
                      double interest_due, double close_balance,
                      double minimum_payment);
bool is_valid_account (int account_number);
bool is_valid_length (int account_number);
bool has_valid_check_digit (int account_number);
int extract_digit (int number, int position);

int main ()
{
  int account_number;              // account number
  double open_balance;             // opening balance
  double credit_limit;             // credit limit for customer
  bool valid_account,              // account validation flag
    valid_transactions;            // transaction validation flag
  double total_payments;           // payments made on account
  double total_purchases;          // charges to account
  double minimum_payment;          // minimum payment
  double interest_due;             // interest accrued
  double close_balance;            // ending balance


  cin >> account_number >> open_balance >> credit_limit;

  read_and_process (account_number, total_payments, total_purchases,
                    valid_account, valid_transactions);

  if (valid_account && valid_transactions)
  {
    update_account (open_balance, credit_limit, total_purchases,
                    total_payments, close_balance, interest_due,
                    minimum_payment);
    print_statement (account_number, credit_limit, open_balance,
                     total_purchases, total_payments, interest_due,
                     close_balance, minimum_payment);
  }
  else
  {
    cout << "*** Account " << account_number
         << " - statement not printed due to errors ***" << endl << endl;
  }

  return 0;
}


//------------------------------------------------------------
// Function Name:  read_and_process
// Purpose: to read one customer's monthly transaction record
//
// Details:
//    A transaction record consists of three items the customer's total purchase
//    and total payments for the month and a letter indicating whether or not
//    these values are valid or not.
//    The transaction record is always read.
//    It is possible that an account can have either or both of these errors.
//
// Inputs: account_number - the customer's account number
//
// Output: total_purchases - sum of purchase transactions for the month
//         total_payments - sum of payment transactions for the month
//         errors - TRUE if any errors were encountered (if TRUE, then
//                  total_purchases and total_payments contain unreliable
//                  values)
//------------------------------------------------------------

void read_and_process (int account_number,
                       double& total_payments,
                       double& total_purchases,
                       bool& valid_account,
                       bool& valid_transactions)
{
  char transaction_error;

  valid_account = true;
  valid_transactions = true;

  cin >>  total_purchases >> total_payments >> transaction_error;

  if (!is_valid_account(account_number))
  {
    valid_account = false;
    cout << "Invalid account number " << endl;
  }

  if (transaction_error == 'B')
  {
    cout << "Bad monthly transaction record" << endl;
    valid_transactions = false;
  }


  return;
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
