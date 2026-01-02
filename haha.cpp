#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, r, b;
    cin >> n >> r >> b;
    
    int parts = b + 1;
    int base = r / parts;
    int extra = r % parts;
    
    string ans = "";
    for (int i = 0; i < parts; i++) {
        int cnt = base + (i < extra);
        ans += string(cnt, 'R');
        if (i < b) ans += 'B';
    }
    
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}