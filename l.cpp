#include <bits/stdc++.h>
using namespace std;
void help()
{
  int a,b;
  cin >> a >> b;
  int xk,yk,xq,yq;
  cin >> xk >> yk;
  cin >> xq >> yq;
  int count = 0;
  vector<vector<int>> arrk = {{xk,yk},{xk,yk},{xk,yk},{xk,yk},{xk,yk},{xk,yk},{xk,yk},{xk,yk}};
  vector<vector<int>> arrq = {{xq,yq},{xq,yq},{xq,yq},{xq,yq},{xq,yq},{xq,yq},{xq,yq},{xq,yq}};
  vector<vector<int>> arr = {{a,b},{a,-b},{-a,b},{-a,-b},{b,a},{b,-a},{-b,a},{-b,-a}};
  for(int i = 0; i < 8; i++)
  {
    arrk[i][0] = arrk[i][0] + arr[i][0];
    arrk[i][1] = arrk[i][1] + arr[i][1];
    arrq[i][0] = arrq[i][0] + arr[i][0];
    arrq[i][1] = arrq[i][1] + arr[i][1];
  }
  

  for(int i = 0; i < 8 ; i++)
  {
    for(int j = 0; j < 8 ; j++)
    {
        if(arrk[i] == arrq[j])
        {
            count++;
            break;
        }
    }
  }
  if(a==b)
  cout<<count/2<<endl;
  else 
  cout<<count<<endl;
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
