#include <bits/stdc++.h>
using namespace std;
#define long long long
void help()
{
    long n;
    cin >> n;
    vector<long> vec;
    for(long i = 0; i < n ; i++)
    {
        long num;
        cin >> num;
        vec.push_back(num);
    }
    for(int i = n-2; i >= 0; i--)
    {
        if((vec[i+1]) % 2 == 0)
        {
            if(vec[i] % 2 == 0)
            {
                vec[i]++;
            }
            else if(vec[i] == 1)
            {
                vec[i] += 2;
            }
            else
            {
                if(vec[i+1] % vec[i] == 0)
                {
                    vec[i] += 2;
                }
            }
        }
        else
        {
            if(vec[i] % 2 == 1)
            {
                vec[i]++;
            }
        }
    }
    for(int i : vec)
    {
        cout << i << " ";
    }
    cout << endl;
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
    // for(long i = 1; i < n; i++)
    // {
    //     if(count == 2*n)
    //     {
    //         break;
    //     }
    //     if((vec[i] % vec[i-1]) == 0)
    //     {
    //         if(vec[i-1] == 1)
    //         {
    //             if(vec[i] == 1)
    //             {
    //                 vec[i-1] += 2;
    //                 vec[i] += 1;
    //                 i -= 2;
    //             }
    //             else{
    //             vec[i-1]++;
    //             count++;
    //             i--;}
                
    //         }
    //         else
    //         {
    //             vec[i]++;
    //             count++;
    //         }
    //     }
    // }
    // for(int i : vec)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;