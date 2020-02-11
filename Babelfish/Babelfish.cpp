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
#include <vector>
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
    if (known =="00")
    {

    }
    else
    {
        
            
        
    }
    
}