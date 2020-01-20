# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
        if head is None:
            return head
        
        if m > 1:
            partReversedBetween = self.reverseBetween(head.next, m-1, n-1)
            head.next = partReversedBetween
            return head
        
        return self.reverseStartToN(head, n)
        
        
    def reverseStartToN(self, head: ListNode, n: int) -> ListNode:
        return self.reverseStartToNHelper(head, n, None, None, True)    
        
    def reverseStartToNHelper(self, head: ListNode, n: int, currReversedList: ListNode, originalHead: ListNode, isFirstNode: bool) -> ListNode:
        # Base Case
        if n < 1:
            # We've reached the end of where we need to reverse.
            originalHead.next = head
            return currReversedList
    
        newHead = ListNode(head.val)
        newHead.next = currReversedList
        if isFirstNode:
            return self.reverseStartToNHelper(head.next, n-1, newHead, newHead, False)
        
        return self.reverseStartToNHelper(head.next, n-1, newHead, originalHead, False)
            