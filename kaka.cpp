#include <bits/stdc++.h>
using namespace std;
#define int long long
void help()
{
   string s;
   cin >> s;
   int n = s.length();
   int st = 0, en = 0;
   int max1 = 0;
   for(int i = 0; i < n; i++)
   {
    if(s[i] == '0')
    {
        en = i;
        int curr = en - st;
        max1 = max(max1,curr);
        st = i + 1;
    }
   }
   if(s[n-1] == '1') {
        max1 = max(max1, n - st);
    }
    int prefix = 0, suffix = 0;
    int i = 0;
    while(i < n && s[i] == '1') {
        prefix++;
        i++;
    }

    i = n - 1;
    while(i >= 0 && s[i] == '1') {
        suffix++;
        i--;
    }

    if(s[0] == '1' && s[n-1] == '1') {
        max1 = max(max1, prefix + suffix);
    }

    cout << max1 << endl;
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
    