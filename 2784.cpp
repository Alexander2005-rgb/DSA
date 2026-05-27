// check if array is good  ex = base[3]= [1,2,3,3]

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public: 
        bool isGood(vector<int>& nums){
            int n = nums.size();
            int max_num = 0;
            for(int i= 0; i<n; i++){
                max_num = max(max_num, i);
            }
            if (n != max_num + 1){
                return false;
            }
            vector<int> counts(max_num +1 ,0);
            for(int i=0;i<n;i++){
                counts[nums[i]]++;
            }
            if (counts[max_num] != 2){
                return false;
            }
            for(int i=1; i<max_num;i++){
                if(counts[i] != 1){
                    return false;
                }
            }
            return true;
        }
};

int main(){
    Solution sol;
    vector<int> nums;
    int n;
    cin>>n;
    nums.resize(n);
    for(int i =0; i<n;i++){
        cin>>nums[i];
    }
    if (sol.isGood(nums)){
        cout<<"Good";
    }
    else{
        cout<<"Not Good";
    }


}