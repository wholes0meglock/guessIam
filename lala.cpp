#include <bits/stdc++.h>
using namespace std;
#define long long long
void help()
{
    long n,k;
    cin >> n >> k;
    vector<long> vec;
    vector<long> suffix(n+1);
    for(int i = 0; i < n ; i++)
    {
        long num;
        cin >> num;
        vec.push_back(num);
    }
    sort(vec.begin(),vec.end());
    suffix[n] = 0;
    suffix[n-1] = vec[n-1];
    for(int i = n-2; i >= 0; i--)
    {
        suffix[i] = suffix[i+1] + vec[i];
    }
    long i = 0;
    long j = n-k;
    long max2 = 0;
    while(k-- >= 0 )
    {
        long s = suffix[i] - suffix[j];
        // cout<<suffix[i]<<" "<<suffix[j]<<endl;
        // cout<<s<<endl;
        max2 = max(s,max2);
        i += 2;
        j +=1;
    }
    cout << max2 << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    // t= 1;
    while (t--)
    {
        help();
    }
    return 0;
}

    // int j = n-1;
    // // int summin = 0; 
    // // int summax = 0;
    // while((k--) && (i <= j))
    // {
    //     int num = vec[i] + vec[i+1];
    //     if(num >= vec[j])
    //     {
    //         // summax += vec[j];
    //         j = j-1;
    //     }
    //     else
    //     {
    //         // summin += num;
    //         i = i + 2;
    //     }
    // }
    // long sum = 0;
    // for(i; i <= j; i++)
    // {
    //     sum += vec[i];
    // }
    // cout << sum << endl;