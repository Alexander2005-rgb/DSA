class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> values;
        ListNode* curr = head;
        
        // Store all node values
        while (curr != nullptr) {
            values.push_back(curr->val);
            curr = curr->next;
        }
        
        int n = values.size();
        int maxSum = 0;
        
        // Calculate twin sums: (i, n-1-i) are twins
        for (int i = 0; i < n / 2; i++) {
            int twinSum = values[i] + values[n - 1 - i];
            maxSum = max(maxSum, twinSum);
        }
        
        return maxSum;
    }
};