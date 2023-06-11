# https://leetcode.cn/problems/mice-and-cheese/

class Solution:
    def miceAndCheese(self, reward1, reward2, k):
        """
        Inputs:
            reward1, reward2: list[int]
            k: int
        Outputs:
            res: int
        """
        n = len(reward1)
        diff = [(reward1[i] - reward2[i], i) for i in range(n)]
        diff.sort(reverse=True)
        res = 0
        for i in range(k):
            res += reward1[diff[i][1]]
        for i in range(k, n):
            res += reward2[diff[i][1]]
        return res