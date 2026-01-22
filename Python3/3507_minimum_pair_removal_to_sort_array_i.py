# https://leetcode.cn/problems/minimum-pair-removal-to-sort-array-i/

class Solution:
    def minimumPairRemoval(self, nums: list[int]) -> int:
        res = 0
        valid = False
        while not valid:
            n = len(nums)
            if n <= 1:
                break
            s_min, idx = nums[0] + nums[1], 0
            valid = True
            for i in range(len(nums)-1):
                if nums[i] > nums[i+1]:
                    valid = False
                if s_min > nums[i] + nums[i+1]:
                    s_min = nums[i] + nums[i+1]
                    idx = i
            if not valid:
                nums[idx] = s_min
                nums.pop(idx+1)
                res += 1
        return res