/*

Idea:
- Compute mirror image of left subtree of root
- Compare mirror image with right subtree of root
- If identical, it's symmetric

*/

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;

        return sameTree(mirror(root->left), root->right);
    }

    TreeNode * mirror(TreeNode* root) {
        if (root == NULL) return NULL;

        TreeNode* mirroredLeft = mirror(root->left);
        TreeNode* mirroredRight = mirror(root->right);
        
        root->left = mirroredRight;
        root->right = mirroredLeft;
        return root;
    }

    bool sameTree(TreeNode* rootA, TreeNode* rootB) {
        if (rootA == NULL && rootB == NULL) return true;
        if (rootA == NULL || rootB == NULL) return false;
        if (rootA->val != rootB->val) return false;

        return sameTree(rootA->left, rootB->left) && sameTree(rootA->right, rootB->right);
    }
};