# https://leetcode.cn/problems/shortest-subarray-with-sum-at-least-k/

class Solution:
    def shortestSubarray(self, nums, k):
        """
        Inputs:
            nums: list[int]
            k: int
        Outputs:
            res: int
        """

        preSumArr = [0]
        res = len(nums) + 1
        for num in nums:
            preSumArr.append(preSumArr[-1] + num)

        q = deque()
        for i, curSum in enumerate(preSumArr):
            while q and curSum - preSumArr[q[0]] >= k:
                res = min(res, i - q.popleft())

            while q and preSumArr[q[-1]] >= curSum:
                q.pop()
                
            q.append(i)
        
        if res >= len(nums) + 1:
            return -1
        return res