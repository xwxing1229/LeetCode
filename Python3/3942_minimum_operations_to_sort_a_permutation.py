# https://leetcode.cn/problems/minimum-operations-to-sort-a-permutation/

class Solution:
    def minOperations(self, nums: list[int]) -> int:
        n = len(nums)
        if n == 1:
            return 0

        diff = nums[1] - nums[0]
        if abs(diff) != 1:
            diff = nums[2] - nums[1]
            if abs(diff) != 1:
                return -1

        pos = 0
        for i in range(1, n):
            if nums[i] - nums[i-1] != diff:
                if pos > 0:
                    return -1
                pos = i
        if diff == 1:
            return min(pos, n-pos+2)
        return min(pos+1, n-pos+1)