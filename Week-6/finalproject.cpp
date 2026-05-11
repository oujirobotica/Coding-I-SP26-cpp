
//                _________________________________________________________________
//     /\__/\   / OUJIROBOTICA Coding 1 Spring 2026  
//  （　´∀｀）＜　MONSTER BATTLER - FINAL PROJECT!
//  （　　　） 　＼＿＿＿＿＿_________________________________________________________
//  ｜ ｜　|
// （ ＿_)＿）

// -----------------------------------------------------------------------------------------------

// REQUIREMENTS - Create a .cpp program that allows the player to 
    //      X - name a 'critter' (or 'monster', or 'robot', or 'slime', or 'puppy' - whatever you like!) 
    //      X - feed their critter
    //      X - train their critter (chance to increase health or damage)
    //      X - listen to their critter (display health, damage, and hunger)
    //      X  - battle other critters - attack, heal, run away 

// INCLUDE THE FOLLOWING FEATURES  
    //      X - a randomized list of names must be read from a separate text file
    //      X - setters and getters must be implemented for all class variables (class variables should be private)
    //      X - critter class must have a constructor
    //      X  - each battle or training adds 1 to the critter's hunger                          >> NOTE: TRAINING CODE COMPLETE, ADD TO BATTLE CODE 
    //      X  - if their hunger is greater than 10, they can't train or battle.                 >> NOTE: TRAINING CODE COMPLETE, ADD TO BATTLE CODE
    //      X  - if their hunger is greater than 5, they'll mention it each time they train or battle    >> NOTE: ADD TO BATTLE CODE


// HINTS 
    // Variables for your critter may include health, damage, hunger, isAlive, mustFeed.
    // Functions for your critter may include hello(), train(), feed(), battle(), and more.
    // Submit to assignment page a link to your files (final.cpp and names.txt) on github.


// -----------------------------------------------------------------------------------------------------------------------------------------------------

// INCLUDE LIBRARIES! // ---------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <vector>    
#include <fstream>     // allow writing / reading of files, save state
#include <ctime>       // get current time from computer, use to randomize number 
#include <cstdlib>     // for random numbers
#include <algorithm>   // tool for data manipulation 

//also use namespace std, increases efficiency of code

using namespace std;                 // remove need to type out std:: before calling from libraries 


// SET CLASSES! // ------------------------------------------------------------------------------------- 

// global vector for randomized  enemy names system

    vector<string> names;

