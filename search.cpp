#include <bits/stdc++.h>
using namespace std;
int LinearSearch(vector<int> vec,int x)
{
    for(int i = 0; i < vec.size(); i++)
    {
        if(vec[i] == x)
        {
            return i;
        }
    }
    return -1;
}
int RLinearSearch(vector<int> vec,int l,int r,int x)
{
    if(r < l)
    {
        return -1;
    }
    if(vec[l] == x)
    {
        return l;
    }
    return RLinearSearch(vec,l+1,r,x);
}
int BinarySearch(vector<int> &vec,int l,int r, int x)
{
    while(l<=r)
    {
        int mid = (l + r)/2;
        if(vec[mid] == x)
        {
            return mid;
        }
        else if(vec[mid] > x)
        {
            r = mid-1;
        }
        else
        {
            l = mid+1; 
        }
    }
    return -1;
}
int RBinarySearch(vector<int> &vec,int l,int r, int x)
{
        if(l > r)
        {
            return -1;
        }
        int mid = (l+r)/2;
        if(vec[mid] == x)
        {
            return mid;
        }
        else if(vec[mid] > x)
        {
            return RBinarySearch(vec,l,mid-1,x);
        }
        else{
            return RBinarySearch(vec,mid+1,r,x);
        }
}
int RotatedBinarySearch(vector<int> vec,int l,int r,int x)
{
    while(l<=r)
    {
        int mid = (l+r)/2;
        if(vec[mid] == x) return mid;
        if(vec[l] <= vec[mid])
        {
            if(x < vec[mid] && x >= vec[l])
            {
                r = mid-1;
            }
            else{l = mid + 1;}
        }
        else
        {
            if(vec[r] >= vec[mid])
            {
                if(x > vec[mid] && x <= vec[r])
                {
                    l = mid+1;
                }
                else{r = mid-1;}
            }
        }
    }
    return -1;
}
int MedianSearch(vector<int> vec,int l,int r,int k)
{
    if(l == r) return vec[l];
    int ind = r-l+1;
    int index = rand() % ind;
    int i;
    vector<int> vec1,vec2,vec3;
    for(i = 0; i < r ; i++)
    {
        if(vec[i] < vec[index])
        {
            vec1.push_back(vec[i]);
        }
        else if(vec[i] == vec[index])
        {
            vec2.push_back(vec[i]);
        }
        else
        {
            vec3.push_back(vec[i]);
        }
    }
    int j = vec1.size();
    int n = vec2.size();
    int m = vec3.size();
    if(j >= k)
    {
        MedianSearch(vec1,0,j - 1,k);
    }
    else if((j+n) >= k)
    {
        return vec[index];
    }
    else
    {
        MedianSearch(vec3,0,m-1,k);
    }
}
int InterpolationSearch(vector<int> vec,int l,int r,int k)
{
    int p = l + ((((k-vec[l])*(r-l))/(vec[r]-vec[l])));
}
int main()
{
    vector<int> vec = {1,2,3,4,5};
    int x = 4;
    int result = LinearSearch(vec,x);
    if(result == -1)
    {
        cout << "not found brotato chip" << endl;
    }
    else{
        cout << "found it brotisserie chicken, at index : " << result << endl;
    }
}