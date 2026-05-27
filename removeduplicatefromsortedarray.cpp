// remove duplicate elememt from sorted array
#include <bits/stdc++.h>
using namespace std;
int removeDuplicates(vector<int> &nums)
{
     int j = 0;
     for (int i = 1; i < nums.size(); i++)
     {
          if (nums[i] != nums[j])
          {
               j++;
               nums[j] = nums[i];
          }
     }
     cout << j + 1 << endl;
     return 0;
}
int main()

{
     vector<int> nums = {1, 1, 2};
     int n = removeDuplicates(nums);

     return 0;
}