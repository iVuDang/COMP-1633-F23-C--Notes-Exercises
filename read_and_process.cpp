#include <iostream>
#include <string>
using namespace std; 


int account_number;
double credit_limit;
double open_balance;
double total_purchases;
double total_payments;
double interest_due;
double close_balance;
double minimum_payment;

read_and_process() {
    string line1, line2;

    ifstream myfile("test1.dat");
    if (myfile.is_open()) {
        getline(myfile, line1);
        getline(myfile, line2);
        myfile.close();
    }
    else cout << "Unable to open file"; 

    // use line1 and line2 as parameters
    // ...

    return 0;
}


