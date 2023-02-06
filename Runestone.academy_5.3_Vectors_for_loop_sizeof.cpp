#include <iostream>
#include <vector>
using namespace std; 


int main() {
  
    int nums[] = {1,3,6,2,5};
  
    // Divide the size of the array (in bytes) by the size of a single element (in bytes)
    // to get the total number of elements in the array.
  
    int numsSize = sizeof(nums) / sizeof(nums[0]); // Get size of the nums array

    for (int index = 0; index < numsSize; index++) {
        cout << nums[index] << endl;
    }

   // Simpler Implementation that may only work in
   // Newer versions of C++

   // for (int item:nums) {
   //     cout << item << endl;
   // }

     return 0;
}

/*
// OUTPUT:
1
3
6
2
5
*/


/*

https://runestone.academy/ns/books/published/cpp4python/CollectionData/Vectors.html


*/