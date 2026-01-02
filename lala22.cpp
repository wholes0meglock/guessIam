#include <bits/stdc++.h>
using namespace std;
#define int long long
void help() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    int l = 0, r = n - 1;

    while (l < n && a[l] == b[l])
    l++;
    while (r >= 0 && a[r] == b[r]) 
    r--;

    // Extend l leftward while possible (for longest segment)
    while (l > 0 && b[l - 1] <= b[l]) l--;
    // Extend r rightward while possible
    while (r < n - 1 && b[r] <= b[r + 1]) r++;

    cout << l + 1 << " " << r + 1 << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long double t;
    cin >> t;
    while(t--)
    { help();}
}