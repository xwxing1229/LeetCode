# https://leetcode.cn/problems/most-frequent-even-element/

class Solution:
    def mostFrequentEven(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """
        cnt = defaultdict(int)
        for num in nums:
            if num % 2 == 0:
                cnt[num] += 1
        
        res = -1
        appear = 0
        for num in cnt:
            if res < 0 or appear < cnt[num] or (appear == cnt[num] and res > num):
                res = num
                appear = cnt[num]
        return res