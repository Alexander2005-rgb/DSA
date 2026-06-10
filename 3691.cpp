// maximum total subaeeay value 2
/*
    You are given a 0-indexed integer array nums of length n and an integer k.
    The value of a subarray is defined as the maximum element in the subarray multiplied by the minimum element in the subarray, multiplied by the length of the subarray.
    Return the maximum value among all subarrays of nums.
*/

#include <bits/stdc++.h>  
using namespace std;  
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();

        int max_val = *max_element(nums.begin(), nums.end());
        int min_val = *min_element(nums.begin(), nums.end());

        if (max_val == min_val) {
            return 0;
        }

        long long max_value = 1LL * (max_val - min_val);

        long long count_max =
            countSubarraysContainingBoth(nums, max_val, min_val);

        if (count_max >= k) {
            return max_value * k;
        }

        return solveGeneral(nums, k);
    }

private:
    long long countSubarraysContainingBoth(
        const vector<int>& nums, int a, int b) {

        int n = nums.size();
        long long ans = 0;

        int lastA = -1, lastB = -1;

        for (int r = 0; r < n; r++) {
            if (nums[r] == a) lastA = r;
            if (nums[r] == b) lastB = r;

            if (lastA != -1 && lastB != -1) {
                ans += min(lastA, lastB) + 1;
            }
        }

        return ans;
    }

    long long solveGeneral(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> nextGreater(n, n), prevGreater(n, -1);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                nextGreater[st.top()] = i;
                st.pop();
            }

            if (!st.empty())
                prevGreater[i] = st.top();

            st.push(i);
        }

        while (!st.empty()) st.pop();

        vector<int> nextSmaller(n, n), prevSmaller(n, -1);

        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                nextSmaller[st.top()] = i;
                st.pop();
            }

            if (!st.empty())
                prevSmaller[i] = st.top();

            st.push(i);
        }

        // TODO:
        // Implement the actual logic for finding the
        // sum of the top-k subarray values.
        // Currently returns 0 as a placeholder.

        return 0;
    }
}; 
int main() {
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 10;
    cout << s.maximumTotalValue(nums, k) << endl;
    return 0;
}