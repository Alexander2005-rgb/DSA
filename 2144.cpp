//minimum cost of buying candies with discount 
/*A shop is selling candies at a discount. For every two candies sold, the shop gives a third candy for free.

The customer can choose any candy to take away for free as long as the cost of the chosen candy is less than or equal to the minimum cost of the two candies bought.

For example, if there are 4 candies with costs 1, 2, 3, and 4, and the customer buys candies with costs 2 and 3, they can take the candy with cost 1 for free, but not the candy with cost 4.
Given a 0-indexed integer array cost, where cost[i] denotes the cost of the ith candy, return the minimum cost of buying all the candies.*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        if (n == 0) return 0;
        
        // Sort in descending order so we get the most expensive items free
        sort(cost.rbegin(), cost.rend());
        
        int sum = 0;
        for (int i = 0; i < n; i++) {
            // Pay for items at positions 0,1, then skip position 2 (free), repeat
            if (i % 3 != 2) {
                sum += cost[i];
            }
        }
        
        return sum;
    }
};

int main(){
    Solution s;
    vector<int> cost = {1,2,3,4,5};
    cout << s.minimumCost(cost) << endl;
    return 0;
}