
//                _________________________________________________________________
//     /\__/\   / OUJIROBOTICA Coding 1 Spring 2026  
//  （　´∀｀）＜　Writing to and reading from files.
//  （　　　） 　＼＿＿＿＿＿_________________________________________________________
//  ｜ ｜　|
// （ ＿_)＿）


// read - function that loads data from a file into a vector  (ifstream)
// write - data from a vector into a file (ofstream)

# include <iostream>    // allows for communication to/from console
# include <string>      // allows for the storage/use of text
# include <vector>      // allows for the creation of lists 
# include <fstream>     // file stream, allows program to open and make changes to files

using namespace std;

// ---------------------------------- READING - PRINTING --------------------------------- 


void read(string path = "save.txt")              // read from tile (save.txt)
    {
     // define variables and try to file

            string line;                                        // create variable to store each line of text
            ifstream readFile(path);                            // attempt to open file at specified path

     // if the file is opened successfully...

        if(readFile.is_open())        

        {
            cout << "The file is open.\n"; 

            while(getline(readFile, line))                      // read the the file 
            {
                cout << line << endl;                           // print content of file to console 
            }
        }

     // if the file IS NOT successfully opened...

        else 
        {
            cout << "Couldn't open that file.\n";
        }

     // after we're done with the file, close it 

        readFile.close();                                      // close the file
    }                                         

 // ---------------------------------- READING - LOADING FILE INTO VECTOR --------------------------------- 


    void read(vector<string>& vec, string path = "save.txt")  // load data from file into vector
    {
     // define variables and try to file
    
            string line;                                      // creates variable to store each line of text
            ifstream readFile(path);                          // attempt to open file at specified path

     // if the file is opened successfully...

        if(readFile.is_open())                              
        {
            cout << "The file is open.\n";

            while(getline(readFile, line))                    // read the the file 
                vec.push_back(line);                          // add each line to the vector
            
        }


     // if the file IS NOT successfully opened...

        else
        {
            cout << "Couldn't open that file.\n";
        }

     // after we're done with the file, close it 
        readFile.close();                                     // close the file

    }


 // ---------------------------------- WRITING - SAVING VECTOR TO FILE --------------------------------- 

    
    void write(vector<string>& vec, string path = "save.txt")  // saves vector of strings to file
    {
     
     ofstream writeFile(path);                                 // create file-writing object, open file at specified path 


     // if the file is opened successfully...

     if(writeFile.is_open())                                 
        {

            //cout << "the write file is open.]\n";

            for(int i = 0; i < vec.size(); i++)
            {
                writeFile << vec[i] << endl;
            }

        } 
    
     //if the file is NOT opened successfully...

     else 
        {
            cout << "Couldn't open new writeFile.\n";
        }


     // after we're done with the file, close it             
          writeFile.close();                                   // close the file

    }
 

    //---------------------------------------- USER CONTROL --------------------------------------------


 // START PROGRAM HERE! // 

 int main () 
    {
     cout << "Let's write to a file!\n";    

     // define variables 
            vector<string> favs;                                   // creates variable to store "favs"
            string input = "asdf";                                 // creates text variable w/ placeholder value 
            string path = "save.txt";                              // creates variable to store file name

     cout << "What file would you like to open?\n type 'no' to use default.\n";

         getline(cin, input);                                     // get user input 

     // if user says NO....
        if(input != "no") 
            {
            path = input;                                     // save to save.txt
            }

     // display names and add names to vector 
            read (path);                                                // show the current names
            read (favs, path);                                          // add the names to the vector 
    
      // prompt user to add names 
            cout << "What names would you like to add?\n";
            cout << "enter an empty line to stop.\n";
    
      while(input !="")                             // keeps looping until input empty
        {                                           
            cout << "> ";
            
            getline(cin, input);                    // get user input

            // if user inputs nothing...
            if (input == "") 
            {
                break;                             // break 
            }

            //send to file 
            //writeFile << input << endl;

            favs.push_back(input);
        }


     // now call the write function and send it to our favs vector.
 
        write(favs, path);
    
        return 0;
    
    }




//int main() 
//{
//    cout << "Let's write to a file!\n";

    // open or "load" the file (read)
    // call the read function here 
 //   read();
    // make some changes 
    // save the file
    // close the file


    // // create a new var and try to open a file.
    // string line;
    // ifstream readFile("save.txt");       //inpout file stream
    // if(readFile.is_open())
    // {

    //     cout << "The file is open.\n";
    //     while(getline(readFile, line)) 
    //     {
    //         cout << line << endl;

    //     }
    // }
    //     else
    //     {
    //         cout << "Couldn't open that file.\n";
    //     }

    // // after we're done with the file, close it 
    // readFile.close();

    // -----------------------------------------------------------------------------