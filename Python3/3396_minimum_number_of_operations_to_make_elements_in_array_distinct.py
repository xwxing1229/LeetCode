# https://leetcode.cn/problems/minimum-number-of-operations-to-make-elements-in-array-distinct/

from collections import Counter

class Solution:
    def minimumOperations(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """
        cnt = Counter(nums)
        cnt = Counter({k: v for k, v in cnt.items() if v > 1})
        res, i = 0, 0
        while i + 2 < len(nums):
            if len(cnt) == 0:
                break
            for j in range(i, i+3):
                num = nums[j]
                cnt[num] -= 1
                if cnt[num] <= 1:
                    del cnt[num]
            res += 1
            i += 3
        res += (i < len(nums) and len(cnt) != 0)
        return res