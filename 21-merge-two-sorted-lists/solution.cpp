/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL && l2 == NULL) return NULL;

        if (l1 == NULL && l2 != NULL) return l2;

        if (l1 != NULL && l2 == NULL) return l1;

        // Both l1 and l2 are not NULL
        if (l1->val <= l2->val) {
            // Grab node from l1
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            // Grade node from l2
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};