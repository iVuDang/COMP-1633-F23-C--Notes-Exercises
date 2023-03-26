// 1
#include <iostream>
#include "Time.h"
using namespace std;


int main()
{
    Time time1;
    Time time2;

    cout << "------- Time Class Exercise  -------" << endl;

    time1.setValue(10,12,2);
    time2.setValue(22,13,5);

    time1.print(cout);
    // insert your code for IF time1 != time2

    time2.print(cout); cout << endl;


    time2.setValue(10,12,2);
    time1.print(cout);
    // insert your code for IF time1 <= time2

    time2.print(cout); cout << endl;



    time2.setValue(7,6,5);
    time1.print(cout);
    // insert your code for IF time1 > time2

    time2.print(cout); cout << endl;

    time1.print(cout);
    // insert your code for IF time1 >= time2

    time2.print(cout); cout << endl;

        return 0;
}



// 2
#include <iostream>
#include "Bank_Account.h"
using namespace std;


int main()
{
    Bank_Account act1(123456, 100.75);
    Bank_Account act2(778899, 712.32);

    cout << "------- Bank_Account Class Exercise  -------" << endl;

    cout << "act 1 balance is " << act1.getBalance() << endl;

        act1.deposit(1000.50);
        act1.write(cout);

        act2.deposit(-100.00);
        act2.write(cout);

        act1.withdraw(-100);
        act1.write(cout);

        act2.withdraw(500.72);
        act1.write(cout);

        return 0;
}


// 3
#include <iostream>
#include "Bank_Account.h"
using namespace std;


int main()
{
    Bank_Account act1(123456, 100.75);
    Bank_Account act2(778899, 712.32);

    cout << "------- Bank_Account Class Exercise  -------" << endl;

    cout << "act 1 balance is " << act1.getBalance() << endl;

        act1.deposit(1000.50);
        act1.write(cout);

        act2.deposit(-100.00);
        act2.write(cout);

        act1.withdraw(-100);
        act1.write(cout);

        act2.withdraw(500.72);
        act1.write(cout);

        return 0;
}
[vdang159@ins.mtroyal.ca /users/library/comp1633/labs/lab15> ^C
[vdang159@ins.mtroyal.ca /users/library/comp1633/labs/lab15> cat ex4_client.cpp
#include <iostream>
#include "Date.h"


using namespace std;


void printCompareResult(RelatedType result);
void compare (Date d1,Date d2, const char expected[]);


//-------------------------------------------
int main()
{
    Date d;
    d.set(23,6,1981);

    cout << "Should print: 23" << endl;
    cout << "getDay: " << d.getDay() << endl << endl;


    cout << "Should print: 6" << endl;
    cout << "getMonth: " << d.getMonth() << endl << endl;

    cout << "Should print: 1981" << endl;
    cout << "getYear: " << d.getYear() << endl << endl;

    cout << "Should print: Tuesday June 23, 1981" << endl;
    d.print(cout); cout << endl << endl;

    d.increment();

    cout << "Should print: Wednesday June 24, 1981" << endl;
    d.print(cout); cout << endl << endl;

    cout << "Should print: Friday April 1, 2022" << endl;
    d.set(31,3,2022);
    d.increment();
    d.print(cout); cout << endl << endl;

    cout << "Should print: January 1, 2023" << endl;
    d.set(31,12,2022);
    d.increment();
    d.print(cout); cout << endl << endl;


    cout << "---------------------------------------------" << endl;
    cout << "Comparing Dates" << endl;


    Date d1,d2,d3,d4,d5;

    d1.set(23,6,1981); //June 23, 1981
    d2.set(23,6,1981); //June 23, 1981
    d3.set(23,6,1982); //June 23, 1982
    d4.set(23,5,1981); //May 23, 1981
    d5.set(22,6,1981); //June 22, 1981

    compare (d1,d2,"SAME AS");
    compare (d1,d3,"BEFORE");
    compare (d1,d4,"AFTER");
    compare (d1,d5,"AFTER");
}
//----------------------------------------------------
void printCompareResult(RelatedType result)
{
    switch(result)
    {
      case BEFORE: cout << " BEFORE "; break;
      case   SAME: cout << " SAME AS "; break;
      case  AFTER: cout << " AFTER "; break;
    }
}
//----------------------------------------------------
void compare (Date d1,Date d2, const char expected[])
{
    cout << "=========" << endl;
    cout << "Should be: " << expected << endl;
    cout << "First Date: "; d1.print(cout); cout << endl;

    cout << " is ";
    printCompareResult(  d1.comparedTo(d2) );
    cout << endl;

    cout << "Second Date: "; d2.print(cout);
    cout << endl;
    cout << "=========" << endl;

}

