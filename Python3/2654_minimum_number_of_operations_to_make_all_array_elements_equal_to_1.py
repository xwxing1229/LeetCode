# https://leetcode.cn/problems/minimum-number-of-operations-to-make-all-array-elements-equal-to-1/

class Solution:
    def minOperations(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """
        n = len(nums)
        cnt1 = 0
        g = 0
        for num in nums:
            cnt1 += num == 1
            g = gcd(g, num)
        if cnt1 > 0:
            return n - cnt1
        if g > 1:
            return -1
        
        min_len = n # minimum length of subarray whose gcd is 1
        for i in range(n):
            g = 0
            for j in range(i, n):
                g = gcd(g, nums[j])
                if g == 1:
                    min_len = min(min_len, j-i+1)
                    break
        res = min_len - 1 + n - 1
        return res