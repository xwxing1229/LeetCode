# https://leetcode.cn/problems/count-the-number-of-beautiful-subarrays/

class Solution:
    def beautifulSubarrays(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """
        res = 0
        cumxor = 0
        cnts = {0: 1}
        for num in nums:
            cumxor ^= num
            cnt = cnts.get(cumxor, 0)
            res += cnt
            cnts[cumxor] = cnt + 1
        return res
