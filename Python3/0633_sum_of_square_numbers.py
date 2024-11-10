# https://leetcode.cn/problems/sum-of-square-numbers/

class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        a, b = 0, int(sqrt(c))
        while a <= b:
            a_sq, b_sq = a*a, b*b
            sq_sum = a_sq + b_sq
            if sq_sum == c:
                return True
            elif sq_sum < c:
                a = max(a+1, int(sqrt(c-b_sq)))
            else:
                b = min(b-1, int(sqrt(c-a_sq)))
        return False