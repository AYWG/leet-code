/*

Algorithm:

Iterate through linked list until we reach tail
    if a node's child is not null
        flatten(child)
        get reference to next node
        get reference to tail of child
        node->next = child
        child->prev = node
        
        tail->next = next
        next->prev = tail
        node->child = NULL


*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* curr = head;
        
        while (curr != NULL) {
            if (curr->child != NULL) {
                // flattenedChild cannot be NULL
                Node* flattenedChild = flatten(curr->child);
                
                Node* nextNode = curr->next;
                Node* childTail = getTail(flattenedChild);
                
                curr->next = flattenedChild;
                flattenedChild->prev = curr;
                childTail->next = nextNode;
                
                if (nextNode != NULL) {
                    nextNode->prev = childTail;
                }
                curr->child = NULL;
            }
            
            curr = curr->next;
        }
        
        return head;
    }
    
    Node* getTail(Node* head) {
        if (head == NULL || head->next == NULL) return head;
        
        return getTail(head->next);
    }
};