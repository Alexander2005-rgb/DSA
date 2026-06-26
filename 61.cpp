//rotate list 

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        ListNode* rotateRight(ListNode* head, int k) {
           // edge case 
            if(!head || !head->next || k == 0) return head;
            // calculte the length of the linked list and find the tail
            ListNode* tail = head ;
            int len = 1;
            while (tail->next) {
                tail = tail->next;
                len++;
            }

     // optimisze k by taking mod of k with len
            k = k % len;
            if (k == 0 ) return head; // no roatation needed 

       // link tail to head to make a circulr 
            tail -> next = head;

           // find the new tail (length - k ) from start 
            int steps_to_newtail = len - k;
            ListNode* newtail = head ;
            for ( int i = 1; i < steps_to_newtail ; i++){
                newtail = newtail -> next;
            }

            // find the new head 
            ListNode* newhead = newtail->next;

           // break the circle 
            newtail ->next = nullptr;

            return newhead; 
            
        }
};

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main (){
    Solution s;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    int k = 2;
    
    cout << "Original list: ";
    printList(head);
    
    ListNode* newHead = s.rotateRight(head, k);
    
    cout << "Rotated list: ";
    printList(newHead);
    
    return 0;
}
