# https://leetcode.cn/problems/total-waviness-of-numbers-in-range-i/

class Solution:
    def totalWaviness(self, num1: int, num2: int) -> int:
        res = 0
        for num in range(num1, num2+1):
            s = str(num)
            for i in range(1, len(s)-1):
                if (s[i] > s[i-1] and s[i] > s[i+1]) or \
                    (s[i] < s[i-1] and s[i] < s[i+1]):
                    res += 1
        return res