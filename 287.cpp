// find the duplicate number 

/**
The optimal way to achieve $O(N)$ time and $O(1)$ space under these constraints is Floyd's Tortoise and Hare (Cycle Detection) algorithm. Because the values in the array are between $1$ and $n$, and the array length is $n+1$, we can treat the array as a directed graph where an edge exists from index i to index nums[i]. A duplicate value means multiple indices point to the same next node, creating a cycle. */

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Phase 1: Detect the intersection point in the cycle
        int tortoise = nums[0];
        int hare = nums[0];
        
        do {
            tortoise = nums[tortoise];      // Moves 1 step
            hare = nums[nums[hare]];          // Moves 2 steps
        } while (tortoise != hare);

        // Phase 2: Find the entrance to the cycle
        // Reset tortoise to the start
        tortoise = nums[0];
        // Move both at the same speed (1 step)
        while (tortoise != hare) {
            tortoise = nums[tortoise];
            hare = nums[hare];
        }

        return hare;
    }
};
