#include <bits/stdc++.h>
using namespace std;
void swap2(int &a,int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void BubbleSort(vector<int> &vec)
{
    int i,j;
    for(i = 0 ; i < vec.size() ; i++)
    {
        for(j = 0; j < vec.size() - i ; j++)
        {
            if(vec[j] > vec[j+1])
            {
                swap2(vec[j], vec[j+1]);
            }
        }
    }
}
void SelectionSort(vector<int> &vec)
{
    for(int i = 0; i < vec.size(); i++)
    {
        int minIndex = i;
        for(int j = i+1; j < vec.size(); j++)
        {
            if(vec[j] < vec[minIndex])
            {
                minIndex = j;
            }
        }
        swap2(vec[minIndex],vec[i]);
    }
    

}
// void SelectionSort2(vector<int> &vec)
// {
//     for(int i = 0 ; i < vec.size(); i++)
//     {
//         for(int j = i + 1; j < vec.size(); j++)
//         {
//             if(vec[j] < vec[i])
//             {
//                 swap2(vec[j],vec[i]);
//             }
//         }
//     }
// }
void InsertionSort(vector<int> &vec)
{
   for(int i = 1; i < vec.size(); i++)
   {
    int key = vec[i];
    int j = i-1;
    while(j >= 0  && vec[j] > key)
    {
        vec[j+1] = vec[j];
        j--;
    }
    vec[j+1] = key;
   }
}
int partition(vector<int> vec,int low,int high)
{
    int pivot = vec[high];
    int i = low-1;
    for(int j = low; j < high ; j++)
    {
        if(vec[j] <= pivot)
        {
            i++;
            swap2(vec[i],vec[j]);
        }
    }
    swap2(vec[i+1],vec[high]);
    return i+1;
}
int partition2(vector<int> &vec, int low, int high)
{
    int pivot = vec[low];  // Pivot is now the FIRST element
    int i = low;           // Start from low instead of low-1
    
    for(int j = low + 1; j <= high; j++)  // Start from low+1
    {
        if(vec[j] <= pivot)
        {
            i++;
            swap2(vec[i], vec[j]);
        }
    }
    
    // Swap pivot (first element) to its correct position
    swap2(vec[low], vec[i]);
    return i;  // Return pivot's final position
}
void QuickSort(vector<int> &vec,int l,int r)
{
    if(l<r)
    {
        int q = partition(vec,l,r);
        QuickSort(vec,l,q-1);
        QuickSort(vec,q+1,r);
    }
}
void merge(vector<int> vec, int low,int mid,int high)
{
    int n1 = mid- low + 1;
    int n2 = high - mid;
    vector<int> vec2,vec3;
    for(int i = 0; i < n1; i++)
    {
        vec2.push_back(vec[i]);
    }
    for(int i = mid+1; i < n2 ; i++)
    {
        vec3.push_back(vec[i]);
    }
    int i = 0, j = 0, k = low;
    while(i < n1 && j < n2)
    {
        if(vec2[i] <= vec3[j])
        {
            vec[k] = vec2[i];
            k++;
            i++;
        }
        else
        {
            vec[k] = vec3[j];
            k++;
            j++;
        }
    }
    while(i<n1)
    {
        vec.push_back(vec2[i]);
        i++;
        k++;
    }
    while(j < n2)
    {
        vec.push_back(vec3[j]);
        k++;
        j++;
    }
}
int MergeSort(vector<int> &vec,int low,int high)
{
    while(low<high)
    {
    int mid = (low+high)/2;
    MergeSort(vec,low,mid-1);
    MergeSort(vec,mid+1,high);
    merge(vec,low,mid,high);
    }
}
void countingSortForRadix(vector<int>& arr, int exp) {
    vector<int> output(arr.size());
    vector<int> count(10, 0);  // 0-9 digits

    // Store count of occurrences
    for (int i = 0; i < arr.size(); i++)
        count[(arr[i] / exp) % 10]++;

    // Change count to cumulative count
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build output array
    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy output to original array
    for (int i = 0; i < arr.size(); i++)
        arr[i] = output[i];
}
void radixSort(vector<int>& arr) {
    int max = *max_element(arr.begin(), arr.end());
    
    // Do counting sort for every digit
    for (int exp = 1; max / exp > 0; exp *= 10)
        countingSortForRadix(arr, exp);
}