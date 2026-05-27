// wap which will take all negative to the right side of the array input = [3,-2,-7,8,9,10,-10,12] output = [3,8,9,10,12,-2,-7,-10]
#include <bits/stdc++.h>
using namespace std;
void negativeright(int arr[], int n)
{
     int j = 0;
     for (int i = 0; i < n; i++)
     {
          if (arr[i] >= 0)
          {
               swap(arr[i], arr[j]);
               j++;
          }
     }
     for (int i = 0; i < n; i++)
     {
          cout << arr[i] << " ";
     }
}
int main()
{
     int arr[] = {3, -2, -7, 8, 9, 10, -10, 12};
     int n = sizeof(arr) / sizeof(arr[0]);
     negativeright(arr, n);
     return 0;
}
