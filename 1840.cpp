// maximum building height 

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        // Step 1: Push the boundary constraints
        restrictions.push_back({1, 0});
        
        // Sort restrictions by building ID
        sort(restrictions.begin(), restrictions.end());
        
        // If the last building isn't restricted, adding a dummy restriction at 'n' 
        // with maximum possible height simplifies the loop logic.
        if (restrictions.back()[0] != n) {
            restrictions.push_back({n, n - 1});
        }
        
        int m = restrictions.size();
        
        // Step 2: Forward Pass (Left to Right)
        for (int i = 1; i < m; ++i) {
            int limitFromLeft = restrictions[i - 1][1] + (restrictions[i][0] - restrictions[i - 1][0]);
            restrictions[i][1] = min(restrictions[i][1], limitFromLeft);
        }
        
        // Step 3: Backward Pass (Right to Left)
        for (int i = m - 2; i >= 0; --i) {
            int limitFromRight = restrictions[i + 1][1] + (restrictions[i + 1][0] - restrictions[i][0]);
            restrictions[i][1] = min(restrictions[i][1], limitFromRight);
        }
        
        // Step 4: Calculate the absolute maximum height between any two checkpoints
        int max_height = 0;
        for (int i = 0; i < m - 1; ++i) {
            int x1 = restrictions[i][0], h1 = restrictions[i][1];
            int x2 = restrictions[i + 1][0], h2 = restrictions[i + 1][1];
            
            // Peak formula between two clamped restrictions
            int peak = (h1 + h2 + (x2 - x1)) / 2;
            max_height = max(max_height, peak);
        }
        
        return max_height;
    }
};
 
int main(){
    int n;
    cin>>n;
    vector<vector<int>> restrictions(n,vector<int>(2));
    for(int i=0;i<n;i++){
        cin>>restrictions[i][0]>>restrictions[i][1];
    }
    Solution sol;
    cout<<sol.maxBuilding(n,restrictions)<<endl;
    return 0;
}
