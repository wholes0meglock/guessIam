#include <bits/stdc++.h>
using namespace std;
#define int long long
void help() {
    int n;
    cin >> n;
    vector<pair<int,int>> vec;
    map<int,int> m;
    for(int i = 1; i <= n; i++)
    {
        int num;
        cin >> num;
        vec.push_back({i,num});
        m[num]++;
    }
    sort(vec.begin(),vec.end(),[](const pair<int,int> a,const pair<int,int> b)
    {
    return a.second < b.second;
    }
    );
    bool possible = true;
    for(auto &it : m) {
        if(it.second == 1) {
            possible = false;
            break;
        }
    }
    if(!possible) {
        cout << -1 << endl;
        return;
    }
    vector<int> res(n + 1);
    int i = 0;
    while (i < n) {
        int j = i;
        while (j < n && vec[j].second == vec[i].second) j++;
        for(int k = i; k < j; k++) {
            int prev_idx = (k == i) ? j - 1 : k - 1;
            res[vec[k].first] = vec[prev_idx].first;
        }
        i = j;
    }
    for(int i = 1; i <= n; i++) {
        cout << res[i] << " ";
    }
    cout << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        help();
    }
    return 0;
}