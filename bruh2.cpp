#include <bits/stdc++.h>
using namespace std;
#define int long long
void help()
{
    int n;
    cin >> n;
    vector<int> vec;
    int count1 = 0;
    int count2 = 0;
    for(int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        vec.push_back(num);
        if(num == 1)
        {
            count1++;
        }
        if(num == 2)
        {
            count2++;
        }
    }
    sort(vec.begin(),vec.end());
    if(count1 == 0 || (n != 1 && count1 == 1))
    {
        cout << "NO" << endl;
        return;
    }
    if(n > 2 && count2 < 1)
    {
        cout << "NO" << endl;
        return;
    }
    // 1 1 2 3 4 5 6 7 

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
    
