#include <bits/stdc++.h>
using namespace std;

void help()
{
  int n;
  cin>>n;
  vector<int> vec;
  vec.push_back(-1);
  if(n== 2){
    cout<<-1<<" "<<2<<endl;
    return;
  }
  for(int i = 1; i < n; i++)
  {
    if(i % 2 == 1)
    {
        vec.push_back(3);
    }
    else{vec.push_back(-1);}
  }
  if(n%2 == 0){
    vec.pop_back();
    vec.push_back(2);
  }

  for(int i = 0; i < n; i++)
  {
    cout<<vec[i]<<" ";
  }
  cout<<endl;
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
