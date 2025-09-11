#include <bits/stdc++.h>

using namespace std;
void help(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<string> vec;
    string temp = "";
    for(char c : s)
    {
        if(c == '.')
        {
            temp += c;
        }
        else{
            if(!temp.empty())
            {
            vec.push_back(temp);
            temp.clear();
            }
        }
        
    }
    if(!temp.empty())
    {
        vec.push_back(temp);
    }
    int size = vec.size();
    int sum = 0;
    if(vec.empty())
    {
        cout<<0<<endl;
        return;
    }
    for(int i = 0; i < size; i++)
    {
        if(vec[i].size() > 2)
        {
            sum = 2;
            break;
        }
        else if(vec[i].size() == 2 || vec[i].size() == 1)
        {
            sum = sum + vec[i].size();
        }
    }
    cout<<sum<<endl;    
}




int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        help();
    }                 
    return 0;

}