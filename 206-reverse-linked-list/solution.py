# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        # Recursive
        return self.reverseListHelper(head, None)
        
    def reverseListHelper(self, head, currReversedList):
        if head is None:
            return None
        
        newHeadOfReversed = ListNode(head.val)
        newHeadOfReversed.next = currReversedList
        # Last node        
        if head.next == None:
            return newHeadOfReversed
        
        return self.reverseListHelper(head.next, newHeadOfReversed)
         