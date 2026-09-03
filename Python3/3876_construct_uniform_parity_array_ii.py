# https://leetcode.cn/problems/construct-uniform-parity-array-ii/

class Solution:
    def uniformArray(self, nums1: list[int]) -> bool:
        odd_min = -1
        for num in nums1:
            if num % 2 == 1 and (odd_min < 0 or odd_min > num):
                odd_min = num
        if odd_min < 0:
            return True
        for num in nums1:
            if num % 2 == 0 and num - odd_min < 1:
                return False
        return True