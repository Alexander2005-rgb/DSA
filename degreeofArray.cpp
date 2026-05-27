// find the degree of an array
#include <bits/stdc++.h>
using namespace std;
int findDegreeOfArray(vector<int> &nums)
{
     unordered_map<int, int> freq;
     int degree = 0;
     for (int num : nums)
     {
          freq[num]++;
          degree = max(degree, freq[num]);
     }
     // find the subarray with the same degree and count the length
     int minLength = nums.size();
     for (auto &x : freq)
     {
          if (x.second == degree)
          {
               int left = 0, right = nums.size() - 1;
               while (nums[left] != x.first)
                    left++;
               while (nums[right] != x.first)
                    right--;

               minLength = min(minLength, right - left + 1);
          }
     }
     return minLength;
}
int findDegreeOfArray1(vector<int> &nums)
{
     map<int , int> freq,first, last;
     for(int i =0; i < nums.size();i++){
          freq[nums[i]]++;
          if(!first.count(nums[i])){
               first[nums[i]] = i;
          }
          last[nums[i]] = i;
     }
     int degree = 0;
     for(auto &x : freq){
          degree = max(degree, x.second);
     }
     int minLength = nums.size();
     for(auto &x : freq){
          if(x.second == degree){
               minLength = min(minLength, last[x.first] - first[x.first] + 1);
          }
     }
     return minLength;


}

int main()
{
     vector<int> nums = {1, 2, 2, 3, 1, 4, 2};
     cout < << findDegreeOfArray(nums) << endl;
     return 0;
}