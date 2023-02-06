#include <iostream>
using namespace std; 

/*
C++ array is always stored in contiguous memory. C++ arrays can be allocated in two different ways:

1. statically allocated in which the array size is fixed at compile-time and cannot change

double darray[4];
int iarray[10];
char arr2[3000];

2. dynamically allocated in which pointers are used in the allocation process so the size can change at run-time

int arr[] = {1, 2, 3, 4};  // This is size 4.
char arr2[] = {'a', 'b', 'c'}; // This is size 3.
string arr3[] = {"this", "is", "an", "array"}; // This is size 4.

*/

int main() {
  
  int myarray[] = {2,4,6,8};

  for (int i = 0; i < 4 ; i++){
    cout << myarray[i] << endl;
  }
  
  return 0;
}

/*
// OUTPUT:
2
4
6
8
*/


/*
// PYTHON 

def main():

    mylist = [2, 4, 6, 8]

    for i in range(8):
        print(mylist[i])

main()


// OUTPUT
2
4
6
8

*/