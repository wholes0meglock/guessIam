#include <bits/stdc++.h>
using namespace std;
#define long long long
void help()
{
    long n,q;
    cin >> n >> q;
    long sum = 0;
    vector<long> vec;
    vector<long> prefix(n+1, 0);
    for(int i = 1; i <= n; i++)
    {
        long num;
        cin >> num;
        sum += num;
        vec.push_back(num);
        prefix[i] = prefix[i-1] + vec[i-1];
    }
    for(int i = 0; i < q; i++)
    {
        long l,r,k;
        cin >> l >> r >> k;
        long sum2 = prefix[r] - prefix[l-1];   
        long n2 = (r-l+1)*k;
        // cout << sum << " " << sum2 << " " << n2 << endl;
        if((sum - sum2 + n2) % 2 == 1)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        help();
    }
    return 0;
}
