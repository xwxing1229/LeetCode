# https://leetcode.cn/problems/beautiful-towers-ii/

class Solution:
    def maximumSumOfHeights(self, maxHeights):
        """
        Inputs:
            maxHeights: list[int]
        Outputs:
            res: int
        """
        n = len(maxHeights)
        # left[i]: maximum index j such that j < i and maxHeights[j] <= maxHeights[i].
        stk = []
        left = [-1 for _ in range(n)]
        for i, h in enumerate(maxHeights):
            while stk and maxHeights[stk[-1]] > h:
                stk.pop()
            if stk:
                left[i] = stk[-1]
            stk.append(i)
        dp_left = [0 for _ in range(n)]
        for i, h in enumerate(maxHeights):
            if i > 0 and h >= maxHeights[i-1]:
                dp_left[i] = dp_left[i-1] + h
            else:
                j = left[i]
                if j > -1:
                    dp_left[i] = dp_left[j] + (i-j) * h
                else:
                    dp_left[i] = (i-j) * h
        
        # right[i]: minimum index j such that j > i and maxHeights[j] <= maxHeights[i].
        stk = []
        right = [n for _ in range(n)]
        for i in range(n-1, -1, -1):
            h = maxHeights[i]
            while stk and maxHeights[stk[-1]] > h:
                stk.pop()
            if stk:
                right[i] = stk[-1]
            stk.append(i)
        dp_right = [0 for _ in range(n)]
        for i in range(n-1, -1, -1):
            h = maxHeights[i]
            if i < n-1 and h >= maxHeights[i+1]:
                dp_right[i] = dp_right[i+1] + h
            else:
                j = right[i]
                if j < n:
                    dp_right[i] = dp_right[j] + (j-i) * h
                else:
                    dp_right[i] = (j-i) * h
        
        res = 0
        for i in range(n):
            res = max(res, dp_left[i]+dp_right[i]-maxHeights[i])
        return res