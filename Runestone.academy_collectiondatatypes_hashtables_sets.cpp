// Creates a hash table that maches
// the english letter to it's spanish
// equivalent, and outputs the size of
// the table to the console
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    // set up our hash table, there's 2 string items per table
    unordered_map <string, string> spnumbers;

    // our hash table has 2 subtables
    spnumbers = { {"one", "uno"}, {"two", "dos"} };

    // Add 2 more subtables into our array, this will result in 4
    spnumbers["three"] = "tres";
    spnumbers["four"] = "cuatro";

    cout << "one is ";
  
    cout << spnumbers["one"] << endl; // uno 

    cout << spnumbers.size() << endl; // 4
}


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


// Creates a hash table that maches
// the english letter to it's spanish
// equivalent, and outputs every item
// in the table to the console
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    unordered_map<string, string> spnumbers;

    spnumbers = { {"one","uno"},{"two","dos"},{"three","tres"},{"four","cuatro"},{"five","cinco"} };

    for (auto i=spnumbers.begin(); i!=spnumbers.end(); i++ ){
        //auto is used to automatically detect the data type when
        //a variable is declared. Use this ONLY when declaring complex
        //variables.

        cout << i->first << ":";
        cout << i->second << endl;
    }
}

// five:cinco
// four:cuatro
// three:tres
// two:dos
// one:uno

/*
"""Python equivalent
of the C++ code """
def main():
    spnumbers = {"one":"uno","two":"dos","three":"tres","four":"cuatro","five":"cinco" }

    for key in spnumbers:
        print(key, end=":")
        print(spnumbers[key])

main()

*/


// Function that checks to see if a char
// is in the unorderd set
#include <iostream>
#include <unordered_set>
using namespace std;

void checker(unordered_set<char> set, char letter){
    if(set.find(letter) == set.end()){
        cout << "letter " << letter << " is not in the set." << endl;
    }
    else{
        cout << "letter " << letter << " is in the set." << endl;
    }
}


int main(){
unordered_set<char> charSet = {'d', 'c', 'b', 'a'};

char letter = 'e';
checker(charSet, letter); // letter e is not in the set.
  
charSet.insert('e');
checker(charSet, letter); // letter e is in the set.
  
return 0;
}



/*
https://runestone.academy/ns/books/published/cpp4python/CollectionData/UnorderedSet.html

A statically allocated C++ array is an ordered collection of one or more C++ data values of identical type stored in contiguous memory.

A vector is a dynamically allocated array with many useful methods. It is more similar to the Python list than the array.

C++ strings are a sequential collection of zero or more characters. They are very similar to Python strings.

A hash table is used to store keys-value pairs. It applies a related hash function to the key in order to compute the location of the associated value. Look-up is typically very fast.

A set is an unordered collection of UNIQUE values.

array
a data structure consisting of an ordered collection of data elements of identical type in which each element can be identified by an array index.

collection
a grouping of a number of data items (possibly only zero or one) that have some shared significance or need to be operated upon together.

hash table
a collection consisting of key-value pairs with an associated hash function that maps the key to the associated value.

const (immutable)
unable to be modified.

non-const (mutable)
the ability of an object to be modified.

set
An unordered data structure consisting of unique, immutable data values.

string
A sequential data structure consisting of zero or more characters.

vector
sequence container storing data of a single type that is stored in a dynamically allocated array which can change in size.

word
unit of data used by a particular processor design.

  */ 
 