// BASEPETCOM CLASS - Player's Character

    class basePetcom
    {

        private: 

            // VARIABLES // 

            string name;
            int health;
            int attack;
            int hunger;
            bool isAlive;

        //

        public:
            

            // ---- >> CONSTRUCTORS << ----- //

            // CONSTRUCTOR 1 
                
                basePetcom(string givenName, int givenHealth, int givenAttack, int givenHunger, bool givenisAlive) 
                {
                    name = givenName;    
                    health = givenHealth;
                    attack = givenAttack;
                    hunger = givenHunger;       
                    isAlive = givenisAlive;     
                    //status();               
                }
            

            // CONSTRUCTOR 2 

                basePetcom() 
                {
                    name = "Petcom";   
                    health = 15;     
                    attack = 5;        
                    hunger = 0;    
                    isAlive = true;
                    //status();              
                } 
            
            
            // ----- >> FUNCTIONS << ----- //

                // DISPLAY STATUS - display health, attack, hunger

                void status()
                {
                    // petcom's variable list
                    cout << "NAME:" << name << "\n"; 
                    cout << "HEALTH:" << health << "\n";
                    cout << "ATTACK:" << attack << "\n"; 
                    cout << "It seems to be..."; 

                    // if hunger > 10, starving - cannot train or battle
                    if(hunger > 10) 
                    { cout << "starving!\n";}
                    
                    // if hunger > 5, hungry - mentions each training / battle attempt
                    else if(hunger > 5) 
                    {cout << "hungry!\n";} 

                    // if hunger > 0, satiated - pet can eat 
                    else if (hunger > 0)
                    {cout << "satiated!\n";}
                    
                    // if hunger = 0, full - pet cannot eat anymore 
                    else
                    {cout << "full!\n";}
                
                }

                
                // FEED PET - increase hunger value
                // increase hunger value by 2 if pet's hunger x > 1

                void feed()
                {
                    // is hunger less than 1? 

                    // if yes,
                    if(hunger < 1)  
                    {
                        cout << "You try offering " << name << " a treat...\n"; 
                        cout << "But it doesn't seem very hungry, right now.\n";
                    }
                    
                    // if no,
                    else          
                    {
                        cout << "You give " << name << " a treat!\n"; 
                        cout << "It seems a little less hungry now.\n";    
                        
                        // decrease hunger by 2 
                        hunger -= 2;

                        // ensure hunger cannot dip below 0 
                        if(hunger < 0)
                        { hunger = 0;}
                    }

                } 
                

                // TRAIN PET - increase health/attack, costs hunger
                // 1/3 chance of health/attack/fail

                void train()
                {

                    // add + 1 to hunger 
                    hunger += 1;


                    // commence training!     
                    cout << "------------------------------------------------\n";
                    cout << " [ " << name << " flings itself at the dummy...! ]\n";

                    // roll for result (1/3 chance)
                    int roll = rand() % 3;

                    
                        // outcome A - miss (no stat increase)
                        if (roll == 0)
                        {
                            cout << name << " trips, missing the dummy completely...\n";
                            cout << ">> TRAINING FAILED! - better luck next time! <<\n";
                            cout <<"------------------------------------------------\n";
                        }

                        // outcome B - dummy hit (health +5)
                        else if (roll == 1)
                        {
                            health += 5;
                            cout << name << " lunges forward - but the dummy strikes back!\n";
                            cout << "luckily, it endures the hit! " << name << " looks a lot tougher now! \n";
                            cout << ">> TRAINING SUCCESSFUL! - HEALTH UP! (+5) << \n";
                            cout << "------------------------------------------------\n";
                        }
                
                        // outcome C - pet hit (attack +2)
                        else
                        {
                            attack += 2;
                            cout << name << " swiftly attacks before the dummy can notice! \n";
                            cout << "the dummy is defeated! " << name << " looks a lot sharper now! \n";
                            cout << ">> TRAINING SUCCESSFUL! - ATTACK UP! (+2) << \n";
                            cout << "------------------------------------------------\n";
                        }

                 
                }



            

            // ----- >> GETTERS << ------- // 

                // getName
                string getName() 
                {return name;}

                // getHealth
                int getHealth()
                {return health;}

                // getAttack
                int getAttack()
                {return attack;}

                // getHunger
                int getHunger()
                {return hunger;}

                // getisALive
                bool getisALive()
                {return isAlive;}
               
                

            

            // ----- >> SETTERS << ------- //

                // setName
                void setName(string givenName)
                {
                    // restrict character name to 8 characters or less 

                    if(givenName.size() <= 8) 
                    {name = givenName;}

                    else 
                    {cout << "error: name is too long.\n";}

                }

                // setHealth
                void setHealth(int givenHealth) 
                { 
                    // if health falls to zero, set isAlive = false
                    // used for game over

                    health = givenHealth;

                    if (health <= 0)
                    {
                        health = 0;
                        isAlive = false;
                    }
                
                }   

                // setAttack
                void setAttack(int givenAttack) 
                { attack = givenAttack;}   

                // setHunger
                void setHunger(int givenHunger) 
                { hunger = givenHunger;}   
                
                // setisALive
                void setisALive(int givenisAlive)
                {
                    // if health > 0, set to true
                   // if health = 0 , set to false -> end game

                }   

            


        



    };


