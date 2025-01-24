# https://leetcode.cn/problems/number-of-visible-people-in-a-queue/

class Solution:
    def canSeePersonsCount(self, heights):
        """
        Inputs:
            heights: list[int]
        Outputs:
            res: list[int]
        """
        n = len(heights)
        res = [0 for _ in range(n)]
        st = []
        for i in range(n-1, -1, -1):
            height = heights[i]
            while st and st[-1] < height:
                res[i] += 1
                st.pop()
            if st:
                res[i] += 1
            st.append(height)
        return res