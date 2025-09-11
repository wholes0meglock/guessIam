#include <bits/stdc++.h>
using namespace std;
#define long long long

void help() {
    long n, q;
    cin >> n >> q;
    vector<long> vec(n+1, 0);  // 1-based
    vector<long> prefix(n+1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> vec[i];
        prefix[i] = prefix[i-1] + vec[i];
    }

    long sum = prefix[n]; // total sum of array

    while (q--) {
        long l, r, k;
        cin >> l >> r >> k;

        long sum2 = prefix[r] - prefix[l-1];   // sum of [l..r]
        long n2 = (r - l + 1) * k;

        if ((sum - sum2 + n2) % 2 == 1) 
            cout << "YES\n";
        else 
            cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        help();
    }
    return 0;
}
