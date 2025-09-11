#include <bits/stdc++.h>
using namespace std;
int binary_search(int A[], int l, int r, int x)

{

while (l <= r) {

int mid = (l + r) / 2;

if (A[mid] == x)

return mid;

if (A[mid] < x)
// If x greater, ignore left half

l = mid + 1;

else
// If x is smaller, ignore right half

r = mid - 1;

}

return -1;
// if we reach here, then element was not present

}
