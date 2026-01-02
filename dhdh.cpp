#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<int,int> m;
    m[3]++;
    m[1]++;
    m[2]++;
    for(auto it : m)
    {
        cout << it.first << endl;
    }
}