# https://leetcode.cn/problems/friends-of-appropriate-ages/

class Solution:
    def numFriendRequests(self, ages):
        """
        Inputs:
            ages: list[int]
        Outputs:
            res: int
        """
        res = 0
        ages.sort()
        n = len(ages)
        for i, x in enumerate(ages):
            if x < 15:
                continue
            
            left, right, idx_min = 0, i-1, i
            valid_min = 0.5 * x + 7
            while left <= right:
                mid = left + (right - left) // 2
                if ages[mid] <= valid_min:
                    left = mid + 1
                else:
                    right = mid - 1
                    idx_min = mid
            
            left, right, idx_max = i+1, n-1, i
            while left <= right:
                mid = left + (right - left) // 2
                if ages[mid] <= x:
                    left = mid + 1
                    idx_max = mid
                else:
                    right = mid - 1
                    
            res += idx_max - idx_min
        return res