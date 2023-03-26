#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std; 

void prompt_meal_file()
{
  ifstream input_file; 
  
  cout << "enter ingredients file name: " << endl;  
  char meals[30 + 1];
  cin >> meals; 
  input_file.open(meals);

  if(input_file
  

  input_file.close();
}


void prompt_inventory_file()
{
  ifstream input_file; 

  cout << "enter inventory file name: " << endl;
  char inventory[30 + 1];
  cin >> inventory; 

  input_file.open(inventory);

  input_file.close();
  
}


void prompt_grocery_file()
{
  ifstream input_file; 

  cout << "enter name of grocery list file to create: " << endl; 
  char groceries[30 + 1];
  cin >> groceries; 

  // int quantity; 
  // char[3- +1] ingredient; 
  // if(input_file.fail())
  // {
  //   cout << "try entering again a valid file name, or (ctrl-c) to exit the program." << endl; 
  // }
  // else
  // {
  //   while(!input.eof())
  //     {
  //       cin >> quantity >> ingredient; 
  //     }
  // }

  input_file.open(groceries);

  input_file.close();
}



int main() 
{
  prompt_meal_file();
  prompt_inventory_file(); 
  prompt_grocery_file(); 

}




