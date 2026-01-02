#include <bits/stdc++.h>
using namespace std;
#define int long long

void help() {
    string a, b;
    cin >> a >> b;
    
    if(a == b) {
        cout << 0 << endl;
        return;
    }
    
    int n = a.length(), m = b.length();
    int maxLen = 0;
    
    // Find the longest common substring
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int len = 0;
            int x = i, y = j;
            
            // Find common substring starting at position i in a and j in b
            while(x < n && y < m && a[x] == b[y]) {
                len++;
                x++;
                y++;
            }
            
            maxLen = max(maxLen, len);
        }
    }
    
    cout << n + m - 2 * maxLen << endl;
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