// longest subarray with given sum k (positives)
// example nums =[10,5,2,7,1,9 ],k=15  output :4


// brute force :

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int subarraySum(vector<int>& nums, int k){
        // calcualte the size of the array 
        int n = nums.size();
        // initiallize the maxi variable to 0
        int maxi = 0;
// iterate over the array to find the longest subarray with sum k
        for(int i = 0; i < n; i++){
            // inintailsie the sum variable to 0 to find the sum of the subarray
            int sum = 0;
            // iterate over the array to find the longest subarray with sum k
            for(int j = i; j < n; j++){
                sum += nums[j];
                if(sum == k){
                    maxi = max(maxi, j - i + 1);
                }
            }
        }
        return maxi;
    }
};
// optimal solution using two pointer  method

class Solution1{
    public:
        int subarraySum(vector<int>& nums, int k){
            int n = nums.size();
            int maxi = 0;
            int l = 0;
            int r = n - 1;
            while(l < r){
                int sum = 0;
                sum += nums[l] + nums[r];
                if(sum == k){
                    maxi = max(maxi, r - l + 1);// r - l + 1 is the length of the subarray
                }
                else if(sum < k){
                    l++;
                }
                else{
                    j--;
                }
            }
            return maxi;

        }
}

int main(){
    Solution s;
    vector<int> nums = {-1,1,1};
    int k = 1;
    cout << s.subarraySum(nums, k) << endl;
}


