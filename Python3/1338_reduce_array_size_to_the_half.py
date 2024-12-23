# https://leetcode.cn/problems/reduce-array-size-to-the-half/

class Solution:
    def minSetSize(self, arr):
        """
        Inputs:
            arr: list[int]
        Outputs:
            res: int
        """
        cnts = defaultdict(int)
        for val in arr:
            cnts[val] += 1
        pq = []
        for val, cnt in cnts.items():
            pq.append(-cnt)
        heapq.heapify(pq)

        res = 0
        half, cnt = (len(arr)+1)//2, 0
        while cnt < half:
            cnt -= heapq.heappop(pq)
            res += 1
        return res