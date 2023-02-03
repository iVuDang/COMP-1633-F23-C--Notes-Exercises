#include <iostream>
#include <math.h>       /* ceil */
using namespace std; 


/*
Write the pseudo-code of an algorithm to assist do-it-yourselfers determine how many cans of paint are required to paint a room. The selected paint covers 10 square metres per litre. It assumed that every room will have exactly one door, with measurements of 1.8m by 0.6m and one window, with measurements of 1.5m by 1m. The algorithm will read from the user the dimensions of the room, specifically length, width and height. A can of paint contains 3.79L.

In: length, width and height (three double values)

Out: Number of cans required (an integer number)

Surface area of a box:
 2 * [(l * w) + (l * h) + (w * h)]

*/

int main() {
  
  double length, width, height, total_area, paint_req; 
  int cans_req; 

  cout << "Enter the length, width, and height: " << endl; 
  cin >> length >> width >> height; 

  total_area = (2 * ((length*width) + (length * height) + (width * height))) - (1.8 * 0.6) - (1.5 * 1);

  paint_req = total_area / 10; // Take total surface area of m, divide by 1 can paint per 1 L

  cans_req = ceil(paint_req/3.79); // Paint required in L, 1 can of paint has 3.79L
    
  cout << "Can of paints required = " << cans_req << endl; 
  
}