#include <bits/stdc++.h>
using namespace std;
#define int long long

void help() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> prefix(n + 1, 0);
    for (int i = 1; i <= n; i++)
        prefix[i] = prefix[i - 1] + (s[i - 1] == 'W');

    int min1 = LLONG_MAX;
    for (int i = 0; i <= n - k; i++) {
        int white = prefix[i + k] - prefix[i];
        min1 = min(min1, white);
    }
    cout << min1 << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) help();

    return 0;
}
