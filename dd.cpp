#include <bits/stdc++.h>
using namespace std;
#define int long long

void help() {
    int n;
    cin >> n;
    vector<pair<int,int>> vec(n);
    map<int,int> freq;
    
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        vec[i] = {i + 1, num}; 
        freq[num]++;
    }
    for(auto it : freq) {
        if(it.second == 1) {
            cout << -1 << endl;
            return;
        }
    }
    
    sort(vec.begin(), vec.end(), [](const pair<int,int>& a, const pair<int,int>& b){
        return a.second < b.second;
    });
    vector<int> indices(n);
    for(int i = 0; i < n; i++)
        indices[i] = vec[i].first;

    int last = indices[n - 1];
    for(int i = n - 1; i > 0; i--)
        indices[i] = indices[i - 1];
    indices[0] = last;

    for(int i = 0; i < n; i++)
        cout << indices[i] << " ";
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
        help();
    return 0;
}
