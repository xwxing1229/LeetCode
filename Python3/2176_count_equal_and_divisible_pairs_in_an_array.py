# https://leetcode.cn/problems/count-equal-and-divisible-pairs-in-an-array/

from collections import defaultdict

class Solution:
    def countPairs(self, nums, k):
        """
        Inputs:
            nums: list[int]
            k: int
        Outputs:
            res: int
        """
        res = 0
        cnt = defaultdict(list)
        for i, num in enumerate(nums):
            for j in cnt[num]:
                if i * j % k == 0:
                    res += 1
            cnt[num].append(i)
        return res