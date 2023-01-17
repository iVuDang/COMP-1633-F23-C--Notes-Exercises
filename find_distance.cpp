// Lab 3 - Find distance traveled given rate and time
#include <iostream>
using namespace std;

int main() {
    int travel_rate, travel_time;
    cout << "Please enter rate of travel (km/h): " << endl;
    cin >> travel_rate;
    cout << "Please enter travel time(h): " << endl;
    cin >> travel_time;
    cout << "The total distance travelled is " << travel_rate*travel_time << "km" << endl;

    return 0;

}
