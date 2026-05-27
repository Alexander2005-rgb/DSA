// write a program to find the contain duplicate 11 in the array ex = [1,2,3,1] =>output true
#include <bits/stdc++.h>
using namespace std;
bool containsDuplicate(vector<int> &nums, int k)
{
     for (int i = 0; i < nums.size(); i++)
     {
          for (int j = i + 1; j < nums.size(); j++)
          {
               if (nums[i] == nums[j] && abs(i - j) <= k)
               {
                    return true;
               }
          }
     }
     return false;
}
int main()
{
     vector<int> nums = {1, 2, 3, 1, 2, 3};
     int k = 2;
     cout << containsDuplicate(nums, k) << endl;
     return 0;
}