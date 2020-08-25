"""
How do I make this faster?

In a single pass, there may be multiple duplicate adjacents. Could we tackle all of them at once?
    - Problem: If you have "abbbc", would need to be careful
    
What if you use a stack?

abbaca

push a
push b
compare top with curr: same!
    - pop top

compare top with curr: same!
    - pop top

"""

class Solution:
    def removeDuplicates(self, S: str) -> str:
        stack = []
        
        for c in S:
            if not stack or stack[-1] != c:
                stack.append(c)
            elif stack[-1] == c:
                stack.pop()
                
        return "".join(stack)
        