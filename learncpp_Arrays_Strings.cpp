#include <iostream>

int main()
{
    int prime[5]{}; // hold the first 5 prime numbers
    prime[0] = 2; // The first element has index 0
    prime[1] = 3;
    prime[2] = 5;
    prime[3] = 7;
    prime[4] = 11; // The last element has index 4 (array length-1)

    std::cout << "The lowest prime number is: " << prime[0] << '\n';
    std::cout << "The sum of the first 5 primes is: " << prime[0] + prime[1] + prime[2] + prime[3] + prime[4] << '\n';

    return 0;
}


#include <iostream>

// One way to “initialize” an array is to do it element by element:
// int prime[5]; // hold the first 5 prime numbers
// prime[0] = 2;
// prime[1] = 3;
// prime[2] = 5;
// prime[3] = 7;
// prime[4] = 11;


// int prime[5]{ 2, 3, 5, 7, 11 }; // use initializer list to initialize the fixed array


#include <iostream>

int main()
{
    int array[5]{ 7, 4, 5 }; // only initialize first 3 elements

    std::cout << array[0] << '\n';
    std::cout << array[1] << '\n';
    std::cout << array[2] << '\n';
    std::cout << array[3] << '\n';
    std::cout << array[4] << '\n';

    return 0;
}


// 7
// 4
// 5
// 0
// 0
//  


// int array[5]{ 0, 1, 2, 3, 4 }; // explicitly define the length of the array
int array[]{ 0, 1, 2, 3, 4 }; // let the initializer list set length of the array


#include <iostream>
#include <utility>

int main()
{
    int x{ 2 };
    int y{ 4 };
    std::cout << "Before swap: x = " << x << ", y = " << y << '\n';
    std::swap(x, y); // swap the values of x and y
    std::cout << "After swap:  x = " << x << ", y = " << y << '\n';

    return 0;
}


// Before swap: x = 2, y = 4
// After swap:  x = 4, y = 2


int array[3][5]; // a 3-element array of 5-element arrays
Since we have 2 subscripts, this is a two-dimensional array.

In a two-dimensional array, it is convenient to think of the first (left) subscript as being the row, and the second (right) subscript as being the column. This is called row-major order. Conceptually, the above two-dimensional array is laid out as follows:

[0][0]  [0][1]  [0][2]  [0][3]  [0][4] // row 0
[1][0]  [1][1]  [1][2]  [1][3]  [1][4] // row 1
[2][0]  [2][1]  [2][2]  [2][3]  [2][4] // row 2


//------------------------------------------------------------------------------


int array[3][5]
{
  { 1, 2, 3, 4, 5 }, // row 0
  { 6, 7, 8, 9, 10 }, // row 1
  { 11, 12, 13, 14, 15 } // row 2
};


//------------------------------------------------------------------------------

int array[3][5]
{
  { 1, 2 }, // row 0 = 1, 2, 0, 0, 0
  { 6, 7, 8 }, // row 1 = 6, 7, 8, 0, 0
  { 11, 12, 13, 14 } // row 2 = 11, 12, 13, 14, 0
};

//------------------------------------------------------------------------------

// Accessing elements in a two-dimensional array

// Accessing all of the elements of a two-dimensional array requires two loops: one for the row, and one for the column. Since two-dimensional arrays are typically accessed row by row, the row index is typically used as the outer loop.

for (int row{ 0 }; row < numRows; ++row) // step through the rows in the array
{
    for (int col{ 0 }; col < numCols; ++col) // step through each element in the row
    {
        std::cout << array[row][col];
    }
}




#include <iostream>

int main()
{
    constexpr int numRows{ 10 };
    constexpr int numCols{ 10 };

    // Declare a 10x10 array
    int product[numRows][numCols]{};

    // Calculate a multiplication table
    // We don't need to calc row and col 0 since mult by 0 always is 0
    for (int row{ 1 }; row < numRows; ++row)
    {
        for (int col{ 1 }; col < numCols; ++col)
        {
            product[row][col] = row * col;
        }
     }

    // Print the table
    for (int row{ 1 }; row < numRows; ++row)
    {
        for (int col{ 1 }; col < numCols; ++col)
        {
            std::cout << product[row][col] << '\t';
        }

        std::cout << '\n';
    }

    return 0;
}


