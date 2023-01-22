// Name:
// email:
// Course:     COMP 1633-00?
// Professor:
// Assignment: 1 Part 1
// Due Date:   January 23, 2023
//
// Source File:  a1p1.cpp


#include <iostream>
//#include <iomanip>
using namespace std;

void print_statement (int account_number, double credit_limit,
                      double open_balance, double total_purchases,
                      double total_payments, double interest_due,
                      double close_balance, double minimum_payment);


int main(){
    int a;
    double c, op,  t, to,  in, cl,  min;
    print_statement(a,c,op,t,to,in,cl,min);
    return 0;
}

/*
  This comment should be removed after these instructions are followed.
  The following items should be added between the print_statement prototype
  and the print_statement function definition:
       all function prototypes
       the main function
       all function definitions
*/




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
Account Number:	1234566
Credit Limit:	2000.00
Starting Balance:	623.45
Total Purchases:	402.10
Total Payments:	100.00
Interest:	7.85
Month End Balance:	933.40
Minimum Payment:	93.34


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

The above invalid account number error message would be use if only an invalid account number error occurs.




// Rules 
You are allowed to use decisions (the if-else statement). 

You are NOT allowed to use repetition (loops) as these have not been covered.

Your account_number must be an integer type variable.

You are NOT allowed to use string or array.

You can use the <cmath> library but make sure you are following the requirements and restrictions mentioned in the specification. 

Two data files have been placed in the a1 directory in the INS class directory, called test1.dat and test2.dat. To see the expected results you can use them in the given working program (a1p1.exe).
*/