# https://leetcode.cn/problems/maximum-number-of-pairs-in-array/

class Solution:
    def numberOfPairs(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: list[int]
        """
        cnt = defaultdict(int)
        res = [0, 0]
        for i in nums:
            cnt[i] = 1 - cnt[i]
            if cnt[i] == 0:
                res[0] += 1
        res[1] = len(nums) - 2 * res[0]
        return res