// 1   2   3   4   5   6   7   8   9
// 2   4   6   8   10  12  14  16  18
// 3   6   9   12  15  18  21  24  27
// 4   8   12  16  20  24  28  32  36
// 5   10  15  20  25  30  35  40  45
// 6   12  18  24  30  36  42  48  54
// 7   14  21  28  35  42  49  56  63
// 8   16  24  32  40  48  56  64  72
// 9   18  27  36  45  54  63  72  81
//  



#include <iostream>


int main()
{
int array[5]{ 9, 7, 5, 3, 1 };

// Deferencing an array returns the first element (element 0)
std::cout << *array; // will print 9!

char name[]{ "Jason" }; // C-style string (also an array)
std::cout << *name << '\n'; // will print 'J'

}


#include <iostream>

int main()
{
    int array[5]{ 9, 7, 5, 3, 1 };
    std::cout << *array << '\n'; // will print 9

    int* ptr{ array };
    std::cout << *ptr << '\n'; // will print 9

    return 0;
}


#include <iostream>

int main()
{
    int array[5]{ 9, 7, 5, 3, 1 };

    std::cout << sizeof(array) << '\n'; // will print sizeof(int) * array length

    int* ptr{ array };
    std::cout << sizeof(ptr) << '\n'; // will print the size of a pointer

    return 0;
}

// 20
// 4


#include <iostream>

int main()
{
    int array[5]{ 9, 7, 5, 3, 1 };
    std::cout << array << '\n';	 // type int[5], prints 009DF9D4
    std::cout << &array << '\n'; // type int(*)[5], prints 009DF9D4

    std::cout << '\n';

    int* ptr{ array };
    std::cout << ptr << '\n';	 // type int*, prints 009DF9D4
    std::cout << &ptr << '\n';	 // type int**, prints 009DF9C8

    return 0;
}
// h/t to reader PacMan for this example



#include <iostream>

void printSize(int* array)
{
    // array is treated as a pointer here
    std::cout << sizeof(array) << '\n'; // prints the size of a pointer, not the size of the array!
}

int main()
{
    int array[]{ 1, 1, 2, 3, 5, 8, 13, 21 };
    std::cout << sizeof(array) << '\n'; // will print sizeof(int) * array length

    printSize(array); // the array argument decays into a pointer here

    return 0;
}



#include <iostream>

void printSize(int* array)
{
    // array is treated as a pointer here
    std::cout << sizeof(array) << '\n'; // prints the size of a pointer, not the size of the array!
}

int main()
{
    int array[]{ 1, 1, 2, 3, 5, 8, 13, 21 };
    std::cout << sizeof(array) << '\n'; // will print sizeof(int) * array length

    printSize(array); // the array argument decays into a pointer here

    return 0;
}


// void printSize(int array[]);
// void printSize(int* array);
// Some programmers prefer using the [] syntax because it makes it clear that the function is expecting an array, not just a pointer to a value. However, in most cases, because the pointer doesn’t know how large the array is, you’ll need to pass in the array size as a separate parameter anyway (strings being an exception because they’re null terminated).



#include <iostream>

// parameter ptr contains a copy of the array's address
void changeArray(int* ptr)
{
    *ptr = 5; // so changing an array element changes the _actual_ array
}

int main()
{
    int array[]{ 1, 1, 2, 3, 5, 8, 13, 21 };
    std::cout << "Element 0 has value: " << array[0] << '\n';

    changeArray(array);

    std::cout << "Element 0 has value: " << array[0] << '\n';

    return 0;
}

// Element 0 has value: 1
// Element 0 has value: 5


// When changeArray() is called, array decays into a pointer, and the value of that pointer (the memory address of the first element of the array) is copied into the ptr parameter of function changeArray(). Although the value in ptr is a copy of the address of the array, ptr still points at the actual array (not a copy!).


#include <iostream>

int main()
{
     int array[]{ 9, 7, 5, 3, 1 };

     std::cout << &array[1] << '\n'; // print memory address of array element 1
     std::cout << array+1 << '\n'; // print memory address of array pointer + 1

     std::cout << array[1] << '\n'; // prints 7
     std::cout << *(array+1) << '\n'; // prints 7 (note the parenthesis required here)

    return 0;
}


// 0017FB80
// 0017FB80
// 7
// 7

#include <algorithm>
#include <iostream>
#include <iterator> // for std::begin and std::end

