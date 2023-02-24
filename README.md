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
    * const or constexpr are capitalized e.g. TAX_RATE

    ```cpp
        constexpr double EARTH_GRAVITY { 9.8 };  // preferred use of const before type
        // Place const before the type (because it is more idiomatic to do so).
        // Const variables must be initialized when you define them
        // EARTH_GRAVITY, intercapped names with a ‘k’ prefix e.g. kEarthGravity, earthGravity.
        // Don’t use const when passing by value.
        // Any variable that should not be modifiable after initialization and whose initializer is known at compile-time should be declared as constexpr.
        // Any variable that should not be modifiable after initialization and whose initializer is not known at compile-time should be declared as const.
        
    ```
    
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

* **Always Initialize your variables upon creation**. Cout to get input, then set up variables, then cin to store:
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
        * These functions already return a value, hence, no parameters/arguments are applied to them in main function. 
    * Void functions 
        * don't have a return statement 
        * they have a cout statement 
        * called on it's own in main function to print
        * should not be called in cout again 
        * uses parameters/arguments (while return functions don't)

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

* Use functions for organization, reusability, testing (self contained, incremental development). 
* Groups of statements that appear more than once in a program should generally be made into a function. For example, if we’re reading input from the user multiple times in the same way, that’s a great candidate for a function. If we output something in the same way in multiple places, that’s also a great candidate for a function.

* Headers - to maximize the chance that missing includes will be flagged by compiler, order your #includes as follows:
    ```
    The paired header file
    Other headers from your project
    3rd party library headers
    Standard library headers
    The headers for each grouping should be sorted alphabetically
    ```

* Use parentheses to make it clear how a non-trivial expression should evaluate (even if they are technically unnecessary). For example, in the expression (2 + 3) * 4, the (2 + 3) part is evaluated first.
    * x = 2 + 3 % 4
    * x = (2 + (3 % 4))
    * NAO precedence: Not, And, Or, can use keyword or symbolic:
        * not !x
        * and x && y
        * or x || y
    * If same level, left to right
    * a || b && c || d;
    * (a || (b && c)) || d;

* If logical NOT is intended to operate on the result of other operators, the other operators and their operands need to be enclosed in parentheses.
    * logical NOT has a very high level of precedence, !x will check x first, rather than the statement 'x > y' 
    * Wrong: (!x > y) 
    * Correct: (!(x > y))

* When mixing logical AND and logical OR in a single expression, explicitly parenthesize each operation to ensure they evaluate how you intend.
    * Bad: value1 && value2 || value3 && value4, 
    * Better: (value1 && value2) || (value3 && value4)
    * value1 || value2 && value3
    * logical AND has higher precedence, evaluates as: value1 || (value2 && value3)

* Declare local variables as close to where they are used as possible is because doing so minimizes the amount of code you need to look through to understand what the variable does. 
    * Global variables are at the opposite end of the spectrum -- because they can be accessed anywhere, you might have to look through the entire program to understand their usage. Global variables also make your program less modular, less flexible, less reusable.

* If must use a constant variable,  it’s a better practice to “encapsulate” a constant variable

    ```cpp
        // For example, instead of:

        namespace constants
        {
            extern const double gravity { 9.8 }; // has external linkage, is directly accessible by other files
        }


        // Do this:
        namespace constants
        {
            constexpr double gravity { 9.8 }; // has internal linkage, is accessible only by this file
        }

        double getGravity() // this function can be exported to other files to access the global outside of this file
        {
            // We could add logic here if needed later
            // or change the implementation transparently to the callers
            return constants::gravity;
        }

    ```

* Loop variables are often given simple names, such as i, j, or k. However, if you want to know where in your program a loop variable is used, and you use the search function on i, j, or k, the search function will return half of the lines in your program! 
    * For this reason, some developers prefer loop variable names like iii, jjj, or kkk. Because these names are more unique, this makes searching for loop variables much easier, and helps them stand out as loop variables. 
    * An even better idea is to use “real” variable names, such as count, or a name that gives more detail about what you’re counting (e.g. userCount)

* Use break and continue when they simplify your loop logic:

    ```cpp
        // break and continue can help make loops more readable by keeping the number of nested blocks down and reducing the need for complicated looping logic.
        #include <iostream>

        int main()
        {
            int count{ 0 }; // count how many times the loop iterates
            bool keepLooping { true }; // controls whether the loop ends or not
            while (keepLooping)
            {
                std::cout << "Enter 'e' to exit this loop or any other character to continue: ";
                char ch{};
                std::cin >> ch;

                if (ch == 'e')
                    keepLooping = false;
                else
                {
                    ++count;
                    std::cout << "We've iterated " << count << " times\n";
                }
            }

            return 0;
        }


        // Here’s a version that’s easier to understand, using a break statement:

        #include <iostream>

        int main()
        {
            int count{ 0 }; // count how many times the loop iterates
            while (true) // loop until user terminates
            {
                std::cout << "Enter 'e' to exit this loop or any other character to continue: ";
                char ch{};
                std::cin >> ch;

                if (ch == 'e')
                    break;

                ++count;
                std::cout << "We've iterated " << count << " times\n";
            }

            return 0;
        }


        //------------------------------------------------------------------------------


    ```

* Break vs. Return

    ```cpp
        #include <iostream>

        int breakOrReturn()
        {
            while (true) // infinite loop
            {
                std::cout << "Enter 'b' to break or 'r' to return: ";
                char ch{};
                std::cin >> ch;

                if (ch == 'b')
                    break; // execution will continue at the first statement beyond the loop

                if (ch == 'r')
                    return 1; // return will cause the function to immediately return to the caller (in this case, main())
            }

            // breaking the loop causes execution to resume here

            std::cout << "We broke out of the loop\n";

            return 0;
        }

        int main()
        {
            int returnValue{ breakOrReturn() };
            std::cout << "Function breakOrReturn returned " << returnValue << '\n';

            return 0;
        }


        // Enter 'b' to break or 'r' to return: r
        // Function breakOrReturn returned 1

        // Enter 'b' to break or 'r' to return: b
        // We broke out of the loop
        // Function breakOrReturn returned 0

    ```

* Favor references over pointers unless the additional capabilities provided by pointers are needed.

<br>


### :x: AVOID
* Global variables are unacceptable. **Global constants are encouraged** e.g. GST used in several functions.
* Code or email, no more than 80 spaces (keep easy to read). 
* Avoid magic numbers (numbers plugged into code). Use constexpr variables instead. 
* Avoid using the comma operator, except within for loops.
* Avoid using operator== and operator!= to compare floating point values if there is any chance those values have been calculated.
* Never need a if statement for evaluating bool. 
    * Don’t add unnecessary == or != to conditions. It makes them harder to read without offering any additional value.

    ```cpp
        // We don’t need the if-statement in isAllowedToTakeFunRide(). The expression height > 140.0 evaluates to a bool, which can be directly returned.

        bool isAllowedToTakeFunRide()
        {
        std::cout << "How tall are you? (cm)\n";

        double height{};
        std::cin >> height;

        return (height > 140.0);
        }


        // You never need an if-statement of the form:

        if (condition)
        return true;
        else
        return false;


        // This can be replaced by the single statement return condition.


        Many new programmers will write statements like this one:

        if (b1 == true) ...
        This is redundant, as the == true doesn’t actually add any value to the condition. Instead, we should write:

        if (b1) ...
        Similarly, the following:

        if (b1 == false) ...
        is better written as:


        if (!b1) ...

    ```
* Keep the nesting level of your functions to 3 or less. If your function has a need for more nested levels, consider refactoring your function into sub-functions.
* Define variables in the most limited existing scope. Avoid creating new blocks whose only purpose is to limit the scope of variables.

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

* Parameters vs. Arguments. 
    * Parameters are stating the input type in original function. 
    * Arguments are values used in calling the functions. 

    ```cpp
    Here are some examples of functions with different numbers of parameters:

    // This function takes no parameters
    // It does not rely on the caller for anything
    void doPrint()
    {
        std::cout << "In doPrint()\n";
    }

    // This function takes one integer parameter named x
    // The caller will supply the value of x
    void printValue(int x)
    {
        std::cout << x  << '\n';
    }

    // This function has two integer parameters, one named x, and one named y
    // The caller will supply the value of both x and y
    int add(int x, int y)
    {
        return x + y;
    }
    An argument is a value that is passed from the caller to the function when a function call is made:

    doPrint(); // this call has no arguments
    printValue(6); // 6 is the argument passed to function printValue()
    add(2, 3); // 2 and 3 are the arguments passed to function add()


    #include <iostream>

    // This function has two integer parameters, one named x, and one named y
    // The values of x and y are passed in by the caller
    void printValues(int x, int y)
    {
        std::cout << x << '\n';
        std::cout << y << '\n';
    }

    int main()
    {
        printValues(6, 7); // This function call has two arguments, 6 and 7

        return 0;
    }

    // 6
    // 7


    // Example - create a void function, set up parameter, and apply argument in main function. 
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
        int num { getValueFromUser() };

        std::cout << num << " doubled is: " << num * 2 << '\n';

        return 0;
    }


    // Output line into its own function
    #include <iostream>

    int getValueFromUser()
    {
        std::cout << "Enter an integer: ";
        int input{};
        std::cin >> input;

        return input;
    }

    void printDouble(int value)       // This function now has an integer parameter
    {
        std::cout << value << " doubled is: " << value * 2 << '\n';
    }

    int main()
    {
        int num { getValueFromUser() }; // We set up an integer parameter

        printDouble(num);               // Called upon our void function, and applied integer parameter 

        return 0;
    }


    // More concise - putting the return function as parameter within the void function as an argument
    #include <iostream>

    int getValueFromUser()
    {
        std::cout << "Enter an integer: ";
        int input{};
        std::cin >> input;

        return input;                           // this is the 'int value' parameter, can put into void function
    }

    void printDouble(int value)
    {
        std::cout << value << " doubled is: " << value * 2 << '\n';
    }

    int main()
    {
        printDouble(getValueFromUser());

        return 0;
    }

    ```

* Forward declaration (function prototype). 
    * Generally functions at top, and main function at bottom. 
    * If cannot reorder the functions, then use forward declaration. 

    ```cpp 
    #include <iostream>

    int add(int x, int y); // forward declaration of add() (using a function declaration) (function prototype)

    int main()
    {
        std::cout << "The sum of 3 and 4 is: " << add(3, 4) << '\n'; // this works because we forward declared add() above
        return 0;
    }

    int add(int x, int y) // even though the body of add() isn't defined until here
    {
        return x + y;
    }

    ```

* std::cout, we’re saying “the cout that lives in namespace std“.
* Design steps:
    1. Step 1: Define your goal in one sentence. 
        e.g. Model how long it takes for a ball dropped off a tower to hit the ground.

    2. Step 2: Define requirements, constraints and capabilities to meet users' needs. 
        e.g. The user should be able to enter the height of the tower.

    3. Step 3: Define your tools, targets, and backup plan. 
        Defining what target architecture and/or OS your program will run on.
        Determining what set of tools you will be using.
        Determining whether you will write your program alone or as part of a team.
        Defining your testing/feedback/release strategy.
        Determining how you will back up your code.

    4. Step 4: Break hard problems into easy problems.
    
        * Top down method:
            Let’s take a look at an example of this. Let’s say we want to clean our house. Our task hierarchy currently looks like this:

            Clean the house
            Cleaning the entire house is a pretty big task to do in one sitting, so let’s break it into subtasks:

            Clean the house
            Vacuum the carpets
            Clean the bathrooms
            Clean the kitchen
            That’s more manageable, as we now have subtasks that we can focus on individually. However, we can break some of these down even further:

            Clean the house
            Vacuum the carpets
            Clean the bathrooms
            Scrub the toilet (yuck!)
            Wash the sink
            Clean the kitchen
            Clear the countertops
            Clean the countertops
            Scrub the sink
            Take out the trash

        * Bottom up method:
            As an example, many people have to go to work or school on weekdays, so let’s say we want to solve the problem of “go to work”. If you were asked what tasks you did in the morning to get from bed to work, you might come up with the following list:

            Pick out clothes
            Get dressed
            Eat breakfast
            Travel to work
            Brush your teeth
            Get out of bed
            Prepare breakfast
            Get on your bicycle
            Take a shower

            Get from bed to work
                Bedroom things
                    Turn off alarm
                    Get out of bed
                    Pick out clothes

            Bathroom things
                Take a shower
                Get dressed
                Brush your teeth

            Breakfast things
                Make coffee or tea
                Eat cereal

            Transportation things
                Get on your bicycle
                Travel to work

    5. Sequence of events
        If we were writing a calculator, we might do things in this order:
        Get first number from user
        Get mathematical operation from user
        Get second number from user
        Calculate result
        Print result
        
* Implementation
    1. Step 1: Outlining your main function

        ```cpp
        int main()
        {
        //    doBedroomThings();
        //    doBathroomThings();
        //    doBreakfastThings();
        //    doTransportationThings();

            return 0;
        }

        Or in the case of the calculator:

        int main()
        {
            // Get first number from user
        //    getUserInput();

            // Get mathematical operation from user
        //    getMathematicalOperation();

            // Get second number from user
        //    getUserInput();

            // Calculate result
        //    calculateResult();

            // Print result
        //    printResult();

            return 0;
        }

        ```

    2. Step 2: Implement each function

        ```cpp
        #include <iostream>

        // Full implementation of the getUserInput function
        int getUserInput()
        {
            std::cout << "Enter an integer: ";
            int input{};
            std::cin >> input;

            return input;
        }

        int main()
        {
            // Get first number from user
            int value{ getUserInput() }; // Note we've included code here to test the return value!
            std::cout << value << '\n'; // debug code to ensure getUserInput() is working, we'll remove this later

            // Get mathematical operation from user
        //    getMathematicalOperation();

            // Get second number from user
        //    getUserInput();

            // Calculate result
        //    calculateResult();

            // Print result
        //    printResult();

            return 0;
        }

    ```

    3. Step 3: Final testing - test the whole program to ensure it works as intended. 

* Keep programs simple to start. Make your first goal as simple as possible, and within reach.
    * Add features over time. 
    * Focus on one area at a time. 
    * Test each piece of code as you go. 
    * Don't worry about perfecting early code. The first draft of a feature (or program) is rarely good. Furthermore, programs tend to evolve over time, as you add capabilities and find better ways to structure things. If you invest too early in polishing your code (adding lots of documentation, full compliance with best practices, making optimizations), you risk losing all of that investment when a code change is necessary. Instead, get your features **minimally working** and then move on. As you gain confidence in your solutions, apply successive layers of polish. Don’t aim for perfect -- non-trivial programs are never perfect, and there’s always something more that could be done to improve them. Get to **“good enough” and move on**.


* Debugging tactics:
    1. Commenting out sections of code to see if issue persists 
    e.g. if commenting out doMaintenance, the problem goes away, 
    then doMaintenance must be causing the problem, 
    and we should focus our attention there.
    if the problem persists (which is more likely), then we know doMaintenance wasn’t at fault

    ```cpp
        int main()
        {
            getNames(); // ask user to enter a bunch of names
        //    doMaintenance(); // do some random stuff
            sortNames(); // sort them in alphabetical order
            printNames(); // print the sorted list of names

            return 0;
        }

    ```


    2. Add cerr << validation/debug print statements to validate code flow. 
    (When adding temporary debug statements, it can be helpful to not indent them. This makes them easier to find for removal later)

    ```cpp 
        #include <iostream>

        int getValue()
        {
        std::cerr << "getValue() called\n";
            return 4;
        }

        int main()
        {
        std::cerr << "main() called\n";
            std::cout << getValue;

            return 0;
        }
    ```

    Now when these functions execute, they’ll output their names, indicating that they were called:

    Output:
        main() called
        1

    Now we can see that function getValue was never called. There must be some problem with the code that calls the function. 

    ```cpp 
        we forgot the parenthesis on the function call. It should be:

        #include <iostream>

        int getValue()
        {
        std::cerr << "getValue() called\n";
            return 4;
        }

        int main()
        {
        std::cerr << "main() called\n";
            std::cout << getValue(); // added parenthesis here

            return 0;
        }

    ```
    Output:
        main() called
        getValue() called
        4

    3. Add cerr << statements to print/validate values:

    ```cpp 
        #include <iostream>

        int add(int x, int y)
        {
        std::cerr << "add() called (x=" << x <<", y=" << y << ")\n";
            return x + y;
        }

        void printResult(int z)
        {
            std::cout << "The answer is: " << z << '\n';
        }

        int getUserInput()
        {
            std::cout << "Enter a number: ";
            int x{};
            std::cin >> x;
            return x;
        }

        int main()
        {
            int x{ getUserInput() };
        std::cerr << "main::x = " << x << '\n';
            int y{ getUserInput() };
        std::cerr << "main::y = " << y << '\n';

            std::cout << x << " + " << y << '\n';

            int z{ add(x, 5) };
        std::cerr << "main::z = " << z << '\n';
            printResult(z);

            return 0;
        }

    ```
        Output:

        Enter a number: 4
        main::x = 4
        Enter a number: 3
        main::y = 3
        add() called (x=4, y=5)
        main::z = 9
        The answer is: 9


    4. A breakpoint is a special marker that tells the debugger to stop execution of the program at the breakpoint when running in debug mode.

* Use **boolalpha** to print true or false instead of 0 or 1. 

    ```cpp
    #include <iostream>

    // returns true if x and y are equal, false otherwise
    bool isEqual(int x, int y)
    {
        return (x == y); // operator== returns true if x equals y, and false otherwise
    }

    int main()
    {
        std::cout << "Enter an integer: ";
        int x{};
        std::cin >> x;

        std::cout << "Enter another integer: ";
        int y{};
        std::cin >> y;

        std::cout << std::boolalpha; // print bools as true or false

        std::cout << x << " and " << y << " are equal? ";
        std::cout << isEqual(x, y); // will return true or false

        return 0;
    }


    /*
    Enter an integer: 5
    Enter another integer: 5
    5 and 5 are equal? true 


    Enter an integer: 6
    Enter another integer: 4
    6 and 4 are equal? false 
    */

    ```

* Four ways to do if statements:

    ```cpp 
        #include <iostream>

        bool isPrime(int x)
        {
            if (x == 2) // if user entered 2, the digit is prime
                return true;
            else if (x == 3) // if user entered 3, the digit is prime
                return true;
            else if (x == 5) // if user entered 5, the digit is prime
                return true;
            else if (x == 7) // if user entered 7, the digit is prime
                return true;

            return false; // if the user did not enter 2, 3, 5, 7, the digit must not be prime
        }

        int main()
        {
            std::cout << "Enter a number 0 through 9: ";
            int x {};
            std::cin >> x;

            if ( isPrime(x) )
                std::cout << "The digit is prime\n";
            else
                std::cout << "The digit is not prime\n";

            return 0;
        }

        /*

        Enter a number 0 through 9: 5
        The digit is prime

        */


        // MORE EFFICIENT METHODS

        // A. Using the logical OR (||) operator (5.7 -- Logical operators):

        bool isPrime(int x)
        {
            return (x == 2 || x == 3 || x == 5 || x == 7); // if user entered 2 or 3 or 5 or 7 the digit is prime
        }

        int main()
        {
            std::cout << "Enter a number 0 through 9: ";
            int x {};
            std::cin >> x;

            if ( isPrime(x) )
                std::cout << "The digit is prime\n";
            else
                std::cout << "The digit is not prime\n";

            return 0;
        }


        // B. Using a switch statement (7.4 -- Switch statement basics):

        bool isPrime(int x)
        {
            switch (x)
            {
                case 2: // if the user entered 2
                case 3: // or if the user entered 3
                case 5: // or if the user entered 5
                case 7: // or if the user entered 7
                    return true; // then the digit is prime
            }

            return false; // otherwise the digit must not be prime
        }


        int main()
        {
            std::cout << "Enter a number 0 through 9: ";
            int x {};
            std::cin >> x;

            if ( isPrime(x) )
                std::cout << "The digit is prime\n";
            else
                std::cout << "The digit is not prime\n";

            return 0;
        }
    ```

* Ternary Operator
    * variable = (condition) ? expressionTrue : expressionFalse; 
    * Always parenthesize the conditional part of the conditional operator, and consider parenthesizing the whole thing as well. 
    * Only use the conditional operator for simple conditionals where you use the result and where it enhances readability.


* Escape sequences uses back slash '\n' , not multicharacter literal '/n'.
* If using std::getline() to read strings, use std::cin >> std::ws input manipulator to ignore leading whitespace.
    ```cpp
        #include <string> // For std::string and std::getline
        #include <iostream>

        int main()
        {
            std::cout << "Enter your full name: ";
            std::string name{};
            std::getline(std::cin >> std::ws, name); // read a full line of text into name

            std::cout << "Enter your age: ";
            std::string age{};
            std::getline(std::cin >> std::ws, age); // read a full line of text into age

            std::cout << "Your name is " << name << " and your age is " << age << '\n';

            return 0;
        }


        // Now our program works as expected:

        // Enter your full name: John Doe
        // Enter your age: 23
        // Your name is John Doe and your age is 23

        // The std::ws input manipulator tells std::cin to ignore any leading whitespace before extraction. Leading whitespace is any whitespace character (spaces, tabs, newlines) that occur at the start of the string.

    ```
* x = x + 4; // add 4 to existing value of x
    * x += 4; // add 4 to existing value of x


* Modulus calculation formula: (Quotient × Divisor) + Remainder = Dividen
    * The modulus operator can also work with negative operands. x % y always returns results with the sign of x.
    * 2 / 4 is 0 (using integer division) remainder 2. Whenever the second number is larger than the first, the second number will divide the first 0 times, so the first number will be the remainder.

* Exponent operator: 
    ```cpp
        #include <cmath>

        double x{ std::pow(3.0, 4.0) }; // 3 to the 4th power
    ```

* ++x	Increment x, then return x
* x++	Copy x, then increment x, then return the copy

    ```cpp
        #include <iostream>

        int main()
        {
            int x{ 5 };
            int y{ 5 };
            std::cout << x << ' ' << y << '\n';                   // 5 5
        
            std::cout << ++x << ' ' << --y << '\n'; // prefix    // 6 4
        
            std::cout << x << ' ' << y << '\n';                  // 6 4
        
            std::cout << x++ << ' ' << y-- << '\n'; // postfix   // 6 4 

            // changes don’t show up until the next line, when x and y are evaluated again.
            std::cout << x << ' ' << y << '\n';                  // 7 3

            return 0;
        }

    ```

* !(x && y) is NOT the same thing as !x && !y. Unfortunately, you can not “distribute” the logical NOT in that manner.
    * De Morgan’s law tells us how the logical NOT should be distributed in these cases:
        * !(x && y) is equivalent to !x || !y
        * !(x || y) is equivalent to !x && !y
        * when you distribute the logical NOT, you also need to flip logical AND to logical OR, and vice-versa!

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



Alt + Shift + < > : to auto move up and down
c + S : to find keyword
C + R : to reverse search
C + G : to quit current command 
C + L: move cursor to center of screen

C + Z / FG : to sleep, unsleep

C + X pause, 2 : horizontal panes
C + X pause, 3: vertical panes
C + X pause, 1: 1 pane


C + X, u : to undo

C + K : to delete
C + Y : undo 


Shift + arrow down to highlight 
Ctrl + Space (at top of code) : to highlight


Ctrl + X, H to select all 
Ctrl + G, to kill

Ctrl + W : to cut
Ctrl + Y: to paste

type few letters, Alt + / : to autocomplete variables 
Ctrl + / : to undo 

Shift + Alt + % : query replace

Alt + X, type compile: 
` to jump to next error 
fix, repeat


Alt + X, type customize-themes: press enter 