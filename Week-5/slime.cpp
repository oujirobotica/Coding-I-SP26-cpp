
//                _________________________________________________________________
//     /\__/\   / OUJIROBOTICA Coding 1 Spring 2026  
//  （　´∀｀）＜　Inheritance, Vectors of classes, and slime battling 
//  （　　　） 　＼＿＿＿＿＿_________________________________________________________
//  ｜ ｜　|
// （ ＿_)＿）

#include <iostream>
#include <string>
#include <vector>
#include <ctime>       //for random numbers
#include <cstdlib>     //for random numbers
#include <algorithm> 

using namespace std;

    // this is a global vector, visible is all functions.
    vector<string> names = {"Alfred", "Barbara", "Quentin" "Sandra", "Glenn", "Betty"};

  //-------------------------------------------------------------------------------

    class baseSlime 
    {

        public: 
        string name;
        int health;
        int damage;

        //default constructor
        
        baseSlime()
        {
            cout << "A new slime has been formed.\n";
            name = names[rand() % names.size()] + " Slime";
            health = rand() % 4 + 4; 
            damage = rand() % 3 + 3;

        }

        //announce name/health/dmg

        void hello()
        {
            cout << "I'm " << name << ", with " << health << " health ";
            cout << "and " << damage << " damage.\n";

        }

        //attack another slime
        //return true if opponent health <= (less than or equal to) 0

        bool attack(baseSlime& opponent)
        {
            opponent.health -= damage;
            cout << name << " has done " << damage << " damage to ";
            cout << opponent.name << "!\n";

            if(opponent.health <= 0) return true;
            else                     return false;

        }


    };

    //-------------------------------------------------------------------------------

    class bossSlime : public baseSlime 
    {
        public:
        int damageMultiplier = 3;

        //constructor for boss 
        //this runs after the baseSlime constructor runs 

        
        bossSlime()
        {
            //should inherit health 
            //should inherit the cout statement
            name = "boss";
            damage = damage * damageMultiplier;
        }
        
    
        bool attack (baseSlime& opponent)
        {
            //very straightforward to 'override' a function in the parent class.
            cout << "This is my boss attack!\n";
            opponent.health -= damage;
            cout << name << " has done " << damage << " damage to ";
            cout << opponent.name << "!\n";

            if(opponent.health <= 0) return true;
            else                     return false;

        }
    
        void taunt () 
        {
            cout << "I will crush your bones with my slime!\n";
        }


    };

    //-------------------------------------------------------------------------------

    // PROGRAM START! //

    int main () 
    {
        srand(time(0)); //seed the random number generator

        cout << "SLIME BATTLE!\n";

        //create a slime
        
        baseSlime gerald;
        gerald.name = "Gerald";
        gerald.hello();

        bossSlime destroyer;
        destroyer.name = "Destroyer";
        destroyer.hello();
        destroyer.taunt();

        cout << "Gerald is feeling a little silly...\n";
        gerald.attack(destroyer);

        cout << "Destroyer is enraged!\n";
        if(destroyer.attack (gerald))
        {
            cout << "Gerald is no more. DED.\n";
        }

        
        // create a vector of slimes
        // then pick two to fight
        // global variables
        // create a new vector of slimes with a size of 6. 


        vector<baseSlime> sludge(6);

        cout << "Here's our sludge of slimes:\n";
        for(auto& slime : sludge)
        {
            cout << slime.name << "\n"; 
        }

        random_shuffle(sludge.begin(), sludge.end());
        auto& a = sludge [0]; // a is equal to the first slime. 
        auto& b = sludge [1]; // b is equal to the second slime. 

        while(a.health> 0 && b.health > 0)
        {
            

         if (a.attack(b))
            {
                    {
                    cout << b.name << " has been defeated by ";
                    cout << a.name << ".\n";
                    }
            }

            
         else 
            {
                
                if (b.attack(a))
                    {
                    cout << a.name << " has been defeated by ";
                    cout << b.name << ".\n";
                    }
                    
            }


        }

     return 0;

    }
