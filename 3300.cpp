// minimum element after replacement with digit sum

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int digitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    int minElement(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            nums[i] = digitSum(nums[i]);
        }

        int minVal = INT_MAX; // Or nums[0] after the first element is processed
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < minVal) {
                minVal = nums[i];
            }
        }
        return minVal;
    }
};
int main(){
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << s.minElement(nums) << endl;
}