#include <bits/stdc++.h>
using namespace std;
int maxsub(int arr[], int n)
{
     int result = 0;
     int cur = 0;
     for (int i = 0; i < n; i++)
     {
          if (cur < 0)
          {
               cur = 0;
          }
          cur += arr[i];
          result = max(cur, result);
     }
     return result;
}
int main()
{
     int arr[] = {2, 1, -6, -8, 4, 7};
     int n = sizeof(arr) / sizeof(arr[0]);
     cout << "the maxsum =" << maxsub(arr, n);
     return 0;
}