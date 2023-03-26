#include <iostream>
#include <fstream>
#include <iomanip>
// #include "groclist.h"
using namespace std; 

// Global variables are unacceptable. Global constants are encouraged.
const int MAXFILENAME = (30 + 1);           // +1 for the null terminator '\0'
const int MAXINVNAME = (50 + 1);            // +1 for the null terminator '\0'

// Set up node which is a struct, space for data and space for link to next node
struct Grocery_Item 
{
    int quantity;
    char name[MAXINVNAME] ;                       // +1 for the null terminator '\0'
    Grocery_Item* link;
};

typedef Grocery_Item* Grocery_Item_Ptr;       // Readability, to ref Grocery_Item_Ptr 
                                              // rather than Grocery_Item*

// Prototypes - because we're putting main function first in this program.
void prompt_ingredients_file(ifstream &in, Grocery_Item_Ptr &head); 
void prompt_inventory_file(ifstream &in, Grocery_Item_Ptr &head);

void process_ingredients(ifstream &in, 
                        Grocery_Item_Ptr &head); 

void process_inventory(ifstream &in, 
                      Grocery_Item_Ptr &head);

//------------------------------------------------------------------------------
// 0. Outline the main function.
//
// Function Name:  Main
// Purpose (relationship between input and output): 
//                                 Outline the steps (functions) of the program. 
//        
// Inputs: Call upon other functions to 
//         process 2 files:
//                        1) meals/ingredients required.
//                        2) inventory in stock. 
//
// Output: Produce a grocery list of quantities of items for making the meals. 
//------------------------------------------------------------------------------
int main() 
{
  Grocery_Item_Ptr head = NULL;  
  
  // Step 1. Prompt user for meals file.
  prompt_ingredients_file(head);    

  // Step 2. Prompt user for inventory file.
  prompt_inventory_file();                                                                                                                
}

//------------------------------------------------------------------------------
// Step 1. Prompt user to enter meals file
//
// Function Name:  void prompt_meals_file()
//
// Purpose: will prompt the user for the 1st of 3 files
//          a meal plan, containing the ingredients 
//          required for all the meals to be prepared
//          opens the entered file name, or displays a message to re-enter. 
// 
// Details: filename must be between 1 and 30 characters.
//          reading the filename from the user
//          successfully opening the file (This must succeed, 
//          otherwise the program can’t continue! 
//          Force the user to repeat this process until 
//          a valid filename is provided.)
// 
// Inputs: name of the ingredients file e.g. meals.txt 
//
// Output: If there's no valid file name, a message prompts user to re-enter 
//         if a valid file name was entered, 
//         the file will be opened
//------------------------------------------------------------------------------
void prompt_ingredients_file(Grocery_Item_Ptr &head)
{ 
  cout << "enter ingredients file name: " << endl;  
  char ingredients[MAXFILENAME];                   // +1 for the null terminator '\0'
  cin >> ingredients;
  
  ifstream input_file; 
  input_file.open(ingredients);

  while(input_file.fail())
  {
    cout << "try entering a valid file name, or (ctrl-c) to exit the program: "
         << endl; 
    
     cin >> ingredients; 
     input_file.open(ingredients); 
  }
  
  // Step 3. Reads ingredients file and returns sorted grocery list.
  process_ingredients(input_file, head);  
  
  input_file.close();
}

//------------------------------------------------------------------------------
// Step 2. Prompt user to enter inventory file
//
// Function Name:  void prompt_meals_file()
//
// Purpose: will prompt the user for the 2nd of 3 files
//          inventory of items already stocked, 
//          opens the entered file name, or displays a message to re-enter.
// 
// Details: filename must be between 1 and 30 characters.
//          reading the filename from the user
//          successfully opening the file 
//          (An inventory file is not technically required, 
//          since you could have no groceries in the house; 
//          however, your program will force the user 
//          to supply a valid filename even if this file is empty.)
// 
// Inputs: name of the inventory file e.g. inventory.txt 
//
// Output: If there's no valid file name, a message prompts user to re-enter 
//         if a valid file name was entered, 
//         the file will be opened
//------------------------------------------------------------------------------
void prompt_inventory_file(Grocery_Item_Ptr &head)
{
  cout << "enter inventory file name: " << endl;  
  char inventory[MAXFILENAME];                   // +1 for the null terminator '\0'
  cin >> inventory; 

  ifstream input_file; 
  input_file.open(inventory);

  while(input_file.fail())
  {
    cout << "try entering a valid file name, or (ctrl-c) to exit the program: "
         << endl; 
    
     cin >> inventory; 
     input_file.open(inventory); 
  }
  // Step 4. Reads inventory file.
  process_inventory(input_file, head);   
  
  input_file.close();
}


//------------------------------------------------------------------------------
// Step 3. Reads ingredients file and returns sorted grocery list
//
// Function Name: process_ingredients(ifstream &in, Grocery_Item_Ptr &head);  
//
// Purpose: 
// 
// Details: 
//   reading items from the ingredients file, adding to the sorted grocery list
//   returns item name, quantity, 
//   EOF not encountered -> success set to true
//   EOF encountered -> success set to false 
//
//   node type must be named Grocery_Item and a Grocery_Item_Ptr type
//   a node will be inserted for each NEW ingredient encountered
//   list must be built in sorted order, each time a new node is inserted, 
//   it is inserted into a sorted list, such that the list remains sorted 
// 
// Inputs: 
//
// Output: 
//------------------------------------------------------------------------------
void process_ingredients(ifstream &in, Grocery_Item_Ptr &head)
{
    Grocery_Item* newItem = new Grocery_Item;

    int quantity; 
    char space; 
    char name[MAXINVNAME]; 
  
    while(!input_file.eof())
    {
      input_file >> quantity; 
      input_file.get(space); 
      input_file.getline(name, MAXINVNAME); 

      insert_item(Grocery_Item_Ptr &head, int quantity, const char name[]);
    }
}

//------------------------------------------------------------------------------
// Step 4. Reads inventory file 
//
// Function Name: 
// void process_inventory(ifstream &input_file, Grocery_Item_Ptr &head); 
//
// Purpose: 
// 
// Details: 
// reading items from the inventory file, altering sorted grocery list as need
// checks if there is sufficient quantity of a given item name 
// if sufficient, delete the given item's node (shrinks the grocery list)
//
// Inputs: 
//
// Output: 
//------------------------------------------------------------------------------
void process_inventory(ifstream &in, Grocery_Item_Ptr &head)
{
    Grocery_Item* newItem = new Grocery_Item;

    int quantity; 
    char space; 
    char name[MAXINVNAME]; 
  
    while(!input_file.eof())
    {
      input_file >> quantity; 
      input_file.get(space); 
      input_file.getline(name, MAXINVNAME); 

      insert_item(Grocery_Item_Ptr &head, int quantity, const char name[]);
    }
}


