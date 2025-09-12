#include <bits/stdc++.h>
using namespace std;
#define long long long

void help() {
    long n, k;
    cin >> n >> k;
    vector<long> vec(n);
    for (int i = 0; i < n; i++) cin >> vec[i];

    sort(vec.begin(), vec.end());

    // build suffix correctly
    vector<long> suffix(n);
    suffix[n-1] = vec[n-1];
    for (int i = n-2; i >= 0; i--) {
        suffix[i] = vec[i] + suffix[i+1];
    }

    long i = 1;
    long j = n-1;
    long max2 = 0;

    while (k-- && i < n && j >= 0 && i <= j) {
        long s = suffix[i] - ((j+1 < n) ? suffix[j+1] : 0);
        max2 = max(max2, s);
        i += 2;
        j -= 1;
    }

    cout << max2 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) help();
    return 0;
}
