// Creates a hash table that matches
// the english letter to it's spanish
// equivalent, and outputs the size of
// the table to the console
// https://runestone.academy/ns/books/published/cpp4python/CollectionData/HashTables.html
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

// In C++, the keyword first is used for the key, and second is used for the associated value.

int main() {
    unordered_map<string, string> spnumbers;

    spnumbers = { {"one", "uno"}, {"two", "dos"} };

    spnumbers["three"] = "tres";
    spnumbers["four"] = "cuatro";

    cout << "one is ";
    cout << spnumbers["one"] << endl; 

    cout << spnumbers.size() << endl;
}


/*
// OUTPUT:

one is uno
4

*/

/*
"""Python equivalent
of the C++ code """
def main():
    spnumbers = {"one":"uno","two":"dos"}

    spnumbers["four"]="cuatro"
    spnumbers["three"]="tres"

    print("one is", end=" ")
    print(spnumbers["one"])

    print(len(spnumbers))
main()
*/