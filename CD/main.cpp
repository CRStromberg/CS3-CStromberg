/*
Kattis Problem
CD

    Algorithm
-----------------
-   Read Data
    -   first line store for home many CD's jack and jill own
    -   use vector to stor N_jack the the next N lines
    -   use vector to stor N_jill the the next N lines
    -   throw out 0 0 line
-   Write test cases
-   Compute data
    -   search vectors for line numbers and incriment
    -   return incriment
-   Output the incriment
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <bits/stdc++.h>


using namespace std;


void test(vector <int unsigned> &Jack, vector <int unsigned> &Jill);
int read(vector <int unsigned> &Jack, vector <int unsigned> &Jill);
int ans(vector <int unsigned> &Jack, vector <int unsigned> &Jill);

int main(int argc, char* argv[])
{
    vector <int unsigned> Jack;
    vector <int unsigned> Jill;

    if (argc > 1 && strncmp(argv[1], "test", 4) == 0) { test(Jack, Jill); }
    else { cout << read(Jack, Jill); }

    return 0;
}

void test(vector <int unsigned> &Jack, vector <int unsigned> &Jill)
{
    //Test case 1
    Jack = {4, 5, 7, 9, 10, 13, 23, 27, 28, 29, 31, 33, 37, 38, 39, 40, 41, 42, 43, 44, 47};
    Jill = {1, 3, 6, 7, 13, 28, 33, 35, 36, 37, 40, 41, 42, 44, 45, 47, 48};
    assert(ans(Jack, Jill) == 10);
    
    //Test case 2
    Jack = {1, 2, 3, 5, 6, 8, 9, 10, 11, 13, 14, 15, 19, 23, 27, 28, 29, 31, 33, 40, 41, 44, 49};
    Jill = {1, 2, 3, 4, 6, 7, 9, 11, 13, 15, 19, 21, 25, 28, 32, 33, 35, 36, 37, 41, 43, 44, 48, 52, 55, 60, 63};
    assert(ans(Jack, Jill) == 13);
    
    //Test case 3
    Jack = {1, 2, 10, 11, 23, 27, 28, 51, 54, 79};
    Jill = {1, 4, 19, 21, 25, 28, 37, 54, 55, 60, 63};
    assert(ans(Jack, Jill) == 3);
    
    cout<<"All Test Cases Passed...\n";
}

int ans(vector <int unsigned> &Jack, vector <int unsigned> &Jill)
{
    int answer = 0;

    for( int i =0; i<Jack.size(); i++)
    {
        if (binary_search(Jill.begin(), Jill.end(), Jack.at(i))) { answer++;}
    } 
    
    return answer;
}

int read(vector <int unsigned> &Jack, vector <int unsigned> &Jill)
{
    int jkn, jln;
    int temp, i;

    cin >> jkn >> jln;

    for(i=0;i<jkn;i++)
    {
        cin >> temp;
        Jack.push_back(temp);
    }
    for(i=0;i<jln;i++)
    {
        cin >> temp;
        Jill.push_back(temp);
    }
    return ans(Jack, Jill);
}