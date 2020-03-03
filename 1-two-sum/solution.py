class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """    
        numIndexDict = {}
        
        for i, num in enumerate(nums):
            if num in numIndexDict:
                numIndexDict[num].append(i)
            else:
                numIndexDict[num] = [i]
            
        result = []
        
        for num in nums:
            if (target - num) in numIndexDict:
                # The two numbers are different
                if numIndexDict[target - num] != numIndexDict[num]:
                    result.extend([numIndexDict[num][0], numIndexDict[target - num][0]])
                    break
                    
                # The two numbers are the same
                elif len(numIndexDict[num]) > 1:
                    result.append(numIndexDict[num][0])
                    result.append(numIndexDict[num][1])
                    break
        
        return result
                
        