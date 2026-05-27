// find tghe majority element in the array give output {3,2,3} => 3
#include <bits/stdc++.h>
using namespace std;
int majorityElement(vector<int> &nums)
{
     int j = 0;
     for (int i = 1; i < nums.size(); i++)
     {
          if (nums[i] == nums[j])
          {
               j++;
          }
     }
     if (j > nums.size() / 2)
     {
          cout << nums[j] << endl;
     }
     return 0;
}
int majorityElement1(vector<int> &nums)
{
     map<int, int> mp;
     for (int i = 0; i < nums.size(); i++)
     {
          mp[nums[i]]++;
     }
     for (auto x : mp)
     {
          if (x.second > nums.size() / 2)
          {
               cout << x.first << endl;
               return 0;
          }
     }
}
int main()
{
     vector<int> nums = {3, 2, 3};
     majorityElement(nums);

     return 0;
}
