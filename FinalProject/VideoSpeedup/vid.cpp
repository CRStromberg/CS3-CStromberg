#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>
#include <cassert>
#include <queue>
#include <sstream>

using namespace std;
/*
    in n, p, k
    in t n times
    ans = from 0 to t1
    ans = ans + [(t2-t1)*(1 + p/100)] + [(t3-t2)*(1 + 2p/100)]...
*/
void test();
void get_data();
double get_ans(double n, double p, double k, queue <double> time);

int main(int argc, char* argv[])
{
    if (argc > 1 && strncmp(argv[1], "test", 4) == 0) {test();}
    else get_data();

    return 0;
}

void get_data()
{
    double n, p, k, temp;
    queue <double> time;

    cin >> n >> p >> k;

    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        time.push(temp);
    }

    cout << fixed << setprecision(6) << get_ans(n, p, k, time) << endl;
}

double get_ans(double n, double p, double k, queue <double> time)
{
    double t, pt, temp, ans, new_p;
    pt = 0;
    ans = 0;

    for(int i = 0; i <= n; i++)
    {
        new_p = 1 + (i*p/100);
        if(i<n)
        {
            t = time.front(); 
            time.pop();
            temp = t - pt;
            ans = ans + (temp * new_p);
            pt = t;
            k = k - temp;
        }            
        else ans = ans + (k * new_p);
    }
    return ans;
}

void test()
{   queue <double> timestamp;
    double timestamp1[22] = {3, 11, 25, 37, 51, 74, 88, 100, 157, 202, 351, 491, 505, 591, 722, 849, 1152, 1237, 1592, 1799, 1801, 2087};
    double timestamp2[13] = {2, 7, 11, 20, 69, 75, 102, 147, 171, 194, 205, 215, 227};
    double timestamp3[7] = {5, 7, 8, 10, 13, 15, 16};
    double num_ans;
    string ans;

    for(int i = 0; i < 22; i++)timestamp.push(timestamp1[i]);
    //Convert to string for assertion
    num_ans = get_ans(22, 133, 2275, timestamp);
    ostringstream ss1;
    ss1 << num_ans;
    ans = ss1.str();
    assert(ans == "50321.2");

    for(int i = 0; i < 13; i++)timestamp.push(timestamp2[i]);
    //Convert to string for assertion
    num_ans = get_ans(13, 75, 245, timestamp);
    ostringstream ss2;
    ss2 << num_ans;
    ans = ss2.str();
    assert(ans == "1062.5");
    
    for(int i = 0; i < 7; i++)timestamp.push(timestamp3[i]);
    //Convert to string for assertion
    num_ans = get_ans(7, 13, 73, timestamp);
    ostringstream ss3;
    ss3 << num_ans;
    ans = ss3.str();
    assert(ans == "101.86"); 
    
    cout << "All test cases passed...\n";
}