bool isVowel(char ch)
{
    switch (ch)
    {
    case 'A':
    case 'a':
    case 'E':
    case 'e':
    case 'I':
    case 'i':
    case 'O':
    case 'o':
    case 'U':
    case 'u':
        return true;
    default:
        return false;
    }
}

int main()
{
    char name[]{ "Mollie" };

    // walk through all the elements of name and count how many calls to isVowel return true
    auto numVowels{ std::count_if(std::begin(name), std::end(name), isVowel) };

    std::cout << name << " has " << numVowels << " vowels.\n";

    return 0;
}

#include <iostream>

int main()
{
    int nArray[5]{ 9, 7, 5, 3, 1 };
    char cArray[]{ "Hello!" };
    const char* name{ "Alex" };

    std::cout << nArray << '\n'; // nArray will decay to type int* // 0x7fff61a566d0
    std::cout << cArray << '\n'; // cArray will decay to type char* // Hello!
    std::cout << name << '\n'; // name is already type char* // Alex

    return 0;
}


#include <iostream>

new int; // dynamically allocate an integer (and discard the result)

int* ptr{ new int }; // dynamically allocate an integer and assign the address to ptr so we can access it later

*ptr = 7; // assign value of 7 to allocated memory



#include <algorithm> // std::sort
#include <iostream>
#include <string>

int getNameCount()
{
    std::cout << "How many names would you like to enter? ";
    int length{};
    std::cin >> length;

    return length;
}

// Asks user to enter all the names
void getNames(std::string* names, int length)
{
    for (int i{ 0 }; i < length; ++i)
    {
        std::cout << "Enter name #" << i + 1 << ": ";
        std::getline(std::cin >> std::ws, names[i]);
    }
}

// Prints the sorted names
void printNames(std::string* names, int length)
{
    std::cout << "\nHere is your sorted list:\n";

    for (int i{ 0 }; i < length; ++i)
        std::cout << "Name #" << i + 1 << ": " << names[i] << '\n';
}

int main()
{
    int length{ getNameCount() };

    // Allocate an array to hold the names
    auto* names{ new std::string[length]{} };

    getNames(names, length);

    // Sort the array
    std::sort(names, names + length);

    printNames(names, length);

    // don't forget to use array delete
    delete[] names;
    // we don't need to set names to nullptr/0 here because it's going to go out
    // of scope immediately after this anyway.

    return 0;
}


// How many names would you like to enter? 5
// Enter name #1: Jason
// Enter name #2: Mark
// Enter name #3: Alex
// Enter name #4: Chris
// Enter name #5: John

// Here is your sorted list:
// Name #1: Alex
// Name #2: Chris
// Name #3: Jason
// Name #4: John
// Name #5: Mark

// Standard for loop
#include <iostream>
#include <iterator> // std::size
using namespace std; 

int main()
{
    constexpr int scores[]{ 84, 92, 76, 81, 56 };
    constexpr int numStudents{ sizeof(scores) };

    int maxScore{ 0 }; // keep track of our largest score
    for (int student{ 0 }; student < numStudents; ++student)
    {
        if (scores[student] > maxScore)
        {
            maxScore = scores[student];
        }
    }

    cout << "The best score was " << maxScore << '\n';

    return 0;
}

// The best score was 92


// For each loop:
#include <iostream>

int main()
{
    constexpr int scores[]{ 84, 92, 76, 81, 56 };
    int maxScore{ 0 }; // keep track of our largest score

    for (auto score : scores) // iterate over array scores, assigning each value in turn to variable score
    {
        if (score > maxScore)
        {
            maxScore = score;
        }
    }

    std::cout << "The best score was " << maxScore << '\n';

    return 0;
}

// For-each loops provide a superior syntax for iterating through an array when we need to access all of the array elements in forwards sequential order. It should be preferred over the standard for loop


#include <iostream>

int main()
{
    constexpr int fibonacci[]{ 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };
    for (int number : fibonacci) // iterate over array fibonacci
    {
       std::cout << number << ' '; // we access the array element for this iteration through variable number
    }

    std::cout << '\n';

    return 0;
}


// 0 1 1 2 3 5 8 13 21 34 55 89


#include <iostream>

int main()
{
    constexpr int fibonacci[]{ 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };
    for (auto number : fibonacci) // type is auto, so number has its type deduced from the fibonacci array
    {
       std::cout << number << ' ';
    }

    std::cout << '\n';

    return 0;
}



