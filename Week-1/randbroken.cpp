// OUJIROBOTICA Coding 1 Spring 2026
// Random Numbers, Switch Statements and While Loops

// fill out the rest of the code so that it displays the words
    // "Random Numbers" to the console
    // then run it

#include <iostream>                  // in out stream, for sending text to the console.
#include <cstdlib>                   // for sramd and rand
#include <ctime>                     // for time

using namespace std;                 // so we don't have to type "std::" all the time.

// here is where we start the program
int main() {
    //only once, at the beginning of the program
    //seed the random number generator 
    srand(time(0)); 

   cout << "Random numbers!\n";

   cout << "Here is our first random number: " << rand() << ".\n"; // display random number 

   int counter = 0; 
   while(counter++ < 10) {                    // ++ = increment add one , if counter less than 10, run program
    int number = rand(); 
    int min = 50; 
    int max = 100;
    int range = max - min;                   //50
    int clampedNumber = (number % range) + min;

    cout << clampedNumber << endl;
   }

    // set variables 
    // the random number
    int randomRange = (rand() % 11) + 10;     // this gives us a number between 10 and 20 (inclusive)
    int number = (rand() % randomRange) + 1;  

    // the guess/input
    int guess = -1;

    int totalGuesses = 0;
   // start loop
   while(true) {
    // ask for the player's guess between 1 and 10 (inclusive) 
    cout << "I'm thinking of a number between 1 and " << randomRange << ", can you guess it? \n>>";
    // get player's guess/input
    cin >> guess;
    totalGuesses ++;
    // evaluate the player's guess for

        // too high
        if(guess > number) {
            cout << "Too high! \n";
            }

        // too low
        if(guess < number) {
            cout << "Too low! \n";
        }

        //correct!    
        if (guess = number) {
            cout << "That's right! You guessed correctly! \n";
            cout << "It only took you " <<totalGuesses << "guesses! \n";
                // break out of loop
                break;
        }
    }

    // if incorrect guess, keep looping!
   
    return 0;                        // end the program  
} 
