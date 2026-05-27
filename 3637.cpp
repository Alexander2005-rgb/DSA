// trionic array I
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
     int trionicArray(vector<int> &arr)
     {
          int n = arr.size();
          if (n < 3)
               return 0; // Not enough elements to form a trionic array

          int count = 0;
          for (int i = 1; i < n - 1; ++i)
          {
               if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
               {
                    count++;
               }
          }
          return count;
     }
     bool isTrionic1(vector<int> &nums)
     {
          int n = nums.size();
          if (n < 3)
               return false; // Not enough elements to form a trionic array

          for (int i = 1; i < n - 1; ++i)
          {
               if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
               {
                    return true; // Found a trionic element
               }
          }
          return false; // No trionic elements found
     }
     bool isTrionicArray2(vector<int> &nums)
     {
          int n = nums.size();
          if (nums[0] >= nums[1])
          {
               return false;
          }
          int count = 1;
          for (int i = 2; i < n; i++)
          {
               if (nums[i - 2] == nums[i])
               {
                    return false;
               }
               if ((nums[i - 2] - nums[i - 1]) * (nums[i - 1] - nums[i]) < 0)
               {
                    count++;
               }
          }
          return count == 3;
     }
};
int main()
{
     Solution obj;
     vector<int> arr = {2, 1, 3};
     cout << obj.trionicArray(arr) << endl;    // Output the count of trionic elements
     cout << obj.isTrionic1(arr) << endl;      // Output whether the array is trionic
     cout << obj.isTrionicArray2(arr) << endl; // Output whether the array is trionic array 2
     return 0;
}