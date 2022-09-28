# https://leetcode.cn/problems/find-k-pairs-with-smallest-sums/

class Solution:
    def kSmallestPairs(self, nums1, nums2, k):
        """
        Inputs:
            nums1: list[int]
            nums2: list[int]
            k: int
        Outputs:
            res: list[list[int]]
        """
        m = len(nums1)
        n = len(nums2)
        pq = [] # priority queue
        for i in range(m):
            heapq.heappush(pq, [nums1[i]+nums2[0], i, 0])

        res = []
        while (len(res) < k) and (len(pq) > 0):
            tmp = heapq.heappop(pq)
            res.append([nums1[tmp[1]], nums2[tmp[2]]])

            if tmp[2] + 1 < n:
                heapq.heappush(pq, [nums1[tmp[1]]+nums2[tmp[2]+1], tmp[1], tmp[2]+1])
        return res