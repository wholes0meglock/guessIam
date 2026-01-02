#include <bits/stdc++.h>
using namespace std;
#define int long long

int wewantjustice(vector<int> vec,int st,int en)
{
    int sum = 0;
    for(int i = st; i <= en; i++)
    {
        sum += vec[i];
    }
    return sum;
}

void help() {
    int n;
    cin >> n;
    vector<int> vec;
    map<int,int> m;
    for(int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        m[num]++;
        vec.push_back(1LL << num); 
    }
    for(auto it : m)
    {
        if(it.second > 1)
        {
            cout << "YES" << endl;
            return;
        }
    }
    bool f = false;
    int st1 = 0,st2 = 1;
    int en1 = 0,en2 = 1;
    while(en2 < n)
    {
        int copy;
        if(vec[st2] < vec[st1])
        {
            copy = en2;
            while(wewantjustice(vec,st2,copy) < wewantjustice(vec,st1,en1))
            {
                if(wewantjustice(vec,st2,copy) == wewantjustice(vec,st1,en1))
                {
                    f = true;
                    cout << "YES" << endl;
                    return;
                }
                copy++;
            }
            en2++;
            st2++;
        }
        else
        {
            copy = en1;
            while(wewantjustice(vec,st1,copy) < wewantjustice(vec,st2,en2))
            {
                if(wewantjustice(vec,st1,copy) == wewantjustice(vec,st2,en2))
                {
                    f = true;
                    cout << "YES" << endl;
                    return;
                }
                copy++;
            }
            en1++;
            st1++;
        }
    }
    cout << "NO" << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) help();
}
