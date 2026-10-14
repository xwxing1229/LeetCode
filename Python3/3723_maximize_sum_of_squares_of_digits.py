# https://leetcode.cn/problems/maximize-sum-of-squares-of-digits/

class Solution:
    def maxSumOfSquares(self, num: int, sum: int) -> str:
        res = ""
        if num * 9 < sum:
            return res
        for i in range(9, 0, -1):
            cnt = sum // i
            if cnt <= num:
                res += str(i) * cnt
                num -= cnt
                sum -= i * cnt
                if sum == 0:
                    break
        res += "0" * num
        return res