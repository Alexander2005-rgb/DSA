// smallest positive missing number
#include <bits/stdc++.h>
using namespace std;
int missing(int arr[], int n)
{
     for (int i = 0; i < n; i++)
     {
          if (arr[i] > 0 && arr[i] < n)
          {
               arr[arr[i] - 1] = -arr[arr[i] - 1];
          }
          else if (arr[i] < 0 && arr[i] >= -n)
          {
          }
     }
}
int main()
{
     int arr[] = {5, 3, 2, 5, 1};
     int n = sizeof(arr) / sizeof(arr[0]);
     cout << "smallest positive mising number =" << missing(arr, n);
}