// our element declarations are declared by value:
std::string array[]{ "peter", "likes", "frozen", "yogurt" };
for (auto element : array) // element will be a copy of the current array element
{
    std::cout << element << ' ';
}


// Copying array elements can be expensive, and most of the time we really just want to refer to the original element. Fortunately, we can use references for this:

std::string array[]{ "peter", "likes", "frozen", "yogurt" };
for (auto element : array) // element will be a copy of the current array element
{
    std::cout << element << ' ';
}


// element will be a reference to the currently iterated array element, avoiding having to make a copy. Also any changes to element will affect the array being iterated over, something not possible if element is a normal variable.


std::string array[]{ "peter", "likes", "frozen", "yogurt" };
for (const auto& element: array) // element is a const reference to the currently iterated array element
{
    std::cout << element << ' ';
}


// our element declarations are declared by value:
std::string array[]{ "peter", "likes", "frozen", "yogurt" };
for (auto element : array) // element will be a copy of the current array element
{
    std::cout << element << ' ';
}


// Copying array elements can be expensive, and most of the time we really just want to refer to the original element. Fortunately, we can use references for this:

std::string array[]{ "peter", "likes", "frozen", "yogurt" };
for (auto element : array) // element will be a copy of the current array element
{
    std::cout << element << ' ';
}


// element will be a reference to the currently iterated array element, avoiding having to make a copy. Also any changes to element will affect the array being iterated over, something not possible if element is a normal variable.


std::string array[]{ "peter", "likes", "frozen", "yogurt" };
for (const auto& element: array) // element is a const reference to the currently iterated array element
{
    std::cout << element << ' ';
}


#include <iostream>
#include <vector>

int main()
{
    std::vector fibonacci{ 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 }; // note use of std::vector here rather than a fixed array
    // Before C++17
    // std::vector<int> fibonacci{ 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };

    for (auto number : fibonacci)
    {
        std::cout << number << ' ';
    }

    std::cout << '\n';

    return 0;
}



#include <iostream>

int* ptr; // pointer to an int, one asterisk
// A pointer to a pointer to an int is declared using two asterisks

int** ptrptr; // pointer to a pointer to an int, two asterisks



int value { 5 };

int* ptr { &value };
std::cout << *ptr << '\n'; // Dereference pointer to int to get int value

int** ptrptr { &ptr };
std::cout << **ptrptr << '\n'; // dereference to get pointer to int, dereference again to get int value


// The above program prints:

// 5
// 5



#include <array>
#include <iostream>

struct House
{
    int number{};
    int stories{};
    int roomsPerStory{};
};

int main()
{
    std::array<House, 3> houses{};

    houses[0] = { 13, 4, 30 };
    houses[1] = { 14, 3, 10 };
    houses[2] = { 15, 3, 40 };

    for (const auto& house : houses)
    {
        std::cout << "House number " << house.number
                  << " has " << (house.stories * house.roomsPerStory)
                  << " rooms\n";
    }

    return 0;
}


// House number 13 has 120 rooms
// House number 14 has 30 rooms
// House number 15 has 120 rooms


#include <array>
#include <iostream>

int main()
{
    std::array myArray { 7, 3, 1, 9, 5 };

    // Print the array in reverse order.
    for (auto i{ myArray.size() }; i-- > 0; )
        std::cout << myArray[i] << ' ';

    std::cout << '\n';

    return 0;
}


#include <algorithm> // std::sort
#include <cstddef> // std::size_t
#include <iostream>
#include <string>
#include <vector>

struct Student
{
  std::string name{};
  int grade{};
};

int getNumberOfStudents()
{
  int numberOfStudents{};

  do
  {
    std::cout << "How many students do you want to enter? ";
    std::cin >> numberOfStudents;
  } while (numberOfStudents <= 0);

  return numberOfStudents;
}

std::vector<Student> getStudents()
{
  using Students = std::vector<Student>;

  int numberOfStudents{ getNumberOfStudents() };

  // Create a vector with numberOfStudents elements.
  Students students(static_cast<Students::size_type>(numberOfStudents));

  int studentNumber{ 1 };

  for (auto& student : students)
  {
    std::cout << "Enter name #" << studentNumber << ": ";
    std::cin >> student.name;
    std::cout << "Enter grade #" << studentNumber << ": ";
    std::cin >> student.grade;

    ++studentNumber;
  }

  return students;
}

// Pass by reference to avoid slow copies.
bool compareStudents(const Student& a, const Student& b)
{
  return (a.grade > b.grade);
}

