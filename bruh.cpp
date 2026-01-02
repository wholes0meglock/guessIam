#include <bits/stdc++.h>
using namespace std;
#define int long long
void help() {
    int n,m;
    cin >> n >> m;
    vector<int> vec;
    for(int i = 0; i < m; i++)
    {
        int num;
        cin >> num;
        vec.push_back(num);
    }
    sort(vec.begin(),vec.end());
    // int longest = 1;
    vector<int> final;
    for(int i = 1; i < m; i++)
    {
        int num = vec[i] - vec[i-1] - 1;
        final.push_back(num);
        // longest = max(longest,num);
    }
    // longest = max(longest,vec[0] - 1 + n - vec[m-1]);
    int num = vec[0] - 1 + n - vec[m-1];
    final.push_back(num);
    sort(final.begin(),final.end(),[](const int& a, const int& b)   
    {
    return a > b;
    });
    // for(int i : final)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;
    int total = 0;
    // if(final[0] > 1) final[0]--;
    // total += final[0];
    // for(int i = 1; i < final.size(); i++)
    // {
    //     if(final[i] >= 2*(i+1)) final[i] -= 2*(i+1);
    //     if(final[i] > 0) total += (final[i] - 1);
    // }
    for(int i = 0; i < final.size(); i++)
    {
        int temp = final[i] - 2*i;
        if(temp > 0) total += temp - 1;
    }
    cout << n - total << endl;
}

signed main()
{
    //Jesus saves.
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    help();
}

