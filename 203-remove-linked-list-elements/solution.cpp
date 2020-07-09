/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *prev = NULL;
        ListNode *curr = head;
        
        while (curr !=  NULL) {
            if (curr->val == val) {
                // Do removal
                
                // Case 1: head
                if (prev == NULL) {
                    head = head->next;
                    curr = head;
                    continue;
                }
                
                // Case 2: Somewhere in the middle
                prev->next = curr->next;
                curr = curr->next;
                continue;
            }
            
            // Advance.
            prev = curr;
            curr = curr->next;
        }
        
        return head;
    }
};