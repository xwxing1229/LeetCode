# https://leetcode.cn/problems/k-th-smallest-prime-fraction/

class Solution:
    def kthSmallestPrimeFraction(self, arr, k):
        """
        Inputs:
            arr: list[int]
            k: int
        Outputs:
            res: list[int]
        """
        
        n = len(arr)
        pq = [] # priority queue
        for i in range(n-1):
            heapq.heappush(pq, [arr[i] / arr[n-1], i, n-1])

        for _ in range(k):
            frac, i, j = heapq.heappop(pq)

            if j-1 > i:
                heapq.heappush(pq, [arr[i] / arr[j-1], i, j-1])

        res = [arr[i], arr[j]]
        return res