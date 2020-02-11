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

string dictionary(string known, string unknown);
void test();

int main(int argc, char* argv[])
{
    if (argc > 1 && strncmp(argv[1], "test", 4) == 0) {test();}
    else
    {

    }
    return 0;
}

void test()
{
    dictionary("hello", "hallo");
    dictionary("may", "kann");
    dictionary("saturday", "samstag");
    
    assert(dictionary("00", "hallo") == "hello");
    assert(dictionary("00", "wasd") == "eh");
    assert(dictionary("00", "samstag") == "saturday");
    cout << "All test cases passed...\n";
}

string dictionary(string known, string unknown)
{
    int i;
    map <string, string> trans_AM;
    map <string, string> trans_NZ;

    char temp = unknown[0];
    temp = tolower(temp);

    if (known =="00")
    {
        //Using modified find() loop from geeksforgeeks.com
        //https://www.geeksforgeeks.org/map-find-function-in-c-stl/
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
            /*
            Change to temp = .find()-second
            */
                for (auto itr = trans_AM.find(unknown); itr != trans_AM.end(); itr++) 
            break;
            default:
                for (auto itr = trans_NZ.find(unknown); itr != trans_NZ.end(); itr++) 
            break;

        }
    

    }
    else
    {
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
                trans_AM.insert({known, unknown});
            break;
            default:
                trans_NZ.insert({known, unknown});
            break;
        }
        
            
        
    }
    
}
