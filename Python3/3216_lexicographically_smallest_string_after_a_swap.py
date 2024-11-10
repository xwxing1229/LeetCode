# https://leetcode.cn/problems/lexicographically-smallest-string-after-a-swap/

class Solution:
    def getSmallestString(self, s: str) -> str:
        res = [ch for ch in s]
        for i in range(len(res)-1):
            num1, num2 = int(res[i]), int(res[i+1])
            if num1 % 2 == num2 % 2 and num1 > num2:
                tmp = res[i]
                res[i] = res[i+1]
                res[i+1] = tmp
                break
        return "".join(res)