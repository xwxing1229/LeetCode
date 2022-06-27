# https://leetcode.cn/problems/longest-consecutive-sequence/

class Solution:
    def longestConsecutive(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """

        res = 0
        hash_dict = {}
        for num in nums:
            if num not in hash_dict:
                left = hash_dict.get(num-1, 0)
                right = hash_dict.get(num+1, 0)
                length = left + 1 + right

                hash_dict[num] = length
                hash_dict[num-left] = length
                hash_dict[num+right] = length

                res = max(res, length)

        return length