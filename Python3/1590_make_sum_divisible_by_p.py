# https://leetcode.cn/problems/make-sum-divisible-by-p/

class Solution:
    def minSubarray(self, nums, p):
        """
        Inputs:
            nums: list[int]
            p: int
        Outputs:
            res: int
        """
        target = 0
        for num in nums:
            target = (target + num) % p
        if target == 0:
            return 0

        # Given
        #     sum_cur % p = s,
        # we would like to find a sum_pre that
        #     (sum_cur - sum_pre) % p = target.
        s, res = 0, len(nums)
        record = {0: -1}
        for i, num in enumerate(nums):
            s = (s + num) % p
            record[s] = i
            target_subarr = (s - target + p) % p
            if target_subarr in record:
                res = min(res, i - record[target_subarr])
        if res == len(nums):
            res = -1
        return res