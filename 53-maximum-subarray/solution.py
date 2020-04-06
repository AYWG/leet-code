class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        maxSoFar = -99999999999
        currentMaxSum = 0

        for num in nums:
            newSum = currentMaxSum + num
            if newSum > maxSoFar:
                maxSoFar = newSum

            if newSum < 0:
                currentMaxSum = 0

        return maxSoFar





        # subArrayDict = {}
        # maxSum = nums[0]
        # numsLen = len(nums)
        
        # for index, num in enumerate(nums):
        #     subArray = (num,)
        #     key = (subArray, index + 1)
        #     subArrayDict[key] = num
            
        #     if num > maxSum:
        #         maxSum = num
                
        # biggestSubArrayLen = 1
                
        # while biggestSubArrayLen < numsLen:
        #     # Filter subArrayDict for all keys whose sub array len == biggestSubArrayLen
            
        #     keys = set(subArrayDict.keys())
        #     for key in keys:
        #         subArray = key[0]
        #         nextIndex = key[1]
                
        #         if len(subArray) == biggestSubArrayLen and nextIndex < numsLen:
        #             newSubArray = subArray + (nums[nextIndex],)
        #             newSum = subArrayDict[key] + nums[nextIndex]
        #             newNextIndex = nextIndex + 1

        #             newKey = (newSubArray, newNextIndex)
        #             subArrayDict[newKey] = newSum

        #             if newSum > maxSum:
        #                 maxSum = newSum
            
        #     biggestSubArrayLen += 1
                
                
        # return maxSum
            
        