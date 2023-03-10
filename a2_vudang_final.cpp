// Name:       Vu Dang
// email:      vdang159@mtroyal.ca
// Course:     COMP 1633-001
// Instructor: Munima Jahan
// Assignment: Assignment 2 (Blueprints Scoring)
// Due Date:   Monday, Februrary 27, 2023, before 11:59pm
//
// Source File:  a1p1_solution.cpp
//
// Purpose:  This program generates a score for a building in the Blueprints game.
//
// Details:
//
//   Input:  The building information is stored in a file and consists of
//             3 columns representing (row, column, dice type-value) .
//             6 rows representing 6 dices.
//
//
//   Output: The program will generate a:
//           1) Visual representation of the building with 3 stacks, 6 rows.
//           2) Scoring table of glass, recycled, stone, wood, and total.
//
// Assumptions & Limitations:
//    There are four types of dices, each scoring in different ways.
//    Must use a 2-D ARRAY OF STRUCTURES to be 6 rows by 3 columns
//    Structure fields are a character for type, and an integer for the value.


#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


//------------------------------------------------------------------------------
// Global constants are encouraged, but global variables are unacceptable.
const int ROW = 6;
const int COL = 3;

// struct to keep track of attributes of dices, sharing the same variables.
struct Dice
{
    char type;
    int value;
};


//------------------------------------------------------------------------------
// 3. Set up array with default {'X', -1} (becomes the empty spaces)
//
// Function Name:  fill_array_default
// Purpose: Set up array with default {'X', -1} (becomes the empty spaces)
//
// Inputs: 2D array of structures for 18 cells (6row x 3col) of {type, value}.
//
// Output: 2D array of structures for 18 cells made up of {'X', -1}.
//------------------------------------------------------------------------------
void fill_array_default(Dice array[][COL])
{
  Dice filler = {'X', -1};

  for (int i = 0; i < ROW; i++)
  {
    for (int j = 0; j < COL; j++)
      {
        array[i][j] = filler;
      }
  }
}


//------------------------------------------------------------------------------
// 2. Reads int he data that has 4 columns: row >> column > type > value.
// Assigns the type and value to our array (of structures).
//
// Function Name:  fill_array_dices
// Purpose: Reads in the data that has 4 columns: row >> column > type > value.
//
// Details: Assigns the type and value to our array (of structures),
//
// Inputs: 2D array of structures for 18 cells (6row x 3col) of {type, value}.
//
// Output: 2D array of structures for 18 cells of dice attributes e.g. (G, 4)
//------------------------------------------------------------------------------
void fill_array_dices(Dice array[][COL])
{
  int row;
  int column;

  Dice dice;

  while(!cin.eof())
  {
      cin >> row >> column >> dice.type >> dice.value;
      array[row][column].type = dice.type;
      array[row][column].value = dice.value;
  }

// Un-comment to test print 2D array

//   for (int i = 0; i < ROW; i++)
//   {
//     for (int j = 0; j < COL; j++)
//       {
//         cout << array[i][j].type
//              << array[i][j].value
//              << endl;
//       }
//   }

}


//------------------------------------------------------------------------------
// 4. Get the glass-clear score
//
// Function Name:  get_glass_score
// Purpose: to return an integer value for clear-glass dice scoring rules.
//
// Details:
// CLEAR (glass): Score each clear die individually;
// the clear die being scored is worth the value of its top face.
// Note: These dice score even if covered by other dice.
//
// Inputs: 2D array of structures for 18 cells of dice attributes {type, value}.
//
// Output: returns integer value for glass score e.g. 4.
//------------------------------------------------------------------------------
int get_glass_score(Dice array[][COL])
{
  int glass_score = 0;

  for (int i = 0; i < ROW; i++) {
    for (int j = 0; j < COL; j++)
    {
      if (array[i][j].type == 'G')
      {
        if (array[i][j].value == 1)
        {
          glass_score += 1;
        }
        else if (array[i][j].value == 2)
        {
          glass_score += 2;
        }
        else if (array[i][j].value == 3)
        {
          glass_score += 3;
        }
        else if (array[i][j].value == 4)
        {
          glass_score += 4;
        }
        else if (array[i][j].value == 5)
        {
          glass_score += 5;
        }
        else
        {
          glass_score += 6;
        }
      }
      else
      {
        glass_score += 0;
      }
    }
  }

  return glass_score;
}


//------------------------------------------------------------------------------
// 5. Get the recycled-green score
//
// Function Name:  get_recycled_score
// Purpose: to return an integer value for recycled-green dice scoring rules.
//
// Details:
// GREEN (recycled): Score a total of 2/5/10/15/20/30 points
// for using a total of 1/2/3/4/5/6 green dice
//
// Inputs: 2D array of structures for 18 cells of dice attributes {type, value}.
//
// Output: returns integer value for recycled score e.g. 5.
//------------------------------------------------------------------------------
int get_recycled_score(Dice array[][COL])

