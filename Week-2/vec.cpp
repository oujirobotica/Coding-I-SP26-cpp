//                ___________________________________
//     /\__/\   / OUJIROBOTICA Coding 1 Spring 2026  
//  （　´∀｀）＜　Vectors, Iterations, Algorithms, Erasing
//  （　　　） 　＼＿＿＿＿＿___________________________
//  ｜ ｜　|
// （ ＿_)＿）

// vector - list you can change the size of.
// iterator = sticky note? pointer that points to a spot in a vector

// TO COMPILE AND RUN, type 'cl /EHsc vec.cpp && vec' in cmd
// for windows, it's 'cl /EHsc vec.cpp && vec'

  // make a global-ish vector of favs
    // this allows us to see our changes through the loops
    //take about the 'auto' variable type 
    //alk about removing with .erase ()
    // sorting with sort 
    // then start homework 


#include <iostream>  // allows us to communicate with console
#include <string>    // for getline() - gets only strings
#include <vector>    // for vectors and iterators
#include <algorithm> // for find(), sort(), random_shuffle()

using namespace std;

int main(){
    cout << "Let's learn about vectors!\n";

    // this vector exists outside the do-while loops
    // because of this, it won't be destroyed every time we loop.

  vector<string> favGames = {"Zelda", "Mario", "Star Fox", "Kirby"};

    string input;
    // int numberInput  = stoi(input);

 vector<string> names; 

    do {
    cout << "What would you like to do?\n";
        cout << "You can type 'quit', 'push','find', 'remove'.\n";
        
        getline(cin, input);         //get input from player 

        if(input == "push") {
            cout << "Let's make our first vector of strings!\n";

            // vector<string> names; 

            // add some names with names.pushback()
            names.push_back("Finn");
            names.push_back("Lady Raincorn");
            names.push_back("Jake");
            names.push_back("The Lich");
            names.push_back("Lemongrab");
                cout << "here are your names! \n";
                for(int i=0; i < names.size(); i++) {
                    cout << names[i] << "\n";

                }

            cout << "There are " << names.size() << " names. \n\n";        

            cout << *(names.end() - 1) << " is a dick. Let's get rid of him.\n";  // de-reference end of list 

            names.pop_back();                      // pop_back() removes the last element from the vector.
            
            cout << "here are your names! \n";
            for(int i=0; i < names.size(); i++) {
            cout << " " << names[i] << "\n";
            }

    

    } // end of 'push'
    else if (input == "find") {                                         //every time code is run, vector creates string, so
        cout << "Let's try to use the find algorithm.\n";

        //using a collection initializer to add favs at creation of vector.
        vector<string> favs = {"Star Wars","Kill Bill","Ponyo"};

        // building an iterator. it points to a 'spot' in a vector.
        vector<string> :: iterator iter;

        cout << "here are your favs!\n";
        for(int i=0; i < favs.size(); i++) {
            cout << "    " << favs[i] << "\n";
        }

        // makes iter point at the first element in the vector
        iter = favs.begin();

        // the asterisk is a "dereference operator" ... so that we can get 
            // the value that the iter is pointing at. 
        cout << "iter is pointing at " << *iter << ".\n";

        iter += 1;

        cout << "Now iter is pointing at " << *iter << ".\n";

        cout << "What name would you like to select?\n";
        getline(cin, input);

        // use the find algorithm
        iter = find(favs.begin(), favs.end(), input);

        if(iter != favs.end ()) {
            cout << "We've found " << *iter << "!\n";
            cout << "Would you like to change this fav?\n";
            getline(cin, input);
            
            if (input == "yes") {
                cout << "What would you like to change this fav to?\n";
                getline(cin, input);

                *iter = input; // changing the fav.
            }
       

            cout << "here are your updated favs!\n";
            for(int i = 0; i < favs.size(); i++) {
                cout << "  " << favs[i] << "\n";
            }

        }

     
        else {
            cout << "We couldn't find that name.\n";
        }

    } 
     

        else if(input == "quit") {
            cout << "Thanks for playing!\n";
            break; 
        }


        else if (input == "remove") {
        cout << "Here are your favorite Games:\n";

        for (int i = 0; i < favGames.size(); i++) {
            cout << favGames [i] << endl;

        }

        cout << "What game would you like to remove from the list?\n";
        getline(cin, input);

        auto iter = find(favGames.begin(), favGames.end(), input); 

        if(iter != names.end ()) {
            cout << "We've found that name. removing now.\n";
            favGames.erase(iter);  // remove the element iter is pointing at 
        }


        else if(input == "remove") {
            // sort the favganes vector alphabetically.
            sort(favGames.begin(), favGames.end());

        }

        cout << "Here are your favorite Games:\n";
        for(int i=0; i < favGames.size(); i++) {
            cout << favGames[i] << endl;
        }

    } // end of remove 

        else {
            cout << "I didn't recognize that command.\n";

        }

    } while(input !="quit");

    // vectors work like arrays, but you can change their size.
    // create a new vector of strings


    return 0;
}


