# COMP-1633-F23-Cplusplus-Notes

## Credits
* Mount Royal University, Comp 1633 - Intro to Comp Sci II
* [learncpp.com](https://www.learncpp.com/)
* [C++ for Python Programmers](https://runestone.academy/ns/books/published/cpp4python/index.html)

## Coding Standards 
<br> 

### :white_check_mark: GOOD 
* Incremental development - when writing programs, add a few lines or a function, compile, resolve any errors, and make sure it works. Don’t wait until you’ve written an entire program before compiling it for the first time! Add one piece at a time, make sure it compiles, and test it. Then when you’re sure it’s working, move on to the next piece. 
* Break problems into **small enough problems** so that the problems cannot be wrong when solving them.
* white space for increased readability
* one statement per line 
* consistent bracing formats with paired open and close braces aligned vertically
* variable and function names, must be meaningful and self-descriptive, with underscores to separate words:
    * function names start with verb, lowercase e.g. get_name
    * variable names describe what it is, lowercase e.g. avg_grade 
    * constants are capitalized e.g. TAX_RATE
* A function must have a single exit point (i.e. return statement), at the end of the
function body, at most one return statement for each function.
* One function, one job. 
* Keep calculations separate from output and return statements. Use variables to store intermediate calcs.
* Each variable should have exactly one purpose. 
* All local variable declarations at the top of each function, before the statements.
* Lines should be no longer than **80 chars** in length. Shorter than this line:

<br>

//------------------------------------------------------------------------------

<br>

* Comments for readability, should be either aligned or at the top. 

    ```cpp
    // BAD
    std::cout << "Hello world!\n"; // std::cout lives in the iostream library
    std::cout << "It is very nice to meet you!\n"; // these comments make the code hard to read
    std::cout << "Yeah!\n"; // especially when lines are different lengths

    // GOOD FOR SHORT COMMENTS:
    std::cout << "Hello world!\n";                 // std::cout lives in the iostream library
    std::cout << "It is very nice to meet you!\n"; // this is much easier to read
    std::cout << "Yeah!\n";                        // don't you think so?


    // GOOD FOR LONG COMMENTS:
    // std::cout lives in the iostream library
    std::cout << "Hello world!\n";

    // this is much easier to read
    std::cout << "It is very nice to meet you!\n";

    // don't you think so?
    std::cout << "Yeah!\n";

    /* This is a multi-line comment.
    This line will be ignored.
    So will this one. */

    ```

* Comments should describe 3 things: 
    1.  Typically at the top of the file, library, or a function - WHAT the library, program, or the function does

    ```cpp
    // This program calculates the student's final grade based on their test and homework scores.

    ```

    2. Typically before a function - HOW the code is going to accomplish its goal 
    
    ```cpp
    // To generate a random item, we're going to do the following:
    // 1) Put all of the items of the desired rarity on a list
    // 2) Calculate a probability for each item based on level and weight factor
    // 3) Choose a random number
    // 4) Figure out which item that random number corresponds to
    // 5) Return the appropriate item

    ```

    3. At statement level - WHY the code is doing something. <br>
     A bad statement comment explains what the code is doing. <br>
     If you ever write code that is so complex that needs a comment to explain what a statement is doing, <br>
     you probably need to rewrite your statement, not comment it.

    ```cpp
    Bad comment:

    // Set sight range to 0
    sight = 0;
    Reason: We already can see that sight is being set to 0 by looking at the statement

    Good comment:

    // The player just drank a potion of blindness and can not see anything
    sight = 0;
    Reason: Now we know why the player’s sight is being set to 0

    Bad comment:

    // Calculate the cost of the items
    cost = quantity * 2 * storePrice;
    Reason: We can see that this is a cost calculation, but why is quantity multiplied by 2?

    Good comment:

    // We need to multiply quantity by 2 here because they are bought in pairs
    cost = quantity * 2 * storePrice;
    Reason: Now we know why this formula makes sense.

    Comments are a great way to remind yourself (or tell somebody else) the reason you made one decision instead of another.

    Good comments:

    // We decided to use a linked list instead of an array because
    // arrays do insertion too slowly.
    // We're going to use Newton's method to find the root of a number because
    // there is no deterministic way to solve these equations.


    ```
    

    Opening documentation:
    ```
    1. your name.
    2. your MRU email address.
    3. your course/section number.
    4. instructor’s name, the assignment number.
    5. source file name and the submission date. 
    ```

    Header documentation for each function must include the following:
    ```
    1. Function name.
    2. Purpose, what the function does.
    3. Details of function.
    4. Input, type of data, and example input.
    5. Output, type of data and desired result.
    ```
* Ways to initialize a variables:
    ```cpp
    int a;         // no initializer (default initialization)
    int b = 5;     // initializer after equals sign (copy initialization)
    int c( 6 );    // initializer in parenthesis (direct initialization)

    // List initialization methods (C++11)
    int d { 7 };   // initializer in braces (direct list initialization)
    int e = { 8 }; // initializer in braces after equals sign (copy list initialization)
    int f {};      // initializer is empty braces (value initialization)

    int a = 5, b = 6;          // copy initialization
    int c( 7 ), d( 8 );        // direct initialization
    int e { 9 }, f { 10 };     // direct brace initialization (preferred)
    int g = { 9 }, h = { 10 }; // copy brace initialization
    int i {}, j {};            // value initialization

    ```

* **Always Initialize your variables upon creation**:
    ```cpp
    #include <iostream>  // for std::cout and std::cin
    using namespace std; 

    int main()
    {
        cout << "Enter two numbers separated by a space: ";

        int x{ }; // define variable x to hold user input (and zero-initialize it)
        int y{ }; // define variable y to hold user input (and zero-initialize it)
    
        cin >> x >> y; // get two numbers and store in variable x and y respectively

        cout << "You entered " << x << " and " << y << '\n';

        return 0;
    }

    ```

* Opening brace appears on its own line to enhace readability and easy to see where error:

    ```cpp
    int main()
    {
    }
    ```

* Use whitepace/indentations to make code easier to read by aligning values and adding space:

    ```cpp

    Harder to read:
    
    cost = 57;
    pricePerItem = 24;
    value = 5;
    numberOfItems = 17;
    Easier to read:

    cost          = 57;
    pricePerItem  = 24;
    value         = 5;
    numberOfItems = 17;


    Harder to read:

    std::cout << "Hello world!\n"; // cout lives in the iostream library
    std::cout << "It is very nice to meet you!\n"; // these comments make the code hard to read
    std::cout << "Yeah!\n"; // especially when lines are different lengths
    Easier to read:

    std::cout << "Hello world!\n";                  // cout lives in the iostream library
    std::cout << "It is very nice to meet you!\n";  // these comments are easier to read
    std::cout << "Yeah!\n";                         // especially when all lined up


    Harder to read:

    // cout lives in the iostream library
    std::cout << "Hello world!\n";
    // these comments make the code hard to read
    std::cout << "It is very nice to meet you!\n";
    // especially when all bunched together
    std::cout << "Yeah!\n";


    Easier to read:

    // cout lives in the iostream library
    std::cout << "Hello world!\n";

    // these comments are easier to read
    std::cout << "It is very nice to meet you!\n";

    // when separated by whitespace
    std::cout << "Yeah!\n";
    ```

* Avoid altering and reassigning original variables:

    ```cpp
    The preferred solution

    #include <iostream>

    // preferred version
    int main()
    {
        std::cout << "Enter an integer: ";

        int num{ };                                                 // initialize variable
        std::cin >> num;                                            // immediately use the variable 

        std::cout << "Double that number is: " <<  num * 2 << '\n'; // use an expression to multiply num * 2 at the point where we are going to print it. Do not alter the original variable 'num'.

        return 0;
    }

    ```

* DRY - don't repeat yourself. If there's something performing more than once, consider creating a function to call upon it.
    ```cpp
    // REDUNDANT, need to apply DRY Don't Repeat Yourself 

    #include <iostream>

    int main()
    {
        int x{};
        std::cout << "Enter an integer: ";
        std::cin >> x;

        int y{};
        std::cout << "Enter an integer: ";
        std::cin >> y;

        std::cout << x << " + " << y << " = " << x + y << '\n';

        return 0;
    }

    // BETTER - create function do do job, and call it twice

    #include <iostream>

    int getValueFromUser()
    {
        std::cout << "Enter an integer: ";
        int input{};
        std::cin >> input;

        return input;
    }

    int main()
    {
        int x{ getValueFromUser() }; // first call to getValueFromUser
        int y{ getValueFromUser() }; // second call to getValueFromUser

        std::cout << x << " + " << y << " = " << x + y << '\n';

        return 0;
    }

    ```

* Return functions vs. Void functions. 
    * Return functions need to have return statement, and need to be used in cout in main function
    * Void functions don't have a return statement, they have a cout statement, and can be called on it's own in main to print. 

    ```cpp
    // Return function
    #include <iostream>

    int return7()
    {
        return 7;
    }

    int return9()
    {
        return 9;
    }

    int main()
    {
        std::cout << return7() + return9() << '\n'; // 16

        return 0;
    }

    // Void function

    // void means the function does not return a value to the caller
    void printHi()
    {
        std::cout << "Hi" << '\n';

        // This function does not return a value so no return statement is needed
    }

    int main()
    {
        printHi(); // okay: function printHi() is called, no value is returned

        return 0;
    }

    ```

<br>


### :x: AVOID
* Global variables are unacceptable. **Global constants are encouraged** e.g. GST used in several functions.
* Code or email, no more than 80 spaces (keep easy to read). 

<br>

---

## :bookmark_tabs: Notes 
* Operator precedence
    * Left to Right if same precedence level. 
    * a*b   a/b   a%b
    * a+b   a-b
    * A double cannot be used with modulus 
* Modulus formula: (Quotient × Divisor) + Remainder = Dividend
    * 5 % 6
    * = 5
    * (0 quotient x 6) + 5 = 5
* Integer operated on Integer will result in an integer, removing the trailing decimal.
    * 3 / 2 = 1 
    * 3 / 2 is 1.5, but the .5 is removed. 
* Integer operated with a double will result in a double. 
    * 1 + 2.5 = 3.5


<br>

---

## :desktop_computer: Linux Terminal Commands 

Context | Keyboard Shortcut | Purpose
---- | ---- | ----
Emacs | Alt + <kbd>X</kbd>, type Compile | to compile/debug within the emacs editor 
Emacs | Ctrl + <kbd>X</kbd>, <kbd>`</kbd> | to jump to error.
Emacs | Ctrl + <kbd>X</kbd>, Ctrl + <kbd>S</kbd> | save.
Emacs | Ctrl + <kbd>X</kbd>, Ctrl + <kbd>C</kbd> | close.
Emacs | Ctrl + <kbd>Z</kbd>, type fg | suspend, and resume. 
Linux | type and hit <kbd>tab</kbd> | shortcut to autofill. 
Linux | up arrow key | shortcut to autofill recent command.  
Linux | Ctrl X, <kbd>U</kbd> | Undo recent action. 
Linux | Ctrl + <kbd>W</kbd> | Cut. 
Linux | Ctrl + <kbd>Y</kbd> | Paste.
Linux | Right click mouse | Paste. 
Linux | cat filename | view contents of file. 
Linux | cat <filename>, select all with mouse, Alt + <kbd>W</kbd> | Ctrl + V to copy and paste contents outside of linux terminal e.g. to Visual Studio Code. 
Linux | cd | navigate to home directory.
Linux | cd.. | navigate up one directory. 
Linux | pwd | check current file path. 
Linux | ls -l | list all items in directory vertically. 
Linux | ls | list all items in directory horizontally. 
Linux | cp filename destination | copy file to specified destination. 
Linux | cp filename ~ | copy file to home directory. 
Linux | cp -R directoryname| copy directory. 
Linux | mv oldnamefile1 newnamefile1 | change name of file. 
Linux | rm filename | remove file.
Linux | rm -R directoryname | remove directory. 
Linux | g++ filename | compile/debug the code file. 
Linux | ./a.out < test filename | run test file. 
Linux | lpr filename | print file. 




