# https://leetcode.cn/problems/find-kth-bit-in-nth-binary-string/

class Solution:
    def findKthBit(self, n: int, k: int) -> str:
        if n == 1:
            return "0"
        
        mid = 2 ** (n-1)
        if k == mid:
            return "1"
        elif k < mid:
            return self.findKthBit(n-1, k)
        else:
            invert = self.findKthBit(n-1, 2*mid-k)
            return str(1 - int(invert))