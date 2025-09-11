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
    int count = 0;
    vector<int> vec2;
    for(int i = 1; i < n; i++)
    {
        int num = vec[i] - vec[i-1];
        vec2.push_back(num);
    }
    for(int i = 0; i < (int)vec2.size(); i++)
    {
        if(vec2[i] > k)
        {
            int num1 = distance(vec.begin(), vec.begin() + i+1);
            int num2 = distance(vec.begin() + i+1,vec.begin()+vec.size());
            // vec.erase(vec.begin(), vec.begin() + i+1);
            if(num1 < num2)
            {
                vec.erase(vec.begin(), vec.begin() + i+1);
                count += num1;
                
                vec2.clear();
                i = -1;
                if (vec.size() > 1)
                {
                for (int j = 1; j < vec.size(); j++)
                { 
                vec2.push_back(vec[j] - vec[j-1]); 
                }
                }
            else{break;}  
            }
            else
            {
                vec.erase(vec.begin() + i+1,vec.begin()+vec.size());
                count += num2;
                vec2.clear();
                i = -1;
                if (vec.size() > 1)
                {
                for (int j = 1; j < vec.size(); j++)
                { 
                vec2.push_back(vec[j] - vec[j-1]); 
                }
                }
            else{break;}
            }
        }
    }
    cout << count << endl;
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

