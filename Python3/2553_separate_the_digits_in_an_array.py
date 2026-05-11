# https://leetcode.cn/problems/separate-the-digits-in-an-array/

class Solution:
    def separateDigits(self, nums: list[int]) -> list[int]:
        res = [0 for _ in range(len(nums) * 6)]
        idx = 0
        for num in nums:
            s = str(num)
            for ch in s:
                res[idx] = int(ch)
                idx += 1
        return res[:idx]