{
  int recycled_die_count = 0;
  int recycled_score = 0;

  for (int i = 0; i < ROW; i++)
  {
    for (int j = 0; j < COL; j++)
    {
      if (array[i][j].type == 'R')
      {
        recycled_die_count += 1;
      }
      else
      {
        recycled_score += 0;
      }
    }
  }

  if (recycled_die_count == 1)
  {
    recycled_score += 2;
  }
  else if (recycled_die_count == 2)
  {
    recycled_score += 5;
  }
  else if (recycled_die_count == 3)
  {
    recycled_score += 10;
  }
  else if (recycled_die_count == 4)
  {
    recycled_score += 15;
  }
  else if (recycled_die_count == 5)
  {
    recycled_score += 20;
  }
  else if (recycled_die_count == 6)
  {
    recycled_score += 30;
  }
  else
  {
    recycled_score += 0;
  }

  return recycled_score;
}


//------------------------------------------------------------------------------
// 6. Get the stone-black score
//
// Function Name:  get_stone_score
// Purpose: to return an integer value for stone-black dice scoring rules.
//
// Details:
// BLACK (stone): Score each black die individually;
// the black die being scored is worth 2/3/5/8 points
// for being on the 1st/2nd/3rd/4th (or higher) level of a building.
//
// Inputs: 2D array of structures for 18 cells of dice attributes {type, value}.
//
// Output: returns integer value for stone score e.g. 5.
//------------------------------------------------------------------------------
int get_stone_score(Dice array[][COL])
{
  int stone_score = 0;

  for (int i = 0; i < ROW; i++)
  {
    for (int j = 0; j < COL; j++)
    {
      if (array[i][j].type == 'S')
      {
        if (i == 5)
        {
          stone_score += 2;
        }
        else if (i == 4)
        {
          stone_score += 3;
        }
        else if (i == 3)
        {
          stone_score += 5;
        }
        else
        {
          stone_score += 8;
        }
      }
      else
      {
        stone_score += 0;
      }
    }
  }

  return stone_score;
}


//------------------------------------------------------------------------------
// 7. Get the wood-orange score
//
// Function Name:  get_wood_score
// Purpose: to return an integer value for wood-orange dice scoring rules.
//
// Details:
// ORANGE (wood):
// Score each orange die individually;
// score 2 points per die adjacent to the orange die being scored.
// Dice are adjacent if they share a face.
//
// Inputs: 2D array of structures for 18 cells of dice attributes {type, value}.
//
// Output: integer value for wood score e.g. 6.
//------------------------------------------------------------------------------
int get_wood_score(Dice array[][COL])
{
    int wood_score = 0;

    // Checking for dices adjacent horizontally left and left
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (array[i][j].type == 'W')             // If struct.type of W
            {
                if (j == 0) {                        // j == 0, in col 0 "1st"
                    if (array[i][j+1].type != 'X')   // j+1, checks next column
                    {                                // if not equal to 'X',
                        wood_score += 2;             // meaning there's a dice, +2
                    }
                }
                else if (j == 1)                     // j == 1, in col 1 "2nd"
                {
                    if (array[i][j-1].type != 'X')   // j-1, checks prev col 0
                    {
                        wood_score += 2;
                    }
                    if (array[i][j+1].type != 'X')   // j+1, checks next col 2
                    {
                        wood_score += 2;
                    }
                }
                else {                               // j == 3, in col 2 "3rd"
                    if (array[i][j-1].type != 'X')        // j-1, checks prev col
                    {
                        wood_score += 2;
                    }
                }
            }
        }
    }

    // Checking for dices adjacent vertically top and bottom
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
              if (array[i][j].type == 'W') {        // If struct.type of W
                  if (i == 0) {                     // i == 0, in row 0, "bottom"
                      if (array[i+1][j].type != 'X')     // i + 1, row above
                      {                             // if not equal to 'X'
                          wood_score += 2;          // meaning there's a dice, +2
                      }
                  }
                  else if (i == (ROW-1))            // ROW-1, the top row
                  {
                      if (array[i-1][j].type != 'X')     // i - 1, row below top row
                      {
                          wood_score += 2;
                      }
                  }
                  else {                            // other rows in between
                      if (array[i-1][j].type != 'X')     // any row below for j col
                      {
                          wood_score += 2;
                      }
                      if (array[i+1][j].type != 'X')     // any row above for j col
                      {
                          wood_score += 2;
                      }
                  }
              }
          }
      }

    return wood_score;
}


