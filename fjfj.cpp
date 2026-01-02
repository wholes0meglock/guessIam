#include <bits/stdc++.h>
using namespace std;
void help() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    if (n == 1) {  
        cout << 0 << "\n"; 
        return;
    }

    int ans = INT_MIN;

    for (int i = 0; i < n - 1; i++) {
        ans = max(ans, vec[i] - vec[i + 1]);
    }

    int min1 = *min_element(vec.begin(), vec.end() - 1);
    ans = max(ans, vec[n - 1] - min1);

    int max3 = *max_element(vec.begin() + 1, vec.end());
    ans = max(ans, max3 - vec[0]);

    cout << ans << "\n";
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
