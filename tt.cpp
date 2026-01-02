#include <bits/stdc++.h>
using namespace std;
#define int long long
void help() {
    int n,q;
    cin >> n >> q;
    vector<int> vec;
    for(int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        vec.push_back(num);
    }
    vector<int> queries;
    map<int,vector<int>> m;
    map<int,int> m1;
    for(int i = 0; i < q; i++)
    {
        int num;
        cin >> num;
        queries.push_back(num);
        m1[num]++; 
    }
    for(auto it : m1)
    {
        int count = 0;
        for(int i = 0; i < n && count <= it.second; i++)
        {
            if(it.first == vec[i])
            {
                m[it.first].push_back(i+1);
                count++;
            }
        }
    }
    for(int i = 0; i < q; i++)
    {
        int color = queries[i];
        int pos = m[color][0];
        cout << m[queries[i]][0] << " ";
        for(auto &x : m)
        {
            for(auto &j : x.second)
                if(j < pos) j++; 
        }
        m[color].erase(m[color].begin());
        m[color].insert(m[color].begin(), 1);
    }    
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while(t--)
    help();
}
