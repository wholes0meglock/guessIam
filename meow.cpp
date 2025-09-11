#include <bits/stdc++.h>
using namespace std;
void help()
{
    int n;
    cin >> n;
    vector<int> vec;
    for(int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        vec.push_back(num);
    }
    // bool f = true;
    // for(int i = 2; i < n ; i++)
    // {
    //     if((vec[i] + vec[i-2]) % 2 != 0)
    //     {f = false; break;}
    // }
    // if(f == true)
    // {
    //     cout << 2 << endl;
    //     return;
    // }
    // int maxc = 0;
    // for(int i = 0; i < n;  i++)
    // {
    //     for(int j = i + 1; j < n-1; j++)
    //     {
    //         int num = abs(vec[i] - vec[j]);
    //         if(num == (abs(i-j)))
    //         {
    //             maxc = max(num,maxc);
    //         }
    //     }
    // }
    // cout << maxc << endl;
    
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
