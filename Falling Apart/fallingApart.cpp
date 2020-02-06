/*
Kattis Problem
Falling Apart

    Algorithm
-----------------
-   Read Data
-   Write test cases
-   Compute data
    -   Set first number = to # of turns
    -   Sort data from Largest to Least
    -   pop data off giving it to Alice and Bob switching between the too
-   Output the Answer
*/

#include <iostream>
#include <cassert>
#include <vector>
#include <sstream>
#include <bits/stdc++.h>
#include <fstream>

using namespace std;

void test();
string ans(string input);

int main(int argc, char* argv[])
{
    string info, temp;
    int alice, bob;

    if (argc > 1 && strncmp(argv[1], "test", 4) == 0) {test();}
    else
    {
        getline(cin, info);
        getline(cin, temp);
        info += " "+ temp;
        stringstream fstrans(ans(info));
        fstrans >> alice >> bob;
        cout << alice << " " << bob;
    }
    return 0;
}

void test()
{
    assert(ans("5 9 2 5 8 3") == "16 11");
    assert(ans("2 7 1") == "7 1");
    assert(ans("14 20 83 1 19 76 83 33 56 12 32 45 21 11 9") == "277 224");
    cout << "All test cases passed...\n";
}

string ans(string input)
{
    stringstream strdata(input);
    int turns, i, j, bob, alice, temp;
    string finans;
        
    vector<int> data((istream_iterator<int>(strdata)), istream_iterator<int>());
   
    //remove # of turns
    turns = data[0];
    data.erase(data.begin());

    //Sort Vector from lg to sm
    sort(data.begin(), data.end(), less<int>());

    alice = 0;
    bob = 0;
    
    //Distribute to Alica and Bob
    for (j = 0; j < turns; j+=2)
    {
        if (!data.empty())  
        {
            alice += data.back();
            data.pop_back();
        }
        if (!data.empty())  
        {
            bob += data.back();
            data.pop_back();
        }
    }

    //Merge Integers to a string for final answer
    finans = to_string(alice);
    finans += " ";
    finans += to_string(bob);
   
    return finans;
}