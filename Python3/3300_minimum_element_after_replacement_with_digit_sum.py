# https://leetcode.cn/problems/minimum-element-after-replacement-with-digit-sum/

class Solution:
    def minElement(self, nums: list[int]) -> int:
        def DigitSum(num: int) -> int:
            res = 0
            while num > 0:
                res += num % 10
                num //= 10
            return res
        
        res = DigitSum(nums[0])
        for num in nums:
            res = min(res, DigitSum(num))
        return res