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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        bool carry = false;
        
        // know that l1 and l2 are non-empty. 
        int sum = l1->val + l2-> val;
        
        if (sum >= 10) carry = true;    
        
        // The head of the sum linked list. 
        ListNode* sum_head = new ListNode(sum % 10);
        // The node pointer we work with in the linked list sum.
        ListNode* curr_sum_node = sum_head;
        
        // The node pointer we work with in l1.
        ListNode* curr_l1_node = l1->next;
        // The node pointer we work with in l2.
        ListNode* curr_l2_node = l2->next;
                
        // We stop if both l1 and l2 are NULL
        while (curr_l1_node != NULL || curr_l2_node != NULL || carry) {
            int l1_node_val = 0;
            int l2_node_val = 0;
            int node_sum = 0;
            if (curr_l1_node != NULL) {
                l1_node_val = curr_l1_node->val;
                curr_l1_node = curr_l1_node->next;
            }
            if (curr_l2_node != NULL) {
                l2_node_val = curr_l2_node->val;
                curr_l2_node = curr_l2_node->next;
            }
            
            // add the two node values
            node_sum = l1_node_val + l2_node_val;
            
            if (carry) {
                node_sum++;
            }
            
            if (node_sum >= 10) carry = true;
            else carry = false;
            
            // create the new node for the sum linked list and append it.
            curr_sum_node->next = new ListNode(node_sum % 10);
            
            curr_sum_node = curr_sum_node->next;
        }
        
        return sum_head;
        
    }
};