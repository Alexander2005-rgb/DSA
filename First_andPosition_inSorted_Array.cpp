// find first and last position of an element in sorted array
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
     vector<int> searchRange(vector<int> &nums, int target)
     {
          int left = 0, right = nums.size() - 1;
          vector<int> result = {-1, -1};
          // first opccurence of target
          while (left <= right)
          {
               int mid = left + (right - left) / 2;
               if (nums[mid] == target)
               {
                    result[0] = mid;
                    right = mid - 1;
               }
               else if (nums[mid] < target)
               {
                    left = mid + 1;
               }
               else
               {
                    right = mid - 1;
               }
          }
     }
};
int main()
{
     Solution sol;
     vector<int> nums = {5, 7, 7, 8, 8, 10};
     int target = 8;
     vector<int> result = sol.searchRange(nums, target);
     cout << "First and Last Position of " << target << " is: [" << result[0] << ", " << result[1] << "]" << endl;
     return 0;
}