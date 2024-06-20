# https://leetcode.cn/problems/number-of-beautiful-pairs/

class Solution:
    def countBeautifulPairs(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """
        res = 0
        n = len(nums)
        last_digits = [num % 10 for num in nums]
        for i in range(n):
            digiti = self.getFirstDigit(nums[i])
            for j in range(i+1, n):
                if gcd(digiti, last_digits[j]) == 1:
                    res += 1
        return res
    
    def getFirstDigit(self, num):
        digit = 0
        while num > 0:
            digit = num % 10
            num //= 10
        return digit