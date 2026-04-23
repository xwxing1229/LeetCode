# https://leetcode.cn/problems/sum-of-distances/

from collections import defaultdict

class Solution:
    def distance(self, nums: list[int]) -> list[int]:
        cumsum = defaultdict(list)
        helper = defaultdict(int)
        for i, num in enumerate(nums):
            helper[num] += i
            cumsum[num].append(helper[num])

        res = [0 for _ in range(len(nums))]
        for num, cs in cumsum.items():
            n = len(cs)
            idx = cs[0]
            res[idx] = cs[-1] - idx * n
            for i in range(1, n):
                idx = cs[i] - cs[i-1]
                left = idx * i - cs[i-1]
                right = cs[-1] - cs[i] - idx * (n-1-i)
                res[idx] = left + right
        return res