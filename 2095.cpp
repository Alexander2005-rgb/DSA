class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return nullptr; // No middle node to delete or only one node
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr; // To keep track of the node before 'slow'

        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // At this point, 'slow' is at the middle node, and 'prev' is the node before it.
        // We need to handle the case where the middle node is the head (for a two-node list).
        if (prev == nullptr) { // This means the list had only two nodes initially
            return head->next; // Return the second node
        }

        prev->next = slow->next; // Delete the middle node

        return head;
    }
};