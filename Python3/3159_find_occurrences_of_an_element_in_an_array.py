# https://leetcode.cn/problems/find-occurrences-of-an-element-in-an-array/

class Solution:
    def occurrencesOfElement(self, nums, queries, x):
        """
        Inputs:
            nums, queries: list[int]
            x: int
        Outputs:
            res: list[int]
        """
        records = dict()
        cnt = 0
        for i, num in enumerate(nums):
            if num == x:
                cnt += 1
                records[cnt] = i
        
        res = [-1 for _ in range(len(queries))]
        for i, q in enumerate(queries):
            if q <= cnt:
                res[i] = records[q]
        return res