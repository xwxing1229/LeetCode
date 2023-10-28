# https://leetcode.cn/problems/take-gifts-from-the-richest-pile/

class Solution:
    def pickGifts(self, gifts, k):
        """
        Inputs:
            gifts: list[int]
            k: int
        Outputs:
            res: int
        """
        gifts_heap = []
        for gift in gifts:
            heapq.heappush(gifts_heap, -gift)
        for _ in range(k):
            gift = heapq.heappop(gifts_heap)
            heapq.heappush(gifts_heap, -int(sqrt(-gift)))
        return -sum(gifts_heap)