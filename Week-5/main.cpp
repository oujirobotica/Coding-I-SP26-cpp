
//                _________________________________________________________________
//     /\__/\   / OUJIROBOTICA Coding 1 Spring 2026  
//  （　´∀｀）＜　Classes, Constructors, Getters and Setters, Instances 
//  （　　　） 　＼＿＿＿＿＿_________________________________________________________
//  ｜ ｜　|
// （ ＿_)＿）


// CLASSES - templates that allow us to bundle information together
    // classes allow us to create instances of an object from a blueprint.
    // member functions - functions that belong to the same class.
    // data members - variables that belong to the same class.
    // when classes are created, you must define both public and private elements.
    // "private:" defines the variables the class will possess. 
    // "public:" defines with how the class can do and how it's interacted with. 
    
// 


// CONSTRUCTORS - prescribe default values to an object when it's created 
    // is run automatically whenever an instance of a class is generated.
    // allows an object to be immediately valid and ready to use.
    // must have the name name as class 
    // may be overloaded, allowing for different class variants 
//


// GETTERS AND SETTERS
    //  Getters allow us to read a private variable
    //  Setters allow us to change/override private variables
//



// ------------------------------------------------------------------------------


// Establish libraries...

#include <iostream>
#include <string>
using namespace std;

// Let's create a class called robot!

// -----------------------------------------  CLASS - ROBOT  ----------------------------------------- //

    class robot 
    {


        private:

            // define the basic variables the class will have here.
            // these are called the class's "DATA MEMBERS"!    

            string name;                // robot may have a name value.
            int charge;                 // robot may have a charge value.
            int boredom;                // robot may have a boredom value.

        //
        

        public:

            // ---------------------------------------------------------------------- Constructors 

                // create CONSTRUCTORS to prescribe starting values to the variables here.
                // remember, it must have the same name as the same as the class!
                // alternate settings can be made with OVERLOADED constructors.


                //  >> CUSTOM Constructor / Inputted Settings 

                    // this constructor sets the created robot's variables to specific given values. 

                    robot(string givenName, int givenCharge, int givenBoredom) 
                    {
                    name = givenName;       // set robot name to provided value. 
                    charge = givenCharge;   // set robot charge to provided value.
                    boredom = givenBoredom; // set robot boredom to provided value.
                    status();               // print current state of robot's variables. 
                    }
                //

                //  >> DEFAULT Constructor / Default Settings

                    // this constructor sets the created robot's variables to generic values. 
                    // considered an overloaded constructor.

                    robot() 
                    {
                    name = "bot";          // set robot name to 'bot'.
                    charge = 10;           // set robot charge to '10'.
                    boredom = 0;           // set robot boredom to '0'.
                    status();              // print current state of robot's variables.   
                    } 

                //

            // -------------------------------------------------------------------  Member Functions

                // MEMBER FUNCTIONS are all the functions assigned to a given class.
                // these will be the functions that all members of your class may use. 


                // >> DISPLAY ROBOT STATUS 

                    void status() 
                    {
                        // announce variable values for robot's name and charge...
                            
                            cout << "My name is " << name << ", my charge is " << charge << ".\n"; 
                            cout << "I am feeling";                         
                
                        // announce how robot is feeling based on value of boredom value...

                                // if low boredom value (<5) - happy 
                                if(boredom < 5) 
                                { cout << "happy";}
                                

                                // if  medium boredom value (<10) - bored
                                else if(boredom < 10) 
                                {cout << "bored";} 
                                

                                // if high boredom value (<15) - frustrated
                                else if(boredom < 15) 
                                {cout << "frustrated";}


                                // if highest boredom value (<16) - enraged
                                else 
                                {cout << "ENRAGED";}
                                
                                cout << ".\n";
    
                    }
                
                //
            
                // >> START A NEW DAY, INCREASING BOREDOM 

                    // on every new day, increase boredom value by 2 

                    void newDay() 
                    {
                        boredom += 2;
                    }     
                // 


                // >> ROBOT PLAYS, REDUCING BOREDOM 

                    // allow robot to play, reduce boredom value by 1 

                    void play() 
                    {
                            boredom -= 1;
                    }
                //

            

        
            // ---------------------------------------------------------------------------- Setters 

                // >> setName

                    void setName(string givenName)
                    {
                    
                        if(givenName.size() <= 5) 
                        {name = givenName;}

                        else 
                        {cout << "error: name is too long.\n";}

                    }
                //

        
                // >> setCharge 

                    void setCharge(int givenCharge) 
                    {

                        if(givenCharge < 0)         // clamping value to not lower than 0
                        {charge = 0;}                           
                    
                        else if(givenCharge > 100)  // clamping not higher than 100
                        {charge = 100;}

                        else 
                        {charge = givenCharge;}
                    
                    }   
                //

                // >> changeCharge 

                    void changeCharge(int amount)
                    {
                        setCharge(charge += amount);
                    }   
                //

                

         // ------------------------------------ GETTERS ------------------------------------ //

            // >> getName
                string getName() 
                {
                    return name;
                }

            //

            // >> getCharge 

                int getCharge() 
                {
                    return charge;
                }
            //


            // >> getBoredom 
                
                int getBoredom() 
                {
                    return boredom;
                }

            //


        // END OF ROBOT CLASS
    };  // don't forget the semi-colon at the end



