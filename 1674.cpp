// minimum moves to make array complementry

#include<bits/stdc++.h>
using namespace std;


class Solution{
    public:
        int minMoves(vector<int> &nums, int limit){
            int n = nums.size();
            // diff[x] stores the change in moves required if the target sum is x
            // Target sum ranges from 2 to 2 * limit
            vector<int> diff(2 * limit + 2, 0);
            
            for(int i = 0; i < n / 2; i++){
                int a = nums[i];
                int b = nums[n - 1 - i];
                
                // For a pair (a, b), the possible sum ranges with different moves:
                // 1. [2, min(a, b)]: 2 moves
                // 2. [min(a, b) + 1, a + b - 1]: 1 move
                // 3. [a + b]: 0 moves
                // 4. [a + b + 1, max(a, b) + limit]: 1 move
                // 5. [max(a, b) + limit + 1, 2 * limit]: 2 moves
                
                // Using difference array starting with 2 moves for every pair:
                // diff[2] already implicitly starts with 2 moves (handled by initial minm = n)
                
                int mini = min(a, b);
                int maxi = max(a, b);
                
                // Range [mini + 1, maxi + limit] needs only 1 move
                diff[mini + 1] -= 1;
                diff[maxi + limit + 1] += 1;
                
                // Sum exactly a + b needs 0 moves
                diff[a + b] -= 1;
                diff[a + b + 1] += 1;
            }
            
            int minm = n; // Max possible moves is n (2 for each n/2 pair)
            int curr_moves = n; 
            for(int i = 2; i <= 2 * limit; i++){
                curr_moves += diff[i];
                minm = min(minm, curr_moves);
            }
            return minm;
        }
};

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int limit;
    cin>>limit;
    Solution sol;
    cout<<sol.minMoves(nums,limit)<<endl;

    
}