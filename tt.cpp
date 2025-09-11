#include <bits/stdc++.h>
using namespace std;
void help()
{
   int n,m;
   cin >> n >> m;
   string x;
   string s;
   cin >> x;
   cin >> s;
   int count;
   
   for(count = 0; x.length() <= m + n; count++)
   {
    size_t pos = x.find(s);
    if (pos == string::npos)
    {
        x = x + x;
    }
    else
    {
        cout<<count<<endl;
        return;
    }
   }
   cout<< -1 <<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        help();
    }
    return 0;
}