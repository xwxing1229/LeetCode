# https://leetcode.cn/problems/find-missing-elements/

class Solution:
    def findMissingElements(self, nums: list[int]) -> list[int]:
        nums.sort()
        mn, mx = nums[0], nums[-1]
        n = mx - mn + 1 - len(nums)
        res = []
        if n == 0:
            return res
        i = 0
        for num in range(mn, mx+1):
            if num == nums[i]:
                i += 1
            else:
                res.append(num)
        return res