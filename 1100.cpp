#include <bits/stdc++.h>
using namespace std;
#define int long long
void help() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    unordered_map<int, vector<int>> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        m[a[i]].push_back(i);
    }
    int answer = INT_MAX;
    for (auto &it : m) {
        auto &v = it.second;
        vector<int> gaps;
        gaps.push_back(v[0]);
        for (int i = 1; i < (int)v.size(); i++)
        gaps.push_back(v[i] - v[i-1] - 1);
        gaps.push_back(n - 1 - v.back());
        sort(gaps.begin(), gaps.end(), greater<int>());
        int g1 = gaps[0];                    
        int g2 = (gaps.size() > 1 ? gaps[1] : 0);  
        int best = max(g1 / 2, g2);
        answer = min(answer, best);
    }
    cout << answer << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) help();
}
