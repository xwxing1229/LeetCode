# https://leetcode.cn/problems/maximum-number-of-balloons/

class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        ord_a = ord("a")
        count = [0 for _ in range(26)]
        for ch in text:
            count[ord(ch) - ord_a] += 1
        
        res = min(count[0], count[1], count[ord("n")-ord_a])
        res = min(res, min(count[ord("l")-ord_a], count[ord("o")-ord_a]) // 2)
        return res