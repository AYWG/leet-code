/*

How to define a tree based on pre and in order?

- Root is always first element of pre-order.
- For pre-order, the traversal is: root, everything in left, then everything in right
    - Can divide into sections of known length
- For in-order, everything to the left of the root is in the left subtree, and same for right


Algorithm:
    1. Create root node using first element of pre-order
    2. Find root in in-order and return its index
    3. Compute index boundaries for left and right subtrees
    4. Recurse 

*/

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
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeHelper(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
    
    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, int start, int end, int inorderStart, int inorderEnd) {
        if (start > end) {
            return NULL;
        }
        
        TreeNode* root = new TreeNode(preorder[start]);
        
        int rootIndex = -1;
        for (int i = inorderStart; i <= inorderEnd; i++) {
            if (inorder[i] == root->val) {
                rootIndex = i;
                break;
            }
        }
        
        int startLeft = start + 1;
        int endLeft = startLeft + rootIndex - inorderStart - 1;
        int startRight = endLeft + 1;
        int endRight = end;
        
        int inorderStartLeft = inorderStart;
        int inorderEndLeft = rootIndex - 1;
        int inorderStartRight = rootIndex + 1;
        int inorderEndRight = inorderEnd;
        
        root->left = buildTreeHelper(preorder, inorder, startLeft, endLeft, inorderStartLeft, inorderEndLeft);
        root->right = buildTreeHelper(preorder, inorder, startRight, endRight, inorderStartRight, inorderEndRight);
        
        return root;
    }    
    
};