# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

"""
Sum of all left leaves.

Idea:

Have a helper function: 
    root, isLeft
    
    if root is NULL
        return 0
    
    if root is leaf
        if isLeft
            return val
        
        return 0
    
    return helper(left) + helper(right)
    

"""

class Solution:
    def sumOfLeftLeaves(self, root: TreeNode) -> int:
        return self.sumOfLeftLeavesHelper(root, False)
    
    def sumOfLeftLeavesHelper(self, root: TreeNode, isLeft: bool) -> int:
        if root is None:
            return 0
        
        if root.left is None and root.right is None:
            if isLeft:
                return root.val
            
            return 0
        
        return self.sumOfLeftLeavesHelper(root.left, True) + self.sumOfLeftLeavesHelper(root.right, False)
    
    