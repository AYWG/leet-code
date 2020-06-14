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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL || head->next->next == NULL) {
            return head;
        }
        
        int length = 2;
        
        ListNode* firstEvenNode = head->next;
        
        ListNode* currNode = head->next;
        ListNode* prevNode = head;
        
        while(currNode->next != NULL) {
            prevNode->next = currNode->next;
            
            prevNode = currNode;
            currNode = currNode->next;
            length++;
        }
        
        // Combine.
        
        // Odd length
        if (length % 2 != 0) {
            prevNode->next = NULL;
            currNode->next = firstEvenNode;    
        }
        // Even length
        else {
            prevNode->next = firstEvenNode;            
        }
        
        
        return head;
    }
};