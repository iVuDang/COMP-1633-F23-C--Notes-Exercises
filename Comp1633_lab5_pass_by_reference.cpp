#include <iostream>
using namespace std; 

int main()
{
    int startMin, startHour, waitMin, waitHour, endHour, endMin;
    char amPm;

    cout << "Enter the start time" << endl;
    get_time (startHour, startMin);
    cout << "Start time entered is " << startHour << ':' << startMin << endl;

    cout << "Enter the waiting time" << endl;
    get_time (waitHour, waitMin);
    cout << "Wait time entered is " << waitHour << ':' << waitMin << endl;

    calc_end_time (startHour, startMin, waitHour, waitMin, endHour, endMin);
    cout << "finish time " << endHour << ':' << endMin << endl;

    convert_12hour (endHour, endMin, amPm);
    cout << "in am and pm" << endHour << ':' << endMin << ' ' << amPm << 'M' <<                                                                                                              endl;

    return 0;
}



void get_time (int& hour, int& min)
{
    char colon;
    cin >> hour >> colon >> min;
 }


void calc_end_time (int hour, int min, int waitHour, int waitMin, int& endHour,                                                                                                              int& endMin)
{
    endMin = (min + waitMin)%60;
    endHour = (hour + waitHour + (min + waitMin)/60) % 24;
}


void convert_12hour (int& hour, int& min, char &amOrPm)
{
    if (hour < 12)
        amOrPm = 'A';
    else
    {
        hour = hour -12;
        amOrPm = 'P';
    }

}
