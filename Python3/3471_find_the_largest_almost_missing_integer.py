# https://leetcode.cn/problems/find-the-largest-almost-missing-integer/

from collections import Counter

class Solution:
    def largestInteger(self, nums: list[int], k: int) -> int:
        res = -1
        count = Counter(nums)
        if k == 1:
            for num, cnt in count.items():
                if cnt == 1 and res < num:
                    res = num
            return res
        elif k == len(nums):
            return max(nums)

        left, right = nums[0], nums[-1]
        if count[left] == 1 and count[right] == 1:
            return max(left, right)
        elif count[left] == 1:
            return left
        elif count[right] == 1:
            return right
        return -1