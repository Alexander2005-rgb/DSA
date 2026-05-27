// move zeroes to the end of the array in the array
#include <bits/stdc++.h>
using namespace std;
void moveZeroes(vector<int> &nums)
{
     int j = 0;
     for (int i = 0; i < nums.size(); i++)
     {
          if (nums[i] != 0)
          {
               swap(nums[i], nums[j]);
               j++;
          }
     }
     for (int i = 0; i < nums.size(); i++)
     {
          cout << nums[i] << " ";
     }
}
void moveZeroes1(vector<int> &nums)
{
     int j = 0;
     for (int i = 0; i < nums.size(); i++)
     {
          if (nums[i] == 0)
          {
               j++;
          }
          else if (j > 0)
          {
               int t = nums[i];
               nums[i] = 0;
               nums[i - j] = t;
          }
     }
     for (int i = 0; i < nums.size(); i++)
     {
          cout << nums[i] << " ";
     }
}
int main()
{
     vector<int> nums = {0, 1, 0, 3, 12};
     // moveZeroes(nums);
     moveZeroes1(nums);
     return 0;
}