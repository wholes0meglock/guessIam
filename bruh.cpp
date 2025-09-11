#include <bits/stdc++.h>
using namespace std;
void help() {
    string s;
    int n;
    cin >> n;
    cin >> s;
    vector<int> vec;
    for(int i = 0; i < n/2; i++)
        {
            for(int j = n-i-1;;)
            {
                if(s[i] != s[j])
                {
                    vec.push_back(i);
                }
                break;
            }
        }
        // for(int i : vec)
        // {
        //     cout << i << endl;
        // }
    if(vec.empty() == true)
        {
            cout << "Yes" << endl;
            return;
        }
    sort(vec.begin(), vec.end());    
    int t = vec.size();
    for(int i = 1; i < t; i++)
        {
            if(vec[i] - vec[i-1] != 1)
            {
                cout << "No" << endl;
                return;
            }
        }
    cout << "Yes" << endl;
        
   
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