//------------------------------------------------------------------------------
// 9. Print the dice stacks
//
// Function Name:  display_dice_stacks
// Purpose: to cout rows of strings to visually represent a building of dices.
//
// Details: the building is made up of 3 stacks, with potentially 6 rows.
//
// Inputs: 2D array of structures for 18 cells of dice attributes {type, value}.
//
// Output: cout of strings to visually represent a building of dices.
//------------------------------------------------------------------------------
void display_dice_stacks(Dice array[][COL])
{
  char dash = '-';

  for (int i = 0; i < ROW; i++)
  {
    for (int j = 0; j < COL; j++)
    {
      if (                                             // if all columns blank
          (array[i][0].type == 'X')
          && (array[i][1].type == 'X')
          && (array[i][2].type == 'X')
          )
          {
          cout << "";
          }

        if (j != (COL - 1))                            // First two columns
        {
            if (                                       // if all columns blank
                (array[i][0].type == 'X')
                && (array[i][1].type == 'X')
                && (array[i][2].type == 'X')
                )
                {
                cout << "";
                }
            else
            {
                if (array[i][j].type == 'X')
                {
                    array[i][j].type = dash;
                    array[i][j].type = dash;

                cout << array[i][j].type
                        << array[i][j].type
                        << " | ";
                }
                else
                {
                cout << array[i][j].type
                        << array[i][j].value
                        << " | ";
                }
            }
        }
        else
        {
            if (                                       // if all columns blank
                (array[i][2].type == 'X')
                && (array[i][1].type == 'X')
                && (array[i][0].type == 'X')
                )
                {
                cout << "";
                }
            else
                {
                    if (array[i][j].type == 'X')       // Last column
                    {
                    array[i][j].type = dash;
                    array[i][j].type = dash;

                    cout << array[i][j].type
                         << array[i][j].type;
                    }
                    else
                    {
                    cout << array[i][j].type
                            << array[i][j].value;
                    }
                 }
        }
    }                                                  // close for loop for COL
    cout  << "\n";
  }                                                    // close for loop for ROW
}


//------------------------------------------------------------------------------
// 10. Print the scoring table
//
// Function Name:  display_score_table
// Purpose: to cout rows of strings showing the scores for each dice & total.
//
// Inputs: 5 parameters:
//                      int glass_score - returned from calling function
//                      int recycled_score - returned from calling function
//                      int stone_score - returned from calling function
//                      int wood_score - returned from calling function
//                      int total_score - sum of the previous variables.
//
// Output: cout of strings as a table showing the scores for each dice & total.
//------------------------------------------------------------------------------
void display_score_table(int glass_score,
                         int recycled_score,
                         int stone_score,
                         int wood_score,
                         int total_score)
{
  cout << "\n";
  cout << "+----------+----+\n";
  cout << "| glass    | " << internal << setw(2) << glass_score << " |\n";
  cout << "| recycled | " << internal << setw(2) << recycled_score << " |\n";
  cout << "| stone    | " << internal << setw(2) << stone_score << " |\n";
  cout << "| wood     | " << internal << setw(2) << wood_score << " |\n";
  cout << "+==========+====+\n";
  cout << "| total    | " << internal << setw(2) << total_score << " |\n";
  cout << "+----------+----+";
  cout << "\n";
}


//------------------------------------------------------------------------------
// STEP 1. Outlining the main function (very first step)

int main()
{
    // Declare our 2D array, calling upon our constants, 6 rows by 3 columns.
    Dice array_of_dice_structures[ROW][COL];

    // 3. Set up array with default {'X', -1} (becomes the empty spaces)
    fill_array_default(array_of_dice_structures);
    // 2. Reads int he data that has 4 columns: row >> column > type > value.
    fill_array_dices(array_of_dice_structures);

    // 4. Get the glass-clear score
    int glass_score = get_glass_score(array_of_dice_structures);
    // 5. Get the recycled-green score
    int recycled_score = get_recycled_score(array_of_dice_structures);
    // 6. Get the stone-black score
    int stone_score = get_stone_score(array_of_dice_structures);
    // 7. Get the wood-orange score
    int wood_score = get_wood_score(array_of_dice_structures);

    // 8. Calculate the total score
    int total_score = glass_score
                      + recycled_score
                      + stone_score
                      + wood_score;

    // 9. Print the dice stacks
    display_dice_stacks(array_of_dice_structures);

    // 10. Print the scoring table
    display_score_table(glass_score,
                        recycled_score,
                        stone_score,
                        wood_score,
                        total_score);

  return 0;
}                                                   // close int main()



/*
CITATIONS
Array of Structures 
https://www.geeksforgeeks.org/array-of-structures-vs-array-within-a-structure-in-c-and-cpp/


Introduction to Structures
learncpp.com

*/