# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        
#         Given two heads, l1 and l2, merge them
        
#         If l1 is None, then just use l2, and vice versa
        if (not l1 and not l2):
            return None

        if (l1 and not l2):
            return l1
        
        if (l2 and not l1):
            return l2
        
        if (l1 and l2):
            if (l1.val <= l2.val):
                head_node = ListNode(l1.val)
                head_node.next = self.mergeTwoLists(l1.next, l2)
            else:
                head_node = ListNode(l2.val)
                head_node.next = self.mergeTwoLists(l1, l2.next)
            
            return head_node
