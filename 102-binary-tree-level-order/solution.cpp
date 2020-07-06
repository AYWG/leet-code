/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> answer;
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));
        
        while (!q.empty()) {
            pair<TreeNode*, int> p = q.front();
            q.pop();
            
            TreeNode *r = p.first;
            int level = p.second;
        
            if (r != NULL) {
                if (level == answer.size()) {
                    // Add new level
                    vector<int> level(1, r->val);
                    answer.push_back(level);
                } else {
                    answer[level].push_back(r->val);
                }
                
                q.push(make_pair(r->left, level + 1));
                q.push(make_pair(r->right, level + 1));
            }     
        }
        
        
        return answer;
    }
};