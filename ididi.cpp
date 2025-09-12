#include <bits/stdc++.h>
using namespace std;
#define long long long
void help()
{
    long n,k;
    cin >> n >> k;
    vector<long> vec;
    vector<long> suffix(n,0);
    for(int i = 0; i < n ; i++)
    {
        long num;
        cin >> num;
        vec.push_back(num);
    }
    sort(vec.begin(),vec.end());
    int i = 0;
    int j = n-1;
    int summin = 0; 
    int summax = 0;
    while((k--) && (i <= j))
    {
        int num = vec[i] + vec[i+1];
        if(num >= vec[j])
        {   
            j = j-1;
        }
        else
        {
            i = i + 2;
        }
        summax += vec[j+1];
        summin += num;
    }
    long sum = 0;
    for(i; i <= j; i++)
    {
        sum += vec[i];
    }
    cout << sum << endl;
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
