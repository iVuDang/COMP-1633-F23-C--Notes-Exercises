// C++ program to demonstrate the
// use of an array within a structure
 
#include <iostream>
using namespace std;
 
// Declaration of the structure candidate
struct candidate {
    int roll_no;
    char grade;
 
    // Array within the structure
    float marks[4];
};
 
// Function to displays the content of
// the structure variables
void display(struct candidate a1)
{
 
    cout << "Roll number : " << a1.roll_no << endl;
    cout <<"Grade : " << a1.grade << endl;
    cout << "Marks secured:\n";
    int i;
    int len = sizeof(a1.marks) / sizeof(float);
 
    // Accessing the contents of the
    // array within the structure
    for (i = 0; i < len; i++) {
        cout << "Subject " << i + 1 << " : " << a1.marks[i] << endl;
      }
}
 
// Driver Code
int main()
{
    // Initialize a structure
    struct candidate A
        = { 1, 'A', { 98.5, 77, 89, 78.5 } };
 
    // Function to display structure
    display(A);
    return 0;
}
 
// This code is contributed by sarajadhav12052009

// Roll number : 1
// Grade : A
// Marks secured:
// Subject 1 : 98.50
// Subject 2 : 77.00
// Subject 3 : 89.00
// Subject 4 : 78.50

// https://www.geeksforgeeks.org/array-of-structures-vs-array-within-a-structure-in-c-and-cpp/