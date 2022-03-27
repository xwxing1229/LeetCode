# https://leetcode-cn.com/problems/kth-smallest-element-in-a-sorted-matrix/

class Solution:
    def kthSmallest(self, matrix, k):
        """
        Inputs:
            matrix: list[list[int]]
            k: int
        Outputs:
            res: int
        """

        n = len(matrix)
        nums = [(matrix[i][0], i, 0) for i in range(n)]
        # Convert nums to a heap.
        heapq.heapify(nums)
        for i in range(k-1):
            num, r, c = heapq.heappop(nums)
            if c < n-1:
                heapq.heappush(nums, (matrix[r][c+1], r, c+1))

        res, r, c = heapq.heappop(nums)
        return res