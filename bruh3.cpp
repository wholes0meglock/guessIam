#include <bits/stdc++.h>
using namespace std;
void help()
{
    int n;
    cin >> n;
    vector<int> vec(n,0);
    for(int i = 0; i < n ; i++)
    {
        cin >> vec[i];
    }
    // cout<<"x";
    int max2 = INT_MIN;

    for(int i = 0; i < n; i++)
    {
        int num = abs(vec[i] - vec[(i+1)%n]);
        max2 = max(max2,num);
    }
    int max3 = INT_MIN;
    for(int i = 1; i < n; i++)
    {
        max3 = max(max3,vec[i]);
    }
    if(max3 != INT_MIN)
    max2 = max(max2,max3-vec[0]);
    // cout<<max2<<endl;
    int min1 = INT_MAX;
    for(int i = 0; i < n-1; i++)
    {
        min1 = min(min1,vec[i]);
    }
    if(min1 != INT_MAX)
    max2 = max(max2,vec[n-1]-min1);
    cout << max2 << endl;

    
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

