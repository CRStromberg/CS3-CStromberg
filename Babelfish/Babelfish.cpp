/*
Kattis Problem
Babelfish

    Algorithm
-----------------
-   Read Data
    -   Create Dictionary from data
    -   Ceate list of words to be translated
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

map <string, string> trans_AM;
map <string, string> trans_NZ;

string search_dictionary(string unknown);
void insert_dictionary(string known, string unknown);
void test();

int main(int argc, char* argv[])
{
    if (argc > 1 && strncmp(argv[1], "test", 4) == 0) {test();}
    else
    {

    }
   for(auto elem : trans_AM)
    {
        std::cout << elem.first << " " << elem.second<<"\n";
    }
    for(auto elem : trans_NZ)
    {
        std::cout << elem.first << " " << elem.second << "\n";
    }
    
    cout<<endl<<endl<<"This is the search results for hallo(hello): " <<search_dictionary("hallo")<<endl
    <<"This is the search results for kann(may): " <<search_dictionary("kann")<<endl<<
    "This is the search results for samstag(saturday): " <<search_dictionary("samstag")<<endl<<
    "This is the search results for wasd(eh): " <<search_dictionary("wasd")<<endl<<endl;
    
    return 0;
}


void test()
{
    insert_dictionary("hello", "hallo");
    insert_dictionary("may", "kann");
    insert_dictionary("saturday", "samstag");

    //assert(search_dictionary("00", "hallo") == "hello");
    //assert(search_dictionary("00", "wasd") == "eh");
    //assert(search_dictionary("00", "samstag") == "saturday");
    //cout << "All test cases passed...\n";
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
            else { return "eh a-m"; }
        break;
        default:
            if(trans_NZ.find(unknown) != trans_NZ.end()) { return trans_NZ.find(unknown)->second; }
            else { return "eh n-z"; }                        
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

