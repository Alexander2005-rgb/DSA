// remove duplicate element form the array
#include <bits/stdc++.h>
using namespace std;
int removeDuplicate(int arr[], int n)
{
     if (n == 0 || n == 1)
          return n;

     int j = 0;
     for (int i = 0; i < n - 1; i++)
          if (arr[i] != arr[i + 1])
               arr[j++] = arr[i];

     arr[j++] = arr[n - 1];

     return j;
}
int main()
{
     int arr[] = {1, 2, 4, 3, 2, 1, 3};
     int n = sizeof(arr) / sizeof(arr[0]);
     sort(arr, arr + n);
     int new_size = removeDuplicate(arr, n);
     for (int i = 0; i < new_size; i++)
     {
          cout << arr[i] << " ";
     }
     return 0;
}