#include <iostream>
#include <cassert>
#include <vector>
#include <bits/stdc++.h>
#include <string>
#include <sstream>


using namespace std;

void test();
void get_data();
int solve(vector <int> int_data, int n);

int main(int argc, char* argv[])
{


    if (argc > 1 && strncmp(argv[1], "test", 4) == 0) test();
    else get_data();

    return 0;
}

void get_data()
{
    string data;
    vector <int> int_data;
    int temp, n;

    while(getline(cin, data))
    {
        istringstream ss_data(data);

        n = 0;
        while(ss_data >> temp) 
        {
            n++;
            int_data.push_back(temp);
        }
        cout << solve(int_data, n) << endl;
        int_data.clear();
    }
}

int solve(vector <int> int_data, int n)
{
    int sum, temp;

    sum = 0;
    for(int i =0; i < n; i ++)
    {
        temp = int_data[i];
        sum += temp;
    }
    return sum/2;
}

void test()
{
    vector <int> int_data;

    int test1 [12] = {14, -10, 2, 32, 13, -1, 17, -7, 5, 4, -11, 6};//32
    int test2 [24] = {231, -196, -178, 306, -1, 208, -386, 308, 167, 173, -394, -77, 6, 193, -124, 125, 75, 311, -282, -114, 484, -110, -64, -39};//311
    int test3 [16] = {473, 354, -58, -38, -316, -125, -151, -297, 189, 80, 457, -176, 99, 417, 106, -306};//354

    //Test Case 1
    for(int i = 0; i < 12; i++) int_data.push_back(test1[i]);
    assert(solve(int_data, 12) == 32);
    int_data.clear();

    //Test Case 2
    for(int i = 0; i < 24; i++) int_data.push_back(test2[i]);
    assert(solve(int_data, 24) == 311);
    int_data.clear();

    //Test Case 3
    for(int i = 0; i < 16; i++) int_data.push_back(test3[i]);
    assert(solve(int_data, 16) == 354);

    cout << "All test cases passed...\n";
}