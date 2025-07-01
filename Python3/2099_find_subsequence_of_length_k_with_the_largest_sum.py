# https://leetcode.cn/problems/find-subsequence-of-length-k-with-the-largest-sum/

class Solution:
    def maxSubsequence(self, nums, k):
        """
        Inputs:
            nums: list[int]
            k: int
        Outputs:
            res: list[int]
        """
        n = len(nums)
        idxs = [i for i in range(n)]
        idxs.sort(key=lambda x: -nums[x])
        idxs = idxs[:k]
        idxs.sort()
        res = [nums[i] for i in idxs]
        return res