int main()
{
  auto students{ getStudents() };

  std::sort(students.begin(), students.end(), compareStudents);

  // Print out all the names
  for (const auto& student : students)
  {
    std::cout << student.name << " got a grade of " << student.grade << '\n';
  }

  return 0;
}


#include <iostream>

// Use reference parameters so we can modify the values of the arguments passed in
void swap(int& a, int& b)
{
  // Temporarily save value of a
  int temp{ a };

  // Put value of b in a
  a = b;
  // Put previous value of a in b
  b = temp;
}

int main()
{
  int a{ 6 };
  int b{ 8 };
  swap(a, b);

  if (a == 8 && b == 6)
    std::cout << "It works!\n";
  else
    std::cout << "It's broken!\n";

  return 0;
}



#include <iostream>

// str will point to the first letter of the C-style string.
// Note that str points to a const char, so we can not change the values it points to.
// However, we can point str at something else.  This does not change the value of the argument.
void printCString(const char* str)
{
  // While we haven't encountered a null terminator
  while (*str != '\0')
  {
    // print the current character
    std::cout << *str;

    // and point str at the next character
    ++str;
  }
}

int main()
{
  printCString("Hello world!");

  std::cout << '\n';

  return 0;
}



#include <iostream>

// Let’s pretend we’re writing a card game.

// a) A deck of cards has 52 unique cards (13 card ranks of 4 suits). Create enumerations for the card ranks (2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King, Ace) and suits (clubs, diamonds, hearts, spades). Those enumerators will not be used to index arrays.

enum class CardSuit
{
    club,
    diamond,
    heart,
    spade,

    max_suits
};

enum class CardRank
{
    rank_2,
    rank_3,
    rank_4,
    rank_5,
    rank_6,
    rank_7,
    rank_8,
    rank_9,
    rank_10,
    rank_jack,
    rank_queen,
    rank_king,
    rank_ace,

    max_ranks
};


// b) Each card will be represented by a struct named Card that contains a rank and a suit. Create the struct.

struct Card
{
  CardRank rank{};
  CardSuit suit{};
};


// c) Create a printCard() function that takes a const Card reference as a parameter and prints the card rank and suit as a 2-letter code (e.g. the jack of spades would print as JS).

void printCard(const Card& card)
{
    switch (card.rank)
    {
    case CardRank::rank_2:      std::cout << '2';   break;
    case CardRank::rank_3:      std::cout << '3';   break;
    case CardRank::rank_4:      std::cout << '4';   break;
    case CardRank::rank_5:      std::cout << '5';   break;
    case CardRank::rank_6:      std::cout << '6';   break;
    case CardRank::rank_7:      std::cout << '7';   break;
    case CardRank::rank_8:      std::cout << '8';   break;
    case CardRank::rank_9:      std::cout << '9';   break;
    case CardRank::rank_10:     std::cout << 'T';   break;
    case CardRank::rank_jack:   std::cout << 'J';   break;
    case CardRank::rank_queen:  std::cout << 'Q';   break;
    case CardRank::rank_king:   std::cout << 'K';   break;
    case CardRank::rank_ace:    std::cout << 'A';   break;
    default:
        std::cout << '?';
        break;
    }

    switch (card.suit)
    {
    case CardSuit::club:       std::cout << 'C';   break;
    case CardSuit::diamond:    std::cout << 'D';   break;
    case CardSuit::heart:      std::cout << 'H';   break;
    case CardSuit::spade:      std::cout << 'S';   break;
    default:
        std::cout << '?';
        break;
    }
}

// d) A deck of cards has 52 cards. Create an array (using std::array) to represent the deck of cards, and initialize it with one of each card. Do this in a function named createDeck and call createDeck from main. createDeck should return the deck to main.

#include <array>

// We'll need these many more times, create an aliases.
using Deck = std::array<Card, 52>;
using Index = Deck::size_type;

Deck createDeck()
{
  Deck deck{};

  // We could initialize each card individually, but that would be a pain.  Let's use a loop.

  Index index{ 0 };

  for (int suit{ 0 }; suit < static_cast<int>(CardSuit::max_suits); ++suit)
  {
    for (int rank{ 0 }; rank < static_cast<int>(CardRank::max_ranks); ++rank)
    {
      deck[index].suit = static_cast<CardSuit>(suit);
      deck[index].rank = static_cast<CardRank>(rank);
      ++index;
    }
  }

  return deck;
}

