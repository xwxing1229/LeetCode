# https://leetcode.cn/problems/magnetic-force-between-two-balls/

class Solution:
    def maxDistance(self, position, m) -> int:
        """
        Inputs:
            position: list[int]
            m: int
        Outputs:
            res: int
        """
        
        def valid(x):
            cnt = 0
            pre = position[0] - x
            for pos in position:
                if pos - pre >= x:
                    cnt += 1
                    pre = pos
            return cnt >= m

        res = 1
        position.sort()
        left, right = 1, (position[-1]-position[0])//(m-1)
        while left <= right:
            mid = left + (right - left) // 2
            if valid(mid):
                res = max(res, mid)
                left = mid + 1
            else:
                right = mid - 1
        return res