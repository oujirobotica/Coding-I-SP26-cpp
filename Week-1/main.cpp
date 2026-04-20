//                _________________________________
//     /\__/\   / OUJIROBOTICA Coding 1 Spring 2026  
//  （　´∀｀）＜　Variables and Logic 
//  （　　　） 　＼＿＿＿＿＿________________________
//  ｜ ｜　|
// （ ＿_)＿）

// ------------------------------------------------------------------------------

// include LIBRARIES! //

#include <iostream>                                                 // allows transmission of info to/from console
using namespace std;                                                // reduce use of std:: when calling libraries


// program START! //

int main() {                                                        // begin program

    cout << "Let's learn about variables and logic!\n";             // send text to console 

    // declaring and define VARIABLES! - default values!

    int playerAge = -1;                                             // create integer variable "playerAge" (sets default)
    string playerName = "Darth Vader";                              // create string variable "playerName" 
    float happinessPercent = 0.61f; //if percent, # between 0 - 1   // create float variable "happinessPercent"
    bool keepPlaying = true;                                        // create boolean variable "keepPlaying" 


    // ~ PLAYER AGE ~ //

        // if - if condition true, run this code!
        if(playerAge == -1) {                                        // if playerAge -1 (should be by true default)
        cout << "How old are you?\n";                                // send text to console 
        cin >> playerAge;                                            // set player response as value of playerAge

        
        // set if at less than/equal to 12.
        // player's age equal to/less than 12 -> print text, end game
        if(playerAge <= 12) {                                        // set t/f - if playerAge assigned by player less than / equal to 12, run
        cout << "I'm sorry, this game is for grown ups! \n";         // send text to console 
        return 0;                                                    // end program early                         
        } 
            // else - if previous statement false, continue code
            // player's age older than 12 -> print text 
            else { 
            cout << "Wow," << playerAge << " years, that is a long time! \n"; // send text to console 
            } 

    }                                                                // end of if(playerAge)

 
    // ~ PLAYER NAME ~ //

       // if - if user's name is Darth Vader...(runs automatically!)
        if(playerName == "Darth Vader") {                            //if playerName Darth Vader (should be by true default)
        cout << "is your name " << playerName << "?\n";              // ask player if their name is Darth Vader
        string input;                                                // create new string variable for user input
        cin >> input;                                                // get user input

        // the OR operator '||' means that if any test evaluates to true, the if statement is true
        if(input == "yes"|| input == "Yes" || input == "YES") {     // allow user to say yes 
            cout << "Well, that's convenient! \n";                  // send text to console 
        } 

        // else - if user's name is NOT Darth Vader...
        else
        {                                                         
        cout << "What is your name?\n";                            // send text to console 
        cin >> playerName;                                         // set input to playerName 
        } 

        cout << "Hello " << playerName << ".\n";                   // displays user's inputtedname 

    } // end of if(playerName)



    bool debug = false; // turn this on to debug the program

    // the AND operator '&&' requires that all tests are true. 
if (playerAge == 23 && playerName == "Emil") {
    debug =true; 
    cout << "Hello Creator. Debug mode is ON. \n";

} // end of if (age && name)

if(debug) {
    cout << "playerAge = " << playerAge << ".\n"; 
    cout << "playerName = " << playerName << ".\n"; 
    cout << "happinessPercent = " << happinessPercent << ".\n";
    cout << "keepPlaying = " << keepPlaying << ".\n"; 
} 

    return 0; 


} // end of main ()

// ----------------------------------------------------------------------------------

// just like a branch in unreal engine 