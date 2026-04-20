//                _________________________________
//     /\__/\   / OUJIROBOTICA Coding 1 Spring 2026 
//  （　´∀｀）＜　My first C++ Program! :D
//  （　　　） 　＼＿＿＿＿＿________________________
//  ｜ ｜　|
// （ ＿_)＿） 

// **note to self, use camelCase for variables
// **variables declared at the top is best practice.  
// ctrl/ to comment out lines

// --------------------------------------------------------------------------------------------

// ~ WHAT IS CODE, ANYWAY? ~ //
   //   code is the means through which we give instructions to a computer!
   //   code is saved as a .cpp format, but first must be compiled into .exe format to run.

// ~ HOW TO COMPILE CODE! ~ //
   //   1. open the 'Developer Command Prompt for VS 2022'
   //   2. type 'cd' (change directory) then paste file location to navigate there
   //   3. type 'cl /EHsc filename.cpp' (compile & safeguard) to compile into an .exe (ex. 'main.cpp')
   //   4. type 'filename' to run the .exe (ex.'main'.)

// --------------------------------------------------------------------------------------------

// ~ BASIC GUIDE TO SYMBOLS! (for personal reference) ~ //
    //  1. // - comment. use this to write lil notes - pretty obvious!
    //  2. #  - preprocessor. tells compiler to do something before building program - often used w/ include
    //  3. ;  - end of statement. ends every statement, similar to a period.
    //  4. <> - call a library. 
    //  5. () - call a function. (optionally pass on info)
    //  6. [] - call array / index.
    //  7. "" - quotes. may be used to for communication of literal text. 
    //  8. {} - grouping. tells compiler everything inside braces is a unit.
    //  9. << & >> - input and output operators. used alongside cin and cout to transfer data between prompt and code. 
    //  10. :: - specifies location of object. text before = location, text after : = object 

// --------------------------------------------------------------------------------------------

// ~ BABY'S FIRST CODE - HELLO PLAYER! ~ //


// include LIBRARIES! //
#include <iostream>                          // call in out stream - allows us to send text to console!
#include <string>                            // call text library - for playerName variable
using namespace std;                         // to reduce use of std:: when calling libraries

// program START! //
int main() {                                 // start program

    // declaring and define VARIABLES!
    string playerName;                             // specify variable name of string as playerName

    // ask the player for their name
    cout << "What is your name, player?\n";        // send text to console 

    // receive response of player and assign to value of playerName 
    cin >> playerName;                             // receive response from console, assign to variable playerName
    
    // greet the player by their specified name
    cout << "Hello " << playerName << ".\n" << endl;

    return 0;                              // end the program  
} 


// ------------------------------------------------------------------------------
// ~ TUTORIAL: LIBRARIES & HOW TO USE EM ~ //

    //  libraries are pre-built pieces of code that may serve particular functions
    //  the standard library (std) is a set collection of libraries that come with C++ 

    //  to use a LIBRARY, type '#include <library>'. call before starting program!
    //  source library of a library may be specified with :: after include (ex. std::cout = use cout from standard library)
    //  for cleaner code, 'using namespace std' in place of :: (reduces frequency)
    //      #include - allows utilization of libraries (ex. #include <string>)
    //      <string> - calls text-handling library 
    //      <iostream> - calls input/output stream library, 'io' = in/out!

// ------------------------------------------------------------------------------
// ~ TUTORIAL: STARTING & ENDING PROGRAMS //

    // to START PROGRAM, type ' int main(){ '
    // this creates a framework to begin and end the compiled code.
    //      main() = tells system where to begin reading
    //      int = exit report, requires a value at the end
    //      do this after establishing your libraries!

    // to END PROGRAM, type ' return 0 ' 
    //      this returns a value to int, ending the program
 
    // alternative given by nate (thanks nate!)
    //       void main(){ - alt start program
    //       return; - alt end program

// ------------------------------------------------------------------------------
// ~ TUTORIAL: SENDING TO AND FROM CONSOLE ~ //

    // to SEND TO CONSOLE FROM PROGRAM, type ' cout << '
    // if sending text, break with with \n before 2nd quote.
    //      ex. cout << "What is your name, player? \n"; 


    // to SEND FROM CONSOLE TO PROGRAM, type ' cin >> '
    //      ex. cin >> playerName;        

// cout << "Hello World!" << endl;  // cout = console out, endl = end line

// ------------------------------------------------------------------------------
