/*
Chris Stromberg
02/27/20

Kattis Problem
ICPC

    Algorithm
-----------------
-   Read Data
    -   only line is M, N, T
-   Write test cases
-   Compute data
    -   search algorithm complexities(T)
    -   Plug N into return from T
        - take output from above and subtract M
    - if output is negative return AC, else return TLE
-   Output AC/TLE
*/
#include <iostream>
#include <cassert>
#include <bits/stdc++.h>
#include <string>
#include <math.h>

using namespace std;

void test();
void read();
string solve(int m, int n, int t);

int main(int argc, char* argv[])
{
    if (argc > 1 && strncmp(argv[1], "test", 4) == 0) { test(); }
    else { read(); }

    return 0;
}

void test()
{
     assert(solve(1000000, 200, 5) == "AC");
     assert(solve(2000000, 30, 2) == "TLE");
     assert(solve(5000, 7, 1) == "TLE");

     cout << "All Test Cases Passed...\n";
}

string solve(int m, int n, int t)
{
    double ans = 1;

    switch (t)
    {
    case 1:
        //n!
        for(int i = 1; i <= n; i++) 
        { 
            ans *= i; 
            //check if TLE before computation finish for speed
            if (ans > m) break;   
        }
        ans = ans - m;        
        break;
    case 2:
        //2^n
        ans = pow(2, n);
        ans = ans - m;
        break;
    case 3:
        //n^4
        ans = pow(n, 4);
        ans = ans - m;
        break;
    case 4:
        //n^3
        ans = pow(n, 3);
        ans = ans - m;
        break;
    case 5:
        //n^2
        ans = pow(n, 2);
        ans = ans - m;        
        break;
    case 6:
        //nlog2(n)
        ans = n*log2(n);
        ans = ans - m;        
        break;
    default:
        //n
        ans = n;
        ans = ans - m;    
        break;
    }

    if( ans <= 0) return "AC";
    else return "TLE";
}

void read()
{
    int m, n, t;

    cin >> m >> n >> t;
    cout << solve(m, n, t) << endl;
}