int main()
{
  auto deck{ createDeck() };

  return 0;
}


// e) Write a function named printDeck() that takes the deck as a const reference parameter and prints the cards in the deck. Use a range-based for-loop. When you can printDeck with the deck you generated in the previous task, the output should be

void printDeck(const Deck& deck)
{
  for (const auto& card : deck)
  {
    printCard(card);
    std::cout << ' ';
  }

  std::cout << '\n';
}

// f) Write a function named shuffleDeck to shuffle the deck of cards using std::shuffle. Update your main function to shuffle the deck and print out the shuffled deck.

#include <algorithm> // for std::shuffle
#include <ctime> // for std::time
#include <random> // for std::mt19937

// ...

void shuffleDeck(Deck& deck)
{
  // mt is static so it only gets seeded once.
  static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };

  std::shuffle(deck.begin(), deck.end(), mt);
}

int main()
{
  auto deck{ createDeck() };

  shuffleDeck(deck);

  printDeck(deck);

  return 0;
}




// g) Write a function named getCardValue() that returns the value of a Card (e.g. a 2 is worth 2, a ten, jack, queen, or king is worth 10. Assume an Ace is worth 11).

#include <cassert>

int getCardValue(const Card& card)
{
  switch (card.rank)
  {
  case CardRank::rank_2:        return 2;
  case CardRank::rank_3:        return 3;
  case CardRank::rank_4:        return 4;
  case CardRank::rank_5:        return 5;
  case CardRank::rank_6:        return 6;
  case CardRank::rank_7:        return 7;
  case CardRank::rank_8:        return 8;
  case CardRank::rank_9:        return 9;
  case CardRank::rank_10:       return 10;
  case CardRank::rank_jack:     return 10;
  case CardRank::rank_queen:    return 10;
  case CardRank::rank_king:     return 10;
  case CardRank::rank_ace:      return 11;
  default:
    assert(false && "should never happen");
    return 0;
  }
}



// a) Alright, challenge time! Let’s write a simplified version of Blackjack. If you’re not already familiar with Blackjack, the Wikipedia article for Blackjack has a summary.

#include <algorithm> // std::shuffle
#include <array>
#include <cassert>
#include <ctime> // std::time
#include <iostream>
#include <random> // std::mt19937

enum class CardSuit
{
    club,
    diamond,
    heart,
    spade,

    max_suits
};

enum class CardRank
{
    rank_2,
    rank_3,
    rank_4,
    rank_5,
    rank_6,
    rank_7,
    rank_8,
    rank_9,
    rank_10,
    rank_jack,
    rank_queen,
    rank_king,
    rank_ace,

    max_ranks
};

struct Card
{
    CardRank rank{};
    CardSuit suit{};
};

struct Player
{
    int score{};
};

using Deck = std::array<Card, 52>;
using Index = Deck::size_type;

// Maximum score before losing.
constexpr int g_maximumScore{ 21 };

// Minimum score that the dealer has to have.
constexpr int g_minimumDealerScore{ 17 };

void printCard(const Card& card)
{
    switch (card.rank)
    {
    case CardRank::rank_2:      std::cout << '2';   break;
    case CardRank::rank_3:      std::cout << '3';   break;
    case CardRank::rank_4:      std::cout << '4';   break;
    case CardRank::rank_5:      std::cout << '5';   break;
    case CardRank::rank_6:      std::cout << '6';   break;
    case CardRank::rank_7:      std::cout << '7';   break;
    case CardRank::rank_8:      std::cout << '8';   break;
    case CardRank::rank_9:      std::cout << '9';   break;
    case CardRank::rank_10:     std::cout << 'T';   break;
    case CardRank::rank_jack:   std::cout << 'J';   break;
    case CardRank::rank_queen:  std::cout << 'Q';   break;
    case CardRank::rank_king:   std::cout << 'K';   break;
    case CardRank::rank_ace:    std::cout << 'A';   break;
    default:
        std::cout << '?';
        break;
    }

    switch (card.suit)
    {
    case CardSuit::club:       std::cout << 'C';   break;
    case CardSuit::diamond:    std::cout << 'D';   break;
    case CardSuit::heart:      std::cout << 'H';   break;
    case CardSuit::spade:      std::cout << 'S';   break;
    default:
        std::cout << '?';
        break;
    }
}

