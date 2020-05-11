#include <iostream>
#include <cassert>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

void test();
void get_data();
bool solve(int n, int capacity, queue <int> qon, queue <int> qoff, queue <int> qstay);

int main(int argc, char* argv[])
{
     if (argc > 1 && strncmp(argv[1], "test", 4) == 0) test(); 
    else get_data(); 

    return 0;
}

void get_data()
{
    int n, capacity, temp_on, temp_off, temp_stay;
    bool ans;
    queue <int> qon;
    queue <int> qoff;
    queue <int> qstay;

    cin >> capacity >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> temp_off >> temp_on >> temp_stay;
        qon.push(temp_on);
        qoff.push(temp_off);
        qstay.push(temp_stay);
    }
    ans = solve(n, capacity, qon, qoff, qstay);

    if(ans == true) cout << "possible" << endl;
    else cout << "impossible" << endl;
}

bool solve(int n, int capacity, queue <int> qon, queue <int> qoff, queue <int> qstay)
{
    bool possible = true;

    int total_capacity, on, off, stay, count;

    total_capacity = 0;
    on = 0;
    off = 0;
    stay = 0;

    for(int i = 0; i < n; i++)
    {
        count = i;
        on = qon.front();
        off = qoff.front();
        stay = qstay.front();
        
        int free = capacity - total_capacity - on + off;
        count++;

        if(possible == false) possible = false;
        else
        {
            if (count == 1 && off > 0) possible = false;
            else if(count == n && on > 0) possible = false;
            else if(count == n && stay > 0) possible = false;
            else if(count == n && total_capacity - off !=0) possible = false;
            else if(total_capacity  > capacity) possible = false;
            else if(total_capacity < 0) possible = false;
            else if(free > 0 && stay > 0) possible = false;
            else
            {
                total_capacity = total_capacity + on - off;
                possible = true;
            } 
        }
        
        qon.pop();
        qoff.pop();
        qstay.pop();
    }
    return possible;
}

void test()
{     
    int capacity, n; 
    queue <int> qon;
    queue <int> qoff;
    queue <int> qstay;

    //First Test Case
    int on1[8] = {0, 11, 2, 0, 3, 0, 5, 0};
    int off1[8] = {0, 0, 0, 2, 1, 5, 0, 13};
    int stay1[8] = {0, 0, 1, 0, 7, 0, 2, 0};
    capacity = 13;
    n = 8;
    for(int i = 0; i < n; i++)
    {
        qon.push(on1[i]);
        qoff.push(off1[i]);
        qstay.push(stay1[i]);
    }
    assert(solve(n, capacity, qon, qoff, qstay) == true);
    for(int i = 0; i < n; i++)
    {
        qon.pop();
        qoff.pop();
        qstay.pop();
    }

    //Second Test Case
    int on2[17] = {5, 20, 2, 0, 3, 0, 15, 0, 10, 5, 7, 3, 1, 5, 13, 7, 0};
    int off2[17] = {0, 2, 0, 12, 1, 5, 0, 13, 2, 0, 8, 2, 10, 3, 6, 7, 25};
    int stay2[17] = {0, 0, 1, 0, 0, 0, 8, 0, 0, 11, 0, 7, 0, 0, 20, 5, 0};
    capacity = 25;
    n = 17;
    for(int i = 0; i < n; i++)
    {
        qon.push(on2[i]);
        qoff.push(off2[i]);
        qstay.push(stay2[i]);
    }
    assert(solve(n, capacity, qon, qoff, qstay) == true);
    for(int i = 0; i < n; i++)
    {
        qon.pop();
        qoff.pop();
        qstay.pop();
    }

    //Third Test Case
    int on3[30] = {5, 20, 2, 0, 3, 0, 15, 10, 0, 7, 3, 4, 0, 11, 17, 9, 7, 10, 0, 10, 5, 7, 3, 1, 5, 13, 7, 0, 8, 0};
    int off3[30] = {0, 2, 0, 12, 1, 5, 7, 10, 11, 2, 5, 18, 0, 0, 3, 1, 1 , 5, 11, 0, 13, 2, 0, 8, 2, 10, 3, 6, 7, 25};
    int stay3[30] = {0, 0, 1, 0, 0, 0, 8, 0, 0, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 0, 0, 0, 7, 0, 0, 0};
    capacity = 18;
    n = 35;
    for(int i = 0; i < n; i++)
    {
        qon.push(on3[i]);
        qoff.push(off3[i]);
        qstay.push(stay3[i]);
    }
    assert(solve(n, capacity, qon, qoff, qstay) == false);
    for(int i = 0; i < n; i++)
    {
        qon.pop();
        qoff.pop();
        qstay.pop();
    }

    cout << "All test cases passed...\n";
}