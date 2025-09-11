#include <bits/stdc++.h>
using namespace std;
void help()
{
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    int count = 0;
    vector<char> vec;
    if(n == 1)
    {
        cout << "YES" << endl;
        return;
    }
    for(int i = 0; i < n; i++)
    {
        vec.push_back(s[i]);
    }
    map<char,int> tuff;
    for(char c : vec)
    {
        tuff[c]++;
    }
    for(auto it : tuff)
    {
        if(it.second % 2 != 0)
        {
            count++;
        }
    }
    count -=k;
    if(count > 1)
    {
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        help();
    }
    return 0;
}
