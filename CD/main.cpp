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
#include <sstream>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;


void test(vector <int> &Jack, vector <int> &Jill);
void read(vector <int> &Jack, vector <int> &Jill);
int ans(vector <int> &Jack, vector <int> &Jill, int jkN, int jlN);

int main(int argc, char* argv[])
{
    vector <int> Jack;
    vector <int> Jill;

    if (argc > 1 && strncmp(argv[1], "test", 4) == 0) { test(Jack, Jill); }
    else { read(Jack, Jill); }

    return 0;
}

void test(vector <int> &Jack, vector <int> &Jill)
{
    int jkn, jln;

    //Test case 1
    jkn = 12;
    jln = 10;
    Jack = {4, 5, 7, 9, 10, 13, 23, 27, 28, 29, 31, 33};
    Jill = {1, 3, 6, 7, 13, 15, 25, 28, 32, 33};
    assert(ans(Jack, Jill, jkn, jln) == 4);
    
    //Test case 2
    jkn = 23;
    jln = 27;
    Jack = {1, 2, 3, 5, 6, 8, 9, 10, 11, 13, 14, 15, 19, 23, 27, 28, 29, 31, 33, 40, 41, 44, 49};
    Jill = {1, 2, 3, 4, 6, 7, 9, 11, 13, 15, 19, 21, 25, 28, 32, 33, 35, 36, 37, 41, 43, 44, 48, 52, 55, 60, 63};
    assert(ans(Jack, Jill, jkn, jln) == 13);
    
    //Test case 3
    jkn = 10;
    jln = 11;
    Jack = {1, 2, 10, 11, 23, 27, 28, 51, 54, 79};
    Jill = {1, 4, 19, 21, 25, 28, 37, 54, 55, 60, 63};
    assert(ans(Jack, Jill, jkn, jln) == 3);
    
    cout<<"All Test Cases Passed...\n";

}

int ans(vector <int> &Jack, vector <int> &Jill, int jkN, int jlN)
{
    vector <int>::iterator it;
    int i;
    int answer = 0;

    //Determine shortest vector and search the largest (fewer loops)
    if(Jack.size() > Jill.size())
    {
          
        for(i=0; i<jlN; i++)
        {
            it = find(Jack.begin(), Jack.end(), Jill[i]);

            if (it != Jack.end()) { answer ++;}
        }
    }
    else
    {
        for(i =0; i<jkN; i++)
        {
            it = find(Jill.begin(), Jill.end(), Jack[i]);

            if (it != Jill.end()) { answer ++;}         
        }        
    }
    return answer;
}

void read(vector <int> &Jack, vector <int> &Jill)
{
    int jkn, jln;
    int jktemp = -1;
    int jltemp = -1;

    cin >> jkn >> jln;

    //Read Data and insert into vector
    while (jktemp!=0 && jltemp!=0)
    {
        cin >> jktemp >> jltemp;
        Jack.push_back(jktemp);
        Jill.push_back(jltemp);
    } 
    cout << ans(Jack, Jill, jkn, jln);
}