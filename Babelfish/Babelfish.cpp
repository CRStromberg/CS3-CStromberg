/*Chris Stromberg
02/12/20

note: I probably could get it to run faster if I spent more time on it, 
but it was way under the 3 second limit. 
*/


/*
Kattis Problem
Babelfish

    Algorithm
-----------------
-   Read Data
    -   Create Dictionary from data
    -   Read words to be translated
-   Write test cases
-   Compute data
    -   search Dictionary for word to be translated
    -   return answer
-   Output the Answer
*/
#include <iostream>
#include <cassert>
#include <map>
#include <sstream>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

//Spit up dictionary for faster search
map <string, string> trans_AM;
map <string, string> trans_NZ;

string search_dictionary(string unknown);
void insert_dictionary(string known, string unknown);
void test();

int main(int argc, char* argv[])
{
    string temp, known, unknown;
    if (argc > 1 && strncmp(argv[1], "test", 4) == 0) {test();}
    else
    {
        //Get English and non-english words
        do
        {
            getline(cin, temp);
            istringstream ss(temp);
            ss >> known >> unknown;
            insert_dictionary(known, unknown);

        } while (!temp.empty());
                
        //Get words to be translated
        while(getline(cin, unknown))
        {
            cout<<search_dictionary(unknown)<<endl;
        }
    }
    return 0;
}

void test()
{
    insert_dictionary("hello", "hallo");
    insert_dictionary("may", "kann");
    insert_dictionary("saturday", "samstag");

    assert(search_dictionary("hallo") == "hello");
    assert(search_dictionary("wasd") == "eh");
    assert(search_dictionary("samstag") == "saturday");
    cout << "All test cases passed...\n";
}

string search_dictionary(string unknown)
{
    char temp = unknown[0];
    temp = tolower(temp);

    switch (temp)
    {
        case 'a':
        case 'b':
        case 'c':
        case 'd':
        case 'e':
        case 'f':
        case 'g':
        case 'h':
        case 'i':
        case 'j':
        case 'k':
        case 'l':
        case 'm':
            if(trans_AM.find(unknown) != trans_AM.end()) { return trans_AM.find(unknown)->second; }
            else { return "eh"; }
        break;
        default:
            if(trans_NZ.find(unknown) != trans_NZ.end()) { return trans_NZ.find(unknown)->second; }
            else { return "eh"; }                        
        break;
    }
}

void insert_dictionary(string known, string unknown)
{
    char temp = unknown[0];
    temp = tolower(temp);

    switch (temp)
    {
        case 'a':
        case 'b':
        case 'c':
        case 'd':
        case 'e':
        case 'f':
        case 'g':
        case 'h':
        case 'i':
        case 'j':
        case 'k':
        case 'l':
        case 'm':
            trans_AM.insert({unknown, known});
        break;
        default:
            trans_NZ.insert({unknown, known});
        break;
    }  
}

