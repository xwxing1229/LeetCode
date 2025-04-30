# https://leetcode.cn/problems/count-complete-subarrays-in-an-array/

from collections import defaultdict

class Solution:
    def countCompleteSubarrays(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """
        n = len(set(nums))
        cnt = defaultdict(int)
        res, left = 0, 0
        for num in nums:
            cnt[num] += 1
            while len(cnt) == n:
                out = nums[left]
                cnt[out] -= 1
                if cnt[out] == 0:
                    del cnt[out]
                left += 1
            res += left
        return res