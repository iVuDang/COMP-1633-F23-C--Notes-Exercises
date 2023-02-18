// This function concatenates the string hello World
// Then it says where World begins in the concatenated string
// https://runestone.academy/ns/books/published/cpp4python/CollectionData/Strings.html

#include <iostream>
#include <string>
using namespace std;

int main(){

    string mystring1 = "Hello";
    string mystring2 = "World!";
    string mystring3;

    mystring3 = mystring1 + " " + mystring2;
    cout << mystring3 << endl;

    cout << mystring2 << " begins at ";
    cout << mystring3.find(mystring2) << endl;

    return 0;
}

/*
Hello World!
World! begins at 6
*/




/*
// PYTHON

"""This does the same thing as the C++ function """
def main():
    mystring1 = "Hello"
    mystring2 = "World!"

    mystring3 = mystring1 + " " + mystring2
    print(mystring3)

    print(mystring2, end=" ")
    print("begins at", end=" ")
    print(str(mystring3.find(mystring2)))

main()

*/ 