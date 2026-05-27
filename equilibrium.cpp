// equlibrium point in an array
#include <bits/stdc++.h>
using namespace std;
int equilibrium(int arr[], int n)

{
     int leftsum = 0;
     int rightsum = 0;
     for (int i = 0; i < n; i++)
     {
          rightsum = rightsum + arr[i];
     }
     for (int i = 0; i < n; i++)
     {
          rightsum -= arr[i];
          if (leftsum == rightsum)
          {
               return i;
          }
          leftsum += arr[i];
     }
     return -1;
};

int main()
{
     int arr[] = {1, 1, 1, 1};
     int n = sizeof(arr) / sizeof(arr[0]);
     cout << equilibrium(arr, n);
     return 0;
}