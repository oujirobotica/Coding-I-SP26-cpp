
//                _________________________________________________________________
//     /\__/\   / OUJIROBOTICA Coding 1 Spring 2026  
//  （　´∀｀）＜　FAVORITE GAMES PROJECT!!!!!!!!!!!!!! (I had a lot of fun with this!)
//  （　　　） 　＼＿＿＿＿＿_________________________________________________________
//  ｜ ｜　|
// （ ＿_)＿）

// include iostream, string, vector, and algorithm libraries 

#include <iostream>   //allow for communication between program and console
#include <string>     //allows for the storage of text itself - game names, user commands 
#include <vector>     //allows for us to list & add/remove values from said list - list of games itself
#include <algorithm>  //allows us to sort the information within vector  

//also use namespace std, increases efficiency of code

using namespace std;                 // remove need to type out std:: before calling from libraries 

// program START!

int main()
{
 cout << "==================================================================================\n";
 cout << "                      GAME LISTER 5000 SUPER POTATO EDITION                       \n";
 cout << "==================================================================================\n";
 cout << "Hello, user!\n";
 cout << "This is a program that allows you to make a list of your favorite video games.\n";
 cout << "Or perhaps even your least favorite - I'm just a computer, I don't judge.\n";
 cout << "==================================================================================\n";
 cout << "                  List of Available Commands:\n";
 cout << "list   - Shows an alphabetically sorted list of your games! \n";
 cout << "edit   - Change the title of an existing game\n";
 cout << "add    - Add a new game to your list \n";
 cout << "remove - Remove a game from your list\n";
 cout << "exit   - Exit the Program\n";

        //------------- CREATE VARIABLES! ------------- //

        // create variable - vector holding strings for favorite game list 

        vector<string> favGames = {"Klonoa", "Monster Hunter", "Shin Megami Tensei", "Disgaea", "Final Fantasy 7"};        // variable that stores a list of favorite game names
        string input;                   // variable that stores user's text input
    

        //---------------- BEGIN LOOP! ---------------- //

        do
        {
                
             cout << "----------------------------------------------------------------------------------\n";
             cout << " What would you like to do? You can type any of the commands listed below.\n";
             cout << " 'list', 'edit', 'add', 'remove', 'exit'\n";
             cout << "----------------------------------------------------------------------------------\n";

            
             // get input from player

             getline(cin, input);

                    //  ------------------------------------ LIST ------------------------------------------ //

                        if(input == "list")
                        {
                            cout << "> Here is your current list of games...\n";
                            cout << "--------------------------------------\n";
                             // Sort favGames alphabetically 

                              sort(favGames.begin(), favGames.end());

                             // Display favGames to console

                                {
                                for (int i = 0; i < favGames.size(); i++)
                                cout << favGames [i] << endl;
                                }
            
                        }

                    //  ------------------------------------ EDIT ------------------------------------------ //

                        else if(input == "edit")
                        {
                            // DISPLAY LIST OF GAMES
                            cout << "> Here is your current list of games...\n";
                            cout << "--------------------------------------\n";
                            
                                // Sort favGames alphabetically 

                                    sort(favGames.begin(), favGames.end());

                                // Display favGames to console

                                    {
                                    for (int i = 0; i < favGames.size(); i++)
                                    cout << favGames [i] << endl;
                                    }

                            cout << "--------------------------------------\n";

                             // create interator

                                    vector<string> :: iterator iter;

                             // get user input - name of game user wants to edit 
                            
                                    cout << "[ Type the name of the game would you like to edit! ]\n";

                                    getline(cin, input);
                            
                             // find user's specified game using iterator

                                iter = find(favGames.begin(), favGames.end(), input);
                                if(iter != favGames.end ()) 
                                {
                                    cout << "You'd like to change the name of " << *iter << ", got it!\n";

                                  // get user input - desired name

                                        cout << " [  What would you like to change it to? ] \n";

                                        getline(cin, input);

                                  // change the name of selected game to user's input 
                                        
                                        *iter = input;

                                        cout << " [ Name has been changed to " << *iter << "! ]\n";

                                  // show updated list of favs to console!

                                        cout << "> Here is your updated list of favorites!\n";
                                        cout << "--------------------------------------\n";

                                        sort(favGames.begin(), favGames.end());
                                        
                                        for(int i = 0; i < favGames.size(); i++) {
                                        cout << "  " << favGames[i] << "\n"; }
                                    
    
                        
                                 //----> IF SPECIFIED NAME NOT FOUND...
                                        
                                        }
                                        else
                                        {
                                        cout << "Sorry, I can't find that game!\n";
                                
                                }      
                    
                         
                        }           
                    //  ------------------------------------ ADD ------------------------------------------ //

                         else if(input == "add")
                         {

                             // get user input - what game would you like to add?
                            
                                    cout << "[ Type the name of the game you'd like to add to your list! ]\n";

                                    string newGame;
                                    getline(cin, newGame);
                        
                             // add the new string to vector 

                                    favGames.push_back(newGame);

                             //  confirm new game has been added

                                    cout << "[New game has been added to list!]\n"; 

                             // show updated list of favs to console!

                                    cout << "> Here is your updated list of favorites!\n";
                                    cout << "--------------------------------------\n";

                                        sort(favGames.begin(), favGames.end());
                            
                                        for(int i = 0; i < favGames.size(); i++) {
                                        cout << "  " << favGames[i] << "\n"; }
                                       
                            }
                    
                    //  ------------------------------------ REMOVE ------------------------------------------ //

                        else if(input == "remove")
                        {
                            // DISPLAY LIST OF GAMES
                            cout << "> Here is your current list of games...\n";
                            cout << "--------------------------------------\n";
                            
                                // Sort favGames alphabetically 

                                    sort(favGames.begin(), favGames.end());

                                // Display favGames to console

                                    {
                                    for (int i = 0; i < favGames.size(); i++)
                                    cout << favGames [i] << endl;
                                    }

                            cout << "--------------------------------------\n";

                             // create interator

                                   

                                // get user input - name of game user wants to remove 
                            
                                    cout << "[ Type the name of the game would you like to remove! ]\n";

                                    getline(cin, input);
                                    
                                // find user's specified game using iterator

                                    auto iter = find(favGames.begin(), favGames.end(), input); 
                                    if(iter != favGames.end ()) 
                                    {
                                    cout << "You'd like to remove " << *iter << ", got it!\n";

                                  // remove from list 
                                    
                                        favGames.erase(iter);
                                    
                                  // send confirmation of removal to console  
                                        
                                        cout << "[ Game has been successfully removed! ]\n";

                                  // show updated list of favs to console!

                                        cout << "> Here is your updated list of favorites!\n";
                                        cout << "--------------------------------------\n";

                                        sort(favGames.begin(), favGames.end());
                                        
                                        for(int i = 0; i < favGames.size(); i++) {
                                        cout << "  " << favGames[i] << "\n"; }
                                    
    
                        
                                 //----> IF SPECIFIED NAME NOT FOUND...
                                        
                                    }
                                        else
                                        {
                                        cout << "Sorry, I can't find that game!\n";
                                        }
                                
                                }      

                    //  ------------------------------------ EXIT ------------------------------------------ //

                        else if(input == "exit")
                        {
                        cout << "==================================================================================\n";
                        cout << "See ya! - Made with <3 by OUJISOFT! 2026\n";
                        cout << "==================================================================================\n";
                        break;
                        }

            
        
                        
            
        }
        
        while(true);
 }