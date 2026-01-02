# https://leetcode.cn/problems/n-repeated-element-in-size-2n-array/

class Solution:
    def repeatedNTimes(self, nums: list[int]) -> int:
        s = set()
        for num in nums:
            if num in s:
                return num
            s.add(num)
        return -1