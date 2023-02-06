#include <iostream>
#include <vector>
using namespace std;

int main(){

    vector<int> intvector;
    intvector.reserve(50);   // sets up the vector for 50 slots 

    for (int i = 0; i < 50; i++){
        intvector.push_back(i*i);
        cout << intvector[i] << endl;
    }
  
    return 0;
}

/*
// OUTPUT:
0
1
4
9
16
25
36
49
64
81
100
*/

/*
// PYTHON
"""Uses a list to square every
number from 0 to 49 """

def main():

    intlist=[]

    for i in range(50):
        intlist.append(i*i)
        print(intlist[i])

main()


// OUTPUT
0
1
4
9
16
25
36
49
64
81
100


// CITUATIONS
https://runestone.academy/ns/books/published/cpp4python/CollectionData/Vectors.html
*/