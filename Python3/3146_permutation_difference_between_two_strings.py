# https://leetcode.cn/problems/permutation-difference-between-two-strings/

class Solution:
    def findPermutationDifference(self, s: str, t: str) -> int:
        idxs = dict()
        for i, ch in enumerate(s):
            idxs[ch] = i
        res = 0
        for i, ch in enumerate(t):
            res += abs(i - idxs[ch])
        return res