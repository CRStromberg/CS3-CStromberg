#include <iostream>
#include <cassert>
#include <vector>
#include <sstream>

using namespace std;

void test();
string ans(string input);


int main()
{
    


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
    int turns, i;

    i = 0;
    strdata << input;

    while(!strdata.eof())
    {
        strdata << data[i];
        i++;
    }

    turns = data[0];
    
    data.erase(data.begin());
    for (int j = 0; j < i; j++) data[j]=data[j+1];
    
}