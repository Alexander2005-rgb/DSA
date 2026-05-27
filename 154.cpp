// find minimum in rotated sorted array 2
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            // If mid element is greater than rightmost element,
            // the minimum is in the right half
            if (nums[mid] < nums[right]){
                right = mid;
            }
            else
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            }
            // Otherwise, the minimum is in the left half
            else {
                right--;
            }
        }
        
        return nums[left];
    }
};
int main(){
    Solution s;
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<s.findMin(nums)<<endl;
    return 0;

}