//------------------------------------------------------------------------------------------------------------------------


// PROGRAM START! 

int main() 
{



    cout << "Let's build some robots!\n";


    // MAKING INSTANCES USING CUSTOM CONSTRUCTOR //

        // to create an object, type the type of class you would like to use, followed by whatever you would like to name the instance. 
        // ex. we're using the class blueprint "robot" to create an instance named "nines".

        // after that, you can give values to be loaded into the constructor for the object that correspond to the class's variables. 
        // ex. name = R2-D2, charge = 45, boredom = 10 

        robot nines("9S", 45, 10);       // create robot instance called "nines" using custom values

        // nines.name = "9S";
        // nines.charge = 45;
        // nines.boredom = 10;

   // CHANGING VALUES USING SETTERS //

        // we don't have to specify the values to create an object though.
        // if you leave out the parenthesis, we can just create a default.
        
        robot toobee;                   // create robot instance called "toobee" using default values 

        // then, we can manually change the values ourselves using setters. 

        toobee.setName("2B");        // use the setter to manually change threepio's name value name value to "C-3PO"
        toobee.setCharge(2);            // use the setter to manually change threepio's charge value name value to "2"

        // all done!


    // USING GETTERS AND CHANGE FUNCTIONS //


        // getters can be used to retrieve the value of an instance's variable.

        // for example, let's get the name value of artoo and display it to the user
        // ex. artoo.getName()

        cout << "Here's nines: " << nines.getName() << ".\n";
        cout << nines.getName() << " notices that " << toobee.getName();
        cout << " doesn't have much battery left. Let's fix that.\n";

        // and now, let's get the charge value of threepio - if it's less than 15,
        // use a changeCharge to remove -1 charge from artoo
        // and add 1 to threepio. 

        while(toobee.getCharge() < 15) 
        {
        nines.changeCharge(-1);          // subtract 1 from charge
        toobee.changeCharge(1);       // add 1 to charge.
        }


        // display!

        cout << "threepio's charge is now " << threepio.getCharge() << ".\n";
        cout << "artoo's charge is now " << artoo.getCharge() << ".\n";


    // USING MEMBER FUNCTIONS //

        // recall that a member function are all the functions within a class.
        // try checking the status of nines and toobee!

        nines.status();
        toobee.status();

        // this creates a game loop. 

        string input = "";
        int turns = 0;

            // this while loop  continues to play an infinite number of times until the player quits. 

            while(true) 
            {
                while(turns < 3)
                {

                    // ask the player that they would like to do

                    cout << "what would you like to do?\n";
                    cout << "these are the following actions:\n";
                    cout << "play, status \n";

                    // get input from player 

                    getline(cin, input);

                    // if input = play , play function 

                    if(input == "play") 
                    {
                        cout << "let's play with " << nines.getName() << "!\n";
                        nines.play();
                    }
                    
                    // else if input = status , status function

                    else if(input == "status") 
                    {
                        nines.status();                 // TODO: add boredom to status.
                    }

                    // increase turn at the end 

                    turns++;

                }

                turns = 0;
                cout << "Do you want to keep playing?\n";
                getline(cin, input);
                
                if(input == "no") 
                {
                    break;
                }

                artoo.newDay();

            }

        return 0;


}

