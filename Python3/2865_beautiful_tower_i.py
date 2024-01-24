# https://leetcode.cn/problems/beautiful-towers-i/

class Solution:
    def maximumSumOfHeights(self, maxHeights):
        """
        Inputs:
            maxHeights: list[int]
        Outputs:
            res: int
        """
        n = len(maxHeights)
        res = 0
        for i in range(n):
            cur = maxHeights[i]
            tmp = cur
            # Left.
            for j in range(i-1, -1, -1):
                cur = min(maxHeights[j], cur)
                tmp += cur
            # Right.
            cur = maxHeights[i]
            for j in range(i+1, n):
                cur = min(maxHeights[j], cur)
                tmp += cur
            res = max(res, tmp)
        return res
    
sol = Solution()
maxHeights = [6,5,3,9,2,7] # 22
# maxHeights = [3,2,5,5,2,3] # 18
print(sol.maximumSumOfHeights(maxHeights))