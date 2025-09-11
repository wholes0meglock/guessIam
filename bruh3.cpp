#include <bits/stdc++.h>
using namespace std;
void help()
{
    int n,k;
    cin >> n >> k;
    vector<int> vec;
    for(int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        vec.push_back(num);
    }
    sort(vec.begin(),vec.end());
    int maxcount = 0;
    int st = 0;
    int en = 0;
    for(int i = 0; i < vec.size() - 1 ; i++)
    {
        if((vec[i+1] - vec[i]) > k)
        {
            en = i;
            int curr = en - st + 1;
            maxcount = max(curr,maxcount);
            st = i + 1;
        }

    }
    int curr = n - st;
    maxcount = max(curr,maxcount);
    cout << n-maxcount << endl;
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

