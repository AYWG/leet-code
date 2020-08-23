/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
/*
1. Search for the node with key
    - follow BST properties

2. Delete node if found
    Case: node is a leaf
    Case: node is not a leaf
        1. Find smallest node in right subtree of node to be deleted
            - if right subtree does not exist, find biggest node in left subtree of node to be deleted
            - in either case, keep track of parent
        2. 
        Modify node to be deleted's key with smallest/biggest node's key
        free smallest/biggest node
        Case: smallest/biggest node is leaf
            - update parent reference to be NULL

        Case: smallest/biggest node has subtree
            - update parent reference to point to subtree instead of smallest/biggest node
*/

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) return NULL;
        
        // Search.
        TreeNode* parent = NULL;
        TreeNode* searchNode = root;
        
        while (searchNode != NULL) {
            if (searchNode->val == key) break;
            
            parent = searchNode;
            if (searchNode->val > key) {
                // left
                searchNode = searchNode->left;
            } else {
                searchNode = searchNode->right;
            }
        }
        
        // target node not found
        if (searchNode == NULL) return root;        
    
        // leaf
        if (searchNode->left == NULL && searchNode->right == NULL) {
            // single node case (leaf, but no parent)
            if (parent == NULL) {
                delete searchNode;
                return NULL;
            }
            
            if (parent->left == searchNode) {
                parent->left = NULL;
            }
            else {
                parent->right = NULL;    
            }
            delete searchNode;
            return root;
        }
        
        // non-leaf
        parent = searchNode;
        
        // Find smallest node in right subtree, or biggest node in left subtree
        if (searchNode->right != NULL) {
            // Right subtree.
            TreeNode *smallestNode = searchNode->right;
            
            while (smallestNode->left != NULL) {
                parent = smallestNode;
                smallestNode = smallestNode->left;
            }
            
            // Swap and delete.
            searchNode->val = smallestNode->val;
            
            // Different behaviour depending on if smallest node is leaf or not.
            if (smallestNode->right == NULL) {
                if (parent->right == smallestNode) parent->right = NULL;
                else parent->left = NULL;
                    
            }
            else {
                if (parent->right == smallestNode) {
                    parent->right = smallestNode->right;
                }
                else {
                    parent->left = smallestNode->right;
                }
            }
            delete smallestNode;
            
        }
        else {
            // Left subtree.
            TreeNode *biggestNode = searchNode->left;
            
            while (biggestNode->right != NULL) {
                parent = biggestNode;
                biggestNode = biggestNode ->right;   
            }
            
            // Swap and delete.
            searchNode->val = biggestNode->val;
            
            if (biggestNode->left == NULL) {
                if (parent->left == biggestNode) parent->left = NULL;
                else parent->right = NULL;
            }
            else {
                if (parent->left == biggestNode) {
                    parent->left = biggestNode->left;
                }
                else {
                    parent->right = biggestNode->left;
                }
                
            }
            delete biggestNode;
        }
        
        return root;
    }
};