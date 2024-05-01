# https://leetcode.cn/problems/total-cost-to-hire-k-workers/

class Solution:
    def totalCost(self, costs: List[int], k: int, candidates: int) -> int:
        n = len(costs)
        left, right = 0, n-1
        cands = []
        while left <= right and len(cands) != 2*candidates:
            heapq.heappush(cands, (costs[left], left))
            left += 1
            if left > right:
                break
            heapq.heappush(cands, (costs[right], right))
            right -= 1
        res = 0
        for _ in range(k):
            c, idx = heapq.heappop(cands)
            res += c
            if idx < left and left <= right:
                heapq.heappush(cands, (costs[left], left))
                left += 1
            elif idx > right and left <= right:
                heapq.heappush(cands, (costs[right], right))
                right -= 1
        return res