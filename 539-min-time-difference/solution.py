"""

For two time points, what's the min difference?
    min(t2 - t1, t1 - 2)
    
23:59, 00:00
    - difference is 23:59 or 24:00 - 23:59 = 00:01

01:00, 13:00
    - difference is 12 h either way

Would sorting help?
    - would then only need to compare adjacent time points (as well as time points at beg and end with each other)
    
Algorithm:
    - Sort the time points

"""
class Solution:
    def timePointMins(self, timePoint: str) -> int:
        hour = int(timePoint[:2])
        mins  = int(timePoint[-2:])
        return hour*60 + mins
        
        
    # Assume timePointB >= timePointA
    def getMinutesDiff(self, timePointA: str, timePointB: str) -> int:
        hourA = int(timePointA[:2])
        minA  = int(timePointA[-2:])
        
        hourB = int(timePointB[:2])
        minB = int(timePointB[-2:])
        
        timeInMinsA = hourA * 60 + minA
        timeInMinsB = hourB * 60 + minB
        
        return timeInMinsB - timeInMinsA
        
    
    def findMinDifference(self, timePoints: List[str]) -> int:
        minDifference = 23*60 + 59
        timePoints.sort(key=self.timePointMins)
        
        for i in range(len(timePoints) - 1):
            minDifference = min(minDifference, self.getMinutesDiff(timePoints[i], timePoints[i+1]))
        
        # Compare end with beginning.
        # add 24h to beginning for comparison
        begTimePoint = timePoints[0]
        hourBeg = int(begTimePoint[:2])
        hourBeg += 24
        begTimePoint = "".join([str(hourBeg), begTimePoint[-3:]])
        minDifference = min(minDifference, self.getMinutesDiff(timePoints[-1], begTimePoint))
        
        return minDifference
            