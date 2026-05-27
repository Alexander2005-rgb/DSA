// wap to check the array is sorted and rotated
#include <bits/stdc++.h>
using namespace std;
int sorted(int arr[], int n)
{
     int count = 0;
     for (int i = 1; i < n; i++)
     {
          if (arr[i - 1] > arr[i])
               count++;
     }
     if (arr[n - 1] > arr[0])
          count++;
     return (count <= 1);
     // check it is clockwise or anticlockwise
}

int main()
{
     int arr[] = {7, 8, 1, 2, 3, 4, 5, 6};
     int n = sizeof(arr[n]) / sizeof(arr[0]);
     if (sorted(arr, n))
     {
          cout << "Araay is sorted and rotated";
     }
     else
     {
          cout << "the aray is not sorted and rotated";
     }
}