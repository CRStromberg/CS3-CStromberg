/*
Chris Stromberg
02/25/20

Kattis Problem
Putovanje

    Algorithm
-----------------
-   Read Data
        - first line - N is array of fruits, C is Capacity of Mislav stomach
        - Second Line - weight of fruits in order of discovery
-   Write test cases
-   Compute data
    -   use nested loop to loop though vector getting max fruit eaten from each starting point
    -   Set total number of fruits to the largest max fruit eaten
-   Output the total number of fruits
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

void test(vector <int unsigned> &data);
void read(vector <int unsigned> &data);
int solve(vector <int unsigned> &data, int C, int N);

int main(int argc, char* argv[])
{
    vector <int unsigned> data;
    if (argc > 1 && strncmp(argv[1], "test", 4) == 0) { test(data); }
    else { read(data); }

    return 0;
}

void test(vector <int unsigned> &data)
{
    int n, c, ans;

    n = 11;
    c = 8;
    ans = 4;
    data = {1,1,5,3,2,6,8,3,2,1,2};
    assert(solve(data, c, n) == ans);

    n = 3;
    c = 2;
    ans = 2;
    data = {1,1,2};
    assert(solve(data, c, n) == ans);

    n = 8;
    c = 12;
    ans = 5;
    data = {1,5,2,3,2,1,7,5};
    assert(solve(data, c, n) == ans); 

    cout << "All test cases passed...\n";   
}

int solve(vector <int unsigned> &data, int C, int N)
{
    int max_temp, max, weight;
    max = 0;

    for(int i = 0; i < N; i++)
    {
        max_temp = 0;
        weight = 0;
        //Don't waste time looping if elements left is less than the current max
        if (N - i > max)
        {
            for(int j = i; j < N; j++)
            {
                if(weight + data[j] <= C)
                {
                    weight += data[j];
                    max_temp ++;
                }
            }
            //Compare to previous max and set new max
            if (max_temp > max) {max = max_temp;}
        }
    }
    return max;
}

void read(vector <int unsigned> &data)
{
    int n, c, temp;

    cin >> n >> c;

    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        data.push_back(temp);
    } 
    cout << solve(data, c, n) << endl;
}