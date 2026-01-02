#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        string s;
        cin >> s;
        vector<bool> used(26, false);
        bool ok = true;
        for (int i = 0; i < (int)s.size(); ++i) {
            if (i == 0 || s[i] != s[i-1]) {
                int idx = s[i] - 'a';
                if (used[idx]) { // s[i] changed and was seen before -> invalid
                    ok = false;
                    break;
                }
                used[idx] = true;
            }
            // if s[i] == s[i-1] nothing to check (continuation of same block)
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}
