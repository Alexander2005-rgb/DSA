//maximum icecream bars

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        // Counting sort
        // Find the maximum cost to determine the size of the counting array
        int maxCost = 0;
        for (int cost : costs) {
            maxCost = max(maxCost, cost);
        }

        // Create a frequency array for counting sort
        vector<int> counts(maxCost + 1, 0);
        for (int cost : costs) {
            counts[cost]++;
        }

        int iceCreamBars = 0;
        // Iterate through the sorted costs (represented by the counts array)
        for (int cost = 1; cost <= maxCost; ++cost) {
            if (counts[cost] > 0) {
                // Number of ice cream bars we can buy at this specific cost
                // and have enough coins
                int canBuy = min(counts[cost], coins / cost);
                iceCreamBars += canBuy;
                coins -= canBuy * cost;
                if (coins == 0) {
                    break;
                }
            }
        }
        return iceCreamBars;
    }
};