// rtoate array by k places 
// frist think could you do it in-place with O(1) extra space? 

#include <iostream>
#include <vector>

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        if (k == 0) {
            return;
        }
        vector<int> temp(k);
        for (int i = 0; i < k; i++) {
            temp[i] = nums[n - k + i];
        }
        for (int i = n - 1; i >= k; i--) {
            nums[i] = nums[i - k];
        }
        for (int i = 0; i < k; i++) {
            nums[i] = temp[i];
        }
    }
};
class SOlution2{
    public:
    void rotate(vector<int>& nums, int k){
        int n = nums.size();
        // handle case where k>=n
        k = k%n ;
        //reverse the entire array 
        reverse(nums.begin(), nums.end());
        //reverse the first k elements 
        reverse(nums.begin(), nums.begin()+k);
        // reverse the remaining n-k elements 
        reverse(nums.begin()+k, nums.end());
    }
};
