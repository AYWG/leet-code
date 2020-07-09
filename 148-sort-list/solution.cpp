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
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        
        // Split into halves.
        pair<ListNode*, ListNode*> halves = split(head);
        ListNode* left = halves.first;
        ListNode* right = halves.second;
        
        // Merge sort recursively
        ListNode* sortedLeft = sortList(left);
        ListNode* sortedRight = sortList(right);
        
        // Merge results.
        return merge(sortedLeft, sortedRight);
    }
    
    pair<ListNode*, ListNode*> split(ListNode* head) {
        ListNode* first = head;
        ListNode* second = head->next;
        
        if (head == NULL) return make_pair(first, second);
        
        while (second->next != NULL) {
            first = first->next;
            
            second = second->next;
            if (second->next != NULL) {
                second = second->next;
            }
        }
        
        ListNode* right = first->next;
        first->next = NULL;
        
        return make_pair(head, right);
    }
    
    ListNode* merge(ListNode *l1Sorted, ListNode *l2Sorted) {
        if (l1Sorted == NULL && l2Sorted == NULL) return NULL;
        
        if (l1Sorted != NULL && l2Sorted == NULL) return l1Sorted;
        if (l1Sorted == NULL && l2Sorted != NULL) return l2Sorted;
        
        if (l1Sorted->val <= l2Sorted->val) {
            l1Sorted->next = merge(l1Sorted->next, l2Sorted);
            return l1Sorted;
        } else {
            l2Sorted->next = merge(l1Sorted, l2Sorted->next);
            return l2Sorted;
        }
    }
};