# https://leetcode.cn/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/

class Solution:
    def numSteps(self, s: str) -> int:
        res = 0
        carry = 0
        for i in range(len(s)-1, 0, -1):
            val = int(s[i]) + carry
            # even: +1 (/2), odd: +2 (+1 then /2)
            res += (val & 1) + 1
            carry = val > 0
        return res + carry