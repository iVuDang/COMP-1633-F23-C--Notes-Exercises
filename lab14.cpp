// LAB 14 - CLASSES

// 1. DATE_H
#ifndef DATE_H
#define DATE_H
#include <fstream>
using namespace std;

/*******************************************************************************
 *
 *  The "Date" class: represents a day/month/year on a calendar
 *
 *  PUBLIC METHOD SPECIFICATION:
 *
 *       set: sets the date object (returns false if date is invalid)
 *
 *       increment: increments the day by one.  Increments month and
 *                  year if necessary
 *
 *       getDay: returns the day component of the date
 *
 *       getMonth: returns the month component of the date
 *
 *       getYear: returns the year component of the date
 *
 *       getDayOfWeek: returns the day of the week for the given date
 *                        0=Sunday, 1=Monday, ..., 6=Saturday
 *
 *       print: outputs the date to the given output stream (e.g. cout)
 *              using the format: day/month/year
 *
 ******************************************************************************/


#include <iostream>
using namespace std;

class Date
{
public:
  bool set(int d, int m, int y);
  void increment();

  int getDay() const;
  int getMonth() const;
  int getYear() const;

  int getDayOfWeek() const;        // 0=Sunday, 1=Monday, ..., 6=Saturday

  void print(ostream &out) const;

private:

/*  ... internal representation omitted ... */
};


#endif

// 2. dTIME_H
#ifndef TIME_H
#define TIME_H
#include <fstream>
using namespace std;

/*******************************************************************************
 *  File name:  Time.h
 *
 *  The "Time" class: represents an hour:minute:second in a day, using the 24
 *  hour clock
 *
 *  PUBLIC METHOD SPECIFICATION:
 *
 *    setValue:
 *       Input:  three integers representing hours, minutes and seconds
 *       Action:  time is set according to the input arguments
 *       Assumptions:  input arguments are assumed legal
 *                     hours   in range 0 to 23
 *                     minutes in range 0 to 59
 *                     seconds in range 0 to 59
 *       NOTES:
 *       1. this operation must be called prior to any of the other member
 *          functions
 *
 *    increment:
 *       Input:  none
 *       Action:  time is advanced by 1 second
 *       Assumptions:  the time has been set using the set function
 *       NOTES:
 *       1. 23:59:59 wraps around to 0:0:0
 *
 *    print:
 *       Input:  an output stream
 *       Action:  time is outputted to the given output stream in the
 *                format HH:MM:SS
 *       Assumptions:  the time has been set using the set function
 *
 *    isEqual:
 *       Input:  a Time object
 *       Action:  returns true if this time is equal to the input time; false
 *                otherwise
 *       Assumptions:  both this time and the input time have been set using the
 *                     set function
 *
 *    isLess:
 *       Input:  a Time object
 *       Action:  returns true if this time is earlier in the day than the input
 *                 time; false otherwise
 *       Assumptions:
 *       1. both this time and the input time have been set using the set function
 *       2. this time and the input time represent times in the same day
 ******************************************************************************/

class Time
{
public:

   void setValue (int hours, int minutes, int seconds);
   void increment ();
   void print(ostream &out) const;
   bool isEqual (Time other) const;
   bool isLess (Time other) const;

private:

   int hrs;
   int mins;
   int secs;
};

#endif


// 3. 
#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

class Bank_Account
{

};


#endif


// 
#ifndef DATE_H
#define DATE_H
#include <fstream>
using namespace std;

/*******************************************************************************
 *
 *  The "Date" class: represents a day/month/year on a calendar
 *
 *  PUBLIC METHOD SPECIFICATION:
 *
 *       set: sets the date object (returns false if date is invalid)
 *
 *       increment: increments the day by one.  Increments month and
 *                  year if necessary
 *
 *       getDay: returns the day component of the date
 *
 *       getMonth: returns the month component of the date
 *
 *       getYear: returns the year component of the date
 *
 *       getDayOfWeek: returns the day of the week for the given date
 *                        0=Sunday, 1=Monday, ..., 6=Saturday
 *
 *       print: outputs the date to the given output stream (e.g. cout)
 *              using the format: day/month/year
 *
 ******************************************************************************/


#include <iostream>
using namespace std;

class Date
{
public:
  bool set(int d, int m, int y);
  void increment();

  int getDay() const;
  int getMonth() const;
  int getYear() const;

  int getDayOfWeek() const;        // 0=Sunday, 1=Monday, ..., 6=Saturday

  void print(ostream &out) const;

private:
  bool isLeapYear(int y) const;
  int daysInMonth(int m, int y) const;

  int day;
  int month;
  int year;
};


#endif