// BASEENEMY CLASS - Opponent Character
    
    class baseEnemy 
    {

        public: 

            // VARIABLES // 

                string name;
                int health;
                int attack;

            // ---- >> CONSTRUCTORS << ----- //

                baseEnemy()
                { 
                    
                    cout << "A wild PETCOM appears!\n";

                    
                    name = names[rand() % names.size()];    // randomize names 
                    health = rand() % 7 + 4;                // randomize health 
                    attack = rand() % 3 + 3;                // randomize atk 
                    

                }

            // ----- >> FUNCTIONS << ----- //    

                // ENEMY STATUS //
                
                void enemystatus()
                {
                    // upon enemy encounter, announce name and stats.

                    cout << "Analyzing enemy PETCOM...\n";
                    cout << "The wild " << name << " has " << health << " health ";
                    cout << "and " << attack << " attack!.\n"; 
                }

        };




// PROGRAM START ! // ------------------------------------------------------------------------------------- 

    int main () 
    {
        
        cout << "==========================================================================================\n";
        cout << "                                 DIGITAL FIGHTER PETCOM MKI                              \n";
        cout << "==========================================================================================\n";
       
        cout << "Deep within your operating system lie an incredible ecosystem teeming with digital life! \n";
        cout << "These electronic organisms - PETCOM, as we've called them, are extremely elusive.\n";
        cout << "Under normal circumstances, there's little means of accessing their domain...\n";
        cout << "But, with the invention of this novel technology, the PETCOM TERMINAL - \n";
        cout << "the gap between the world of PETCOM and humble PC owner has finally been bridged.\n";
        cout << "From here, you may adopt a PETCOM of your very own.\n";
        cout << "Go forth! Feed them, train them, care for them, and maybe one day...\n";
        cout << "You'll become the world's very first PETCOM master!\n";

        cout << "==========================================================================================\n";
    
    
        srand(time(0));                                                 // seed the random number generator
        ifstream file("enemynames.txt");                                // load enemy names from enemynames.txt file
        string input;                                                   // allow string input

        // load enemy names from enemynames.txt file
        string tempName;                                               // stores names from file
        while(getline(file, tempName))                                 // read names from file
        {names.push_back(tempName);}                                   // add names to vector 
        file.close();                                                  // close file


        // START HERE //

            // CREATING AND NAMING THE PETCOM 
            
                cout << "You've found an egg! It looks like it's hatching!\n";
                cout << "Press Enter to continue...\n";
                getline(cin, input);
            
                // spawn pet

                basePetcom petcom;

                // allow player to name the pet... 

                    cout << "-------------------------------------------------------\n";
                    cout << petcom.getName() << " stares at you expectantly...\n";
                    cout << "I think it wants you to give it a name!\n";
                    cout << "-------------------------------------------------------\n";

                    cout << "> Would you like to give it a nickname?\n";
                    cout << "reply 'yes' or 'no'. \n";

                    // ask user if they'd like to name their pet 

                    getline(cin, input);                                           
            
                    // if YES,

                    if(input == "yes") 
                    {

                        cout << "-------------------------------------------------------\n";
                        cout << "What would you like to name your new Petcom?\n";
                        cout << "-------------------------------------------------------\n";


                        getline(cin, input);
                        petcom.setName(input);

                        cout << "-------------------------------------------------------\n";
                        cout << petcom.getName() << ", huh? I think it likes it!\n";
                        cout << "Take good care of " << petcom.getName() << "! \n";
                        cout << "-------------------------------------------------------\n";
                        cout << "Press Enter to continue...\n";
                        getline(cin, input);


                    }

                    // if player DOES not want to name petcom...
                    else
                    {
                        cout << "-------------------------------------------------------\n";
                        cout << petcom.getName() << " looks a bit disappointed...\n";
                        cout << "It will keep it's default name for now.\n"; 
                        cout << "-------------------------------------------------------\n";
                        cout << "Press Enter to continue...\n";
                        getline(cin, input);
                    }
    
            
        // BEGIN LOOP!

            // create variable 'turns' and set it to 0.
            int turns = 0;

            // run loop infinite number of times until player quits. 

                while(turns < 1)
                {

                    // ask the player that for their next action

                    cout << "> What would you like to do now?\n";
                    cout << "You may do the perform one of the following actions:\n";
                    cout << "'status', 'feed', 'train', 'battle' , or 'quit'. \n";

                    // get input from player 

                    getline(cin, input);

                    // enact action...

                        // if player types "status", run status function 

                            if(input == "status") 
                            {
                                cout << "-------------------------------------------------------\n";
                                petcom.status();
                                cout << "-------------------------------------------------------\n";
                                cout << "Press Enter to continue...\n";
                                getline(cin, input);
                                
                            }
                        
                        // if player types "feed", run feed function 

                            else if(input == "feed") 
                            {
                                cout << "-------------------------------------------------------\n";
                                petcom.feed();
                                cout << "-------------------------------------------------------\n";
                                cout << "Press Enter to continue...\n";
                                getline(cin, input);
                                
                            }

                        // if player types "train", run hunger check, then run training system

                            else if(input == "train") 
                            {   
                                // display training introduction

                                cout << "-------------------------------------------------------\n";
                                cout << "A sapient training dummy appears!\n"; 
                                cout << "It dances from left to right, as if to taunt you!\n"; 
                                cout << "You order your Petcom to attack the training dummy!\n"; 
                                cout << "-------------------------------------------------------\n";
                                cout << "Press Enter to continue...\n";
                                getline(cin, input);

                                // block training if pet hunger > 10 

                                if (petcom.getHunger() > 10)
                                {
                                    cout <<"-------------------------------------------------------\n";
                                    cout << petcom.getName() << " is starving, and collapses from exhaustion!\n";
                                    cout << "You feel a bit guilty...maybe I'm pushing it too hard?\n";
                                    cout <<"-------------------------------------------------------\n";
                                }

                                
                                // run training system!

                                else
                                {  
                                    // before starting, display warning if pet hunger > 5

                                    if (petcom.getHunger() > 5)
                                    {
                                        cout << "-------------------------------------------------------\n";
                                        cout << petcom.getName() << " looks hungry, but pushes through anyway.\n";
                                        cout << "it's best to feed it after this!\n";
                                        cout << "-------------------------------------------------------\n";
                                        cout << "Press Enter to continue...\n";
                                        getline(cin, input);
                                    
                                    }

                                    // initiate training function

                                    petcom.train();

                                }

                
                                cout << "Press Enter to continue...\n";
                                getline(cin, input);

                            }

                        
                        // if player types "battle", run hunger check, then run battle system


                            else if(input == "battle") 
                            {

                                // block combat if pet hunger > 10 

                                if(petcom.getHunger() > 10)
                                {   
                                    cout << "-------------------------------------------------------\n";
                                    cout << petcom.getName() << " is too starved to fight!\n";
                                    cout << "You really should feed it, first...\n";
                                    cout << "-------------------------------------------------------\n";
                                    cout << "Press Enter to continue...\n";
                                    getline(cin, input);
                                }

                                // run battle system!

                                else
                                {   
                                    // before starting, display warning if pet hunger > 5

                                    if ( petcom.getHunger() > 5)
                                    {
                                        cout << "-------------------------------------------------------\n";
                                        cout << petcom.getName() << " is hungry, but fights on anyway!\n";
                                        cout << "-------------------------------------------------------\n";
                                        cout << "Press Enter to continue...\n";
                                        getline(cin, input);
                                    }

                                    cout << "-------------------------------------------------------\n";

                                    // create enemy from baseEnemy blueprint

                                    baseEnemy enemy;

                                    // announce fight

                                    cout << "Go, " << petcom.getName() << "!\n";

                                    cout << "-------------------------------------------------------\n";
                                    cout << "Press Enter to continue...\n";
                                    getline(cin, input);

                                    // show enemy stats

                                    cout << "-------------------------------------------------------\n";
                                    enemy.enemystatus(); 
                                    cout << "-------------------------------------------------------\n";
                                    cout << "Press Enter to continue...\n";
                                    getline(cin, input);

                                    // begin battle loop!
                                    
                                    while(enemy.health > 0 && petcom.getHealth() > 0)
                                    {   

                                        // ask player to choose an action, get input!

                                            cout << "-------------------------------------------------------\n";
                                            cout << "Choose an action: 'attack', 'heal', or 'run'\n";
                                            getline(cin, input);
                                            cout << "-------------------------------------------------------\n";

                                            // if pet attacks,
                                            
                                            if(input == "attack")
                                            {
                                                enemy.health -= petcom.getAttack();
                                                cout << petcom.getName() << " attacks for " << petcom.getAttack() << " damage!\n";

                                            }

                                            // if pet heals,

                                            else if(input == "heal")
                                            {

                                                //restore 2 health
                                                petcom.setHealth(petcom.getHealth() + 2);
                                                cout << petcom.getName() << " restored 2 health!\n";

                                            }

                                            // if pet runs,

                                            else if(input == "run")
                                            {
                                                cout << petcom.getName() << " got away safely!\n";

                                                break;

                                            }

                                            // if player types something else,

                                            else 
                                            {  cout << "Unknown action!\n"; }


                                        // enemy is defeated...
                                            
                                            // when enemy health at 0
                                            // increase pet hunger by 1
                                            // break loop 

                                            if(enemy.health <= 0)
                                            {
                                                cout << enemy.name << " is defeated!\n";
                                                cout << "-------------------------------------------------------\n";
                                                petcom.setHunger(petcom.getHunger() + 1);
                                                cout << "Press Enter to continue...\n";
                                                getline(cin, input);
                                                break;
                                            }

                                        // enemy attacks player petcom... 

                                            int damageTaken = enemy.attack;

                                            petcom.setHealth(petcom.getHealth() - damageTaken);
                                            
                                            cout << enemy.name << " strikes back for " 
                                            << damageTaken << " damage!\n";

                                        // player petcom defeated...

                                            if(!petcom.getisALive())
                                            {

                                                // announce game over
                                                cout << "-------------------------------------------------------\n"; 
                                                cout << petcom.getName() << " tumbles over, dissolving into data...\n";
                                                cout << petcom.getName() << " has been defeated.\n";
                                                cout << "-------------------------------------------------------\n";
                                                cout << "GAME OVER!\n";
                                                cout << "Press Enter to continue...\n";
                                                getline(cin, input); 
                                                
                                                // exit the game
                                                cout << "==================================================================================\n";
                                                cout << "Shutting down PETCOM terminal...\n";
                                                cout << "Try to be more careful next time, okay? - Made with <3 by OUJISOFT! 2026\n";
                                                cout << "==================================================================================\n";
                                                exit(0);
                                            }

                                    } 

                                    cout << "-------------------------------------------------------\n";

                                }


                            }


                        // if player types "quit", exit game

                        else if(input == "quit") 
                        {
                            cout << "-------------------------------------------------------\n";
                            cout << "> Are you sure you want to exit?\n";
                            cout << "reply 'yes' or 'no'. \n";

                            getline(cin, input);

                            if(input == "yes") 
                            {
                            
                                cout << "==================================================================================\n";
                                cout << "Shutting down PETCOM terminal...\n";
                                cout << "Thank you for playing! - Made with <3 by OUJISOFT! 2026\n";
                                cout << "==================================================================================\n";
                                break;
                            

                            }

                    
                        }

                        else
                        {cout << "Unknown command!\n";}


                }
            
            


     return 0;

    }


// cd  C:\Users\asksa\Github\Coding-I-SP26-cpp\Week-6
// cl /EHsc finalproject.cpp
// finalproject
