# https://leetcode-cn.com/problems/heaters/

class Solution:
    def findRadius(self, houses, heaters):
        """
        Inputs:
            houses: list[int]
            heaters: list[int]
        Outputs:
            res: int
        """
        
        # Binary search.
        houses.sort()
        heaters.sort()
        n = len(heaters)
        res = 0
        
        for i in houses:
            l = 0
            r = n - 1
            while l <= r:
                m = (l+r) // 2
                if i < heaters[m]:
                    r = m - 1
                else:
                    l = m + 1
                    
            if r == -1:
                res = max(res, abs(heaters[0]-i))
            elif l == n:
                res = max(res, abs(heaters[n-1]-i))
            else:
                res = max(res, min(heaters[l]-i, i-heaters[r]))
                
        return res