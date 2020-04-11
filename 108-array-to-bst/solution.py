"""
Idea:
- Pick middle array element as root
- Recursively convert left and right halves of array into BSTs; do this to ensure height balance
"""

class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
        size = len(nums)
        mid = (size - 1) // 2
        
        if mid < 0:
            return None
        
        root = TreeNode(nums[mid])
        
        root.left = self.sortedArrayToBST(nums[:mid])
        root.right = self.sortedArrayToBST(nums[mid + 1 :])
        return root
