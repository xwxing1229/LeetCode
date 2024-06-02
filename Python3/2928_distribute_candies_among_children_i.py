# https://leetcode.cn/problems/distribute-candies-among-children-i/

class Solution:
    def distributeCandies(self, n: int, limit: int) -> int:        
        res = 0
        for i in range(limit+1):
            for j in range(limit+1):
                k = n - i - j
                if k >= 0 and k <= limit:
                    res += 1
                elif k < 0:
                    break
        return res