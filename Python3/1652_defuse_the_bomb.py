# https://leetcode.cn/problems/defuse-the-bomb/

class Solution:
    def decrypt(self, code, k):
        """
        Inputs:
            code: list[int]
            k: int
        Outputs:
            res: list[int]
        """
        n = len(code)
        res = [0 for _ in range(n)]
        if k == 0:
            return res
        
        left, right = 1, k
        if k < 0:
            left, right = n+k, n-1
        res[0] = sum(code[left:right+1])
        for i in range(1, n):
            right = (right + 1) % n
            res[i] = res[i-1] + code[right] - code[left]
            left = (left + 1) % n
        return res