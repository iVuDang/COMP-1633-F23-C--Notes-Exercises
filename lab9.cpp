// LAB 9 - STRUCT
#include <iostream>
#include <string>
using namespace std;

struct Time
{ int hour;         // valid hour (using 24-hour clock)
  int min;          // valid minutes (0 - 59)
};

struct Appointment
{
  // Step 5 - fill this in
};

void read_time(Time& t);
void write_time(Time t);
int compare_times (Time first, Time second);
void read_daily_appts (Appointment[], int& num_appts);

int main()
{
  // Step 2  - declare 2 Time variables
  // Step 5  - declare a variable for an appointment

  cout << "Enter 2 times (HH:MM), 1 per line" << endl;
  // Step 2 - call read_time twice to get times for the 2 variables you set up


  cout << "The 2 times are:" << endl;
  // Step 3 - fill in the stub for the function write_time
  // Step 4 - call write_time write times for the 2 variables you set up


  cout << "Enter a one word description, then start time (HH::MM)"
       << " and end time:" << endl;
  // Step 7 - call read_appt

  cout << "The details are:" << endl;
  // Step 9 - call write_appt to test

  // Step 10 - comment all declarations and code in main from top to here
  // Step 11 - declare an array of appointments
  //         - uncommenting the following call,
  //           and the function read_daily_appts (at the bottom)
  // read_daily_appts(my_day_appts, num_appts);

  return 0;
}


// initializes a time record based on input from cin (format HH:MM)
void read_time(Time& t)
{
  char colon; // to skip over colon in HH:MM

  cin >> t.hour >> colon >> t.min;
  return;
}


// write a time (using cout)
void write_time(Time t)
{
  // Step 3 - write the appropriate code here
}

// compares times - returns -1, 0, 1 if first time is < = > second
int compare_times (Time first, Time second)
{
  int answer;

  if (first.hour > second.hour)
    answer = 1;
  else if (first.hour < second.hour)
    answer = -1;
  else
  {
    if (first.min > second.min)
      answer = 1;
    else if (first.min < second.min)
      answer = -1;
    else
      answer = 0;
  }
  return answer;

}

// Step 6 - write function read_appt - reads in all the data
// for an appointment (call read_time). Have no prompts in the function
// remember prototype!!


// Step 8 - remove /* AND */ then fill in 4 things to complete the function
//          remember to add prototype
/*
void write_appt () // fill in parameter for the appointment
{
  cout << "Description: " << REPLACE THIS WITH CORRECT CODE << endl;
  cout << "Start time:  ";
  write_time (REPLACE THIS WITH CORRECT CODE );
  cout << endl <<  "End time:    ";
  write_time (REPLACE THIS WITH CORRECT CODE );
  cout << endl;

  return;
}
*/

/*
// reads in a number of appointments (use redirected input)
void read_daily_appts (Appointment day_appts[], int& num_appts)
{
  cin >> num_appts;
  cout << num_appts << endl;

  for (int i = 0; i < num_appts; i++) // assume array size will handle all
  {
    read_appt (day_appts[i]);
    write_appt (day_appts[i]);
    cout << " " <<endl;
  }

  return;
}
*/