int getCardValue(const Card& card)
{
    switch (card.rank)
    {
    case CardRank::rank_2:        return 2;
    case CardRank::rank_3:        return 3;
    case CardRank::rank_4:        return 4;
    case CardRank::rank_5:        return 5;
    case CardRank::rank_6:        return 6;
    case CardRank::rank_7:        return 7;
    case CardRank::rank_8:        return 8;
    case CardRank::rank_9:        return 9;
    case CardRank::rank_10:       return 10;
    case CardRank::rank_jack:     return 10;
    case CardRank::rank_queen:    return 10;
    case CardRank::rank_king:     return 10;
    case CardRank::rank_ace:      return 11;
    default:
        assert(false && "should never happen");
        return 0;
    }
}

void printDeck(const Deck& deck)
{
    for (const auto& card : deck)
    {
        printCard(card);
        std::cout << ' ';
    }

    std::cout << '\n';
}

Deck createDeck()
{
    Deck deck{};

    // We could initialize each card individually, but that would be a pain.  Let's use a loop.

    Index index{ 0 };

    for (int suit{ 0 }; suit < static_cast<int>(CardSuit::max_suits); ++suit)
    {
        for (int rank{ 0 }; rank < static_cast<int>(CardRank::max_ranks); ++rank)
        {
            deck[index].suit = static_cast<CardSuit>(suit);
            deck[index].rank = static_cast<CardRank>(rank);
            ++index;
        }
    }

    return deck;
}

void shuffleDeck(Deck& deck)
{
    static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };

    std::shuffle(deck.begin(), deck.end(), mt);
}

bool playerWantsHit()
{
    while (true)
    {
        std::cout << "(h) to hit, or (s) to stand: ";

        char ch{};
        std::cin >> ch;

        switch (ch)
        {
        case 'h':
            return true;
        case 's':
            return false;
        }
    }
}

// Returns true if the player went bust. False otherwise.
bool playerTurn(const Deck& deck, Index& nextCardIndex, Player& player)
{
    while (true)
    {
        if (player.score > g_maximumScore)
        {
            // This can happen even before the player had a choice if they drew 2
            // aces.
            std::cout << "You busted!\n";
            return true;
        }
        else
        {
            if (playerWantsHit())
            {
                int cardValue{ getCardValue(deck.at(nextCardIndex++)) };
                player.score += cardValue;
                std::cout << "You were dealt a " << cardValue << " and now have " << player.score << '\n';
            }
            else
            {
                // The player didn't go bust.
                return false;
            }
        }
    }
}

// Returns true if the dealer went bust. False otherwise.
bool dealerTurn(const Deck& deck, Index& nextCardIndex, Player& dealer)
{
    // Draw cards until we reach the minimum value.
    while (dealer.score < g_minimumDealerScore)
    {
        int cardValue{ getCardValue(deck.at(nextCardIndex++)) };
        dealer.score += cardValue;
        std::cout << "The dealer turned up a " << cardValue << " and now has " << dealer.score << '\n';

    }

    // If the dealer's score is too high, they went bust.
    if (dealer.score > g_maximumScore)
    {
        std::cout << "The dealer busted!\n";
        return true;
    }

    return false;
}

bool playBlackjack(const Deck& deck)
{
    // Index of the card that will be drawn next. This cannot overrun
    // the array, because a player will lose before all cards are used up.
    Index nextCardIndex{ 0 };

    // Create the dealer and give them 1 card.
    Player dealer{ getCardValue(deck.at(nextCardIndex++)) };

    // The dealer's card is face up, the player can see it.
    std::cout << "The dealer is showing: " << dealer.score << '\n';

    // Create the player and give them 2 cards.
    Player player{ getCardValue(deck.at(nextCardIndex)) + getCardValue(deck.at(nextCardIndex + 1)) };
    nextCardIndex += 2;

    std::cout << "You have: " << player.score << '\n';

    if (playerTurn(deck, nextCardIndex, player))
    {
        // The player went bust.
        return false;
    }

    if (dealerTurn(deck, nextCardIndex, dealer))
    {
        // The dealer went bust, the player wins.
        return true;
    }

    return (player.score > dealer.score);
}

int main()
{
    auto deck{ createDeck() };

    shuffleDeck(deck);

    if (playBlackjack(deck))
    {
        std::cout << "You win!\n";
    }
    else
    {
        std::cout << "You lose!\n";
    }

    return 0;
}









