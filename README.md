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

<br>
----

### :x: AVOID
* Global variables are unacceptable. **Global constants are encouraged** e.g. GST used in several functions.

<br>
---- 

### :desktop_computer: Linux Terminal Commands 

Context | Keyboard Shortcut | Purpose
---- | ---- | ----
In Emacs | Alt + <kbd>X</kbd>, type Compile | to compile/debug within the emacs editor 
In Emacs | Ctrl + <kbd>X</kbd>, ` | to jump to error. 
In Linux | Ctrl X, <kbd>U</kbd> | Undo recent action. 
In Linux | Ctrl + <kbd>W</kbd> | Cut. 
In Linux | Ctrl + <kbd>Y</kbd> | Paste.
In Linux | Right click mouse | Paste. 
In Linux | cat <filename>, select all with mouse, Alt + W | Ctrl + V to copy and paste contents outside of linux terminal e.g. to Visual Studio Code. 
In Linux | cd | navigate to home directory.
In Linux | cd.. | navigate up one directory. 
In Linux | pwd | check current file path. 
In Linux | ls -l | list all items in directory vertically. 
In Linux | ls | list all items in directory horizontally. 
In Linux | cp <filename> <destination> | copy file to specified destination. 
In Linux | cp <filename> ~ | copy file to home directory. 
in Linux | g++ <filename> | compile/debug the code file. 
In Linux | ./a.out < <test filename> | run test file. 
In Linux | lpr <filename> | print file. 

