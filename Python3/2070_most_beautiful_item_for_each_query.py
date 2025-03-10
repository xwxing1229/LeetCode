# https://leetcode.cn/problems/most-beautiful-item-for-each-query/

class Solution:
    def maximumBeauty(self, items, queries):
        """
        Inputs:
            items: list[list[int]]
            queries: list[int]
        Outputs:
            res: list[int]
        """
        res = [0 for _ in range(len(queries))]
        items.sort(key=lambda x: x[0])
        n = len(items)
        beauties = [items[0][1] for _  in range(n)]
        for i in range(1, n):
            beauties[i] = max(beauties[i-1], items[i][1])
        for i, q in enumerate(queries):
            left, right = 0, n-1
            while left <= right:
                mid = left + (right - left) // 2
                if items[mid][0] <= q:
                    res[i] = beauties[mid]
                    left = mid + 1
                else:
                    right = mid - 1
        return res