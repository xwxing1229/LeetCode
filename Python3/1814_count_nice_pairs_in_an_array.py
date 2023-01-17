# https://leetcode.cn/problems/count-nice-pairs-in-an-array/

class Solution:
    def countNicePairs(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """
        cnt = defaultdict(int)
        res = 0
        for num in nums:
            diff = num - self.rev(num)
            res += cnt[diff]
            cnt[diff] += 1
        return res % 1000000007
    
    def rev(self, num):
        res = 0
        while num:
            res = res * 10 + num % 10
            num //= 10
        return res
