// find the pivot index in the array
#include <bits/stdc++.h>
using namespace std;
int pivotIndex(int arr[], int n)
{
     int totalSum = 0;
     for (int i = 0; i < n; i++)
     {
          totalSum += arr[i];
     }
     int leftSum = 0;
     for (int i = 0; i < n; i++)
     {
          if (leftSum == totalSum - leftSum - arr[i])
          {
               return i;
          }
          leftSum += arr[i];
     }
     return -1;
}
int main()
{
     int nums[] = {1, 7, 3, 6, 5, 6};
     int n = sizeof(nums) / sizeof(nums[0]);
     int pivot = pivotIndex(nums, n);
     if (pivot != -1)
     {
          cout << "Pivot index is: " << pivot << endl;
     }
     else
     {
          cout << "No pivot index found" << endl;
     }
     return 0;
}