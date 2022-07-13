# https://leetcode.cn/problems/contains-duplicate-ii/

class Solution:
    def containsNearbyDuplicate(self, nums, k):
        """
        Inputs:
            nums: list[int]
            k: int
        Outputs:
            res: bool
        """

        hash_set = set()
        for i, num in enumerate(nums):
            if i > k:
                hash_set.remove(nums[i-k-1])
            if num in hash_set:
                return True
            hash_set.add(num)

        return False