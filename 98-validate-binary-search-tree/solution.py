# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

"""
Key point: ALL nodes in a subtree are strictly less than or greater than the node's key.

Idea: create a helper, recurse while providing a max/min

"""

class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        import sys
        global_max = sys.maxsize
        global_min = -sys.maxsize - 1
        return self.isValidBSTHelper(root, global_max, global_min)
        
    
    def isValidBSTHelper(self, root: TreeNode, global_max: int, global_min: int):
        """
        Base Case: Leaf node (or None)
        """
        if root is None or (root.left is None and root.right is None):
            return True
        
        if root.left and (root.left.val >= root.val or root.left.val <= global_min):
            return False
        
        if root.right and (root.right.val <= root.val or root.right.val >= global_max):
            return False
        
        isLeftSubtreeValid = self.isValidBSTHelper(root.left,root.val,global_min)
        isRightSubtreeValid = self.isValidBSTHelper(root.right,global_max,root.val)
        
        return isLeftSubtreeValid and isRightSubtreeValid
