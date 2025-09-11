#include <bits/stdc++.h>
using namespace std;
void help()
{
    int n;
    cin >> n;
    int p, q;
    cin >> p;
    map<int,int> try2;
    for(int i = 0; i < p; i++)
    {
        int num;
        cin >> num;
        try2[num]++;
    }
    cin >> q;
    for(int i = 0; i < q; i++)
    {
        int num;
        cin >> num;
        try2[num]++;
    }
    bool f = false;
    for(int i = 1; i <= n; i++)
    {
        for(auto it : try2)
        {
            if(i == it.first)
            {
                f = true;
                break;
            }
            else
            {
                f = false;
            }
        }
        if(!f){
            break;
        }
    }
    if(f == false)
    {
        cout << "Oh, my keyboard!" << endl;
    }
    else
    {
        cout << "I become the guy." << endl;
    }
}
int main()
{
    help();
    return 0;
    
}