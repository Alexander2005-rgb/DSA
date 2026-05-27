// maximum water trap
#include <bits/stdc++.h>
using namespace std;

int trapWater(int arr[], int n)
{
     int left_max[n];
     int right_max[n];
     left_max[0] = arr[0];
     for (int i = 0; i <= n; i++)
     {
          left_max[i] = max(left_max[i - 1], arr[i]);
     }
     right_max[n - 1] = arr[n - 1];

     for (int i = n - 2; i >= 0; i--)
     {
          right_max[i] = max(right_max[i + 1], arr[i]);
     }
     int ans = 0;
     for (int i = 0; i < n - 1; i++)
     {
          ans = ans + min(left_max[i], right_max[i]) - arr[i];
     }
     return ans;
}
int maxArea(vector<int> &height)
{
     int max_area = 0;
     int left = 0;
     int right = height.size() - 1;
     while (left < right)
     {
          int area = min(height[left], height[right]) * (right - left);
          max_area = max(max_area, area);
          if (height[left] < height[right])
          {
               left++;
          }
          else
          {
               right--;
          }
     }
     return max_area;
}
int main()
{
     vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
     cout << maxArea(height);
     return 0;
}

//      int arr[] = {2, 1, 5, 3, 1, 0, 4};
//      int n = sizeof(arr) / sizeof(arr[0]);
//      cout << "Total water trap =" << trapWater(arr, n);
//      return 0;
// }