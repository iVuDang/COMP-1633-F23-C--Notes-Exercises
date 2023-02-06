# COMP-1633-F23-Cplusplus-Notes



## Coding Standards 

### :white_check_mark: GOOD 
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
* length of any line is to be less than or equal to **80 characters**. Should be shorter than this line:
//------------------------------------------------------------------------------

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

<br>

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

### :x: AVOID
* Global variables are unacceptable. **Global constants are encouraged** e.g. GST used in several functions.

<br>

---

### :desktop_computer: Linux Terminal Commands 

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




