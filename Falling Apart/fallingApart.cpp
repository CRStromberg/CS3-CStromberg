#include <iostream>
#include <cassert>
#include <vector>
#include <sstream>
#include <bits/stdc++.h>

using namespace std;

void test();
string ans(string input);


int main(int argc, char* argv[])
{
    string info;

    if (argc > 1 && strncmp(argv[1], "test", 4) == 0)
        test();
    else
        cin >> info;
        cout << ans(info);
    return 0;
}

void test()
{
    assert(ans("5 9 2 5 8 3") == "18 11");
    assert(ans("2 7 1") == "7 1");
    assert(ans("14 20 83 1 19 76 83 33 56 12 32 45 21 11 9") == "277 224");
    cout << "All test cases passed...\n";
}

string ans(string input)
{
    stringstream strdata;
    vector<int> data;
    int turns, i, j, bob, alice, temp;
    string finans;
    
    i = 0;
    strdata << input;
    while (strdata >> temp)
    {
        data.push_back(temp);
        i++;
    }
    
    //remove # of turns from vectors and move everything up
    turns = data[0];
    
    data.erase(data.begin());
    for (j = 0; j < i; j++) data[j]=data[j+1];

    data[i] = 0;

    //Sort Vector form lg to sm
    sort(data.begin(), data.end(), greater<int>());

    alice = 0;
    bob = 0;

    //Distribute to Alica and Bob
    for (j = 0; j < i; j+=2)
    {
        if (data[j] != 0)  alice += data[j];
        if (data[j+1] != 0)  bob += data[j+1];
    }

    finans = alice + " " + bob;
    cout << finans;
    return finans;
}