# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        if not root:
            return []
        
        leftSubtreeTraversal = self.inorderTraversal(root.left)
        leftSubtreeTraversal.append(root.val)
        
        rightSubtreeTraversal = self.inorderTraversal(root.right)
        
        leftSubtreeTraversal.extend(rightSubtreeTraversal)
        
        return leftSubtreeTraversal