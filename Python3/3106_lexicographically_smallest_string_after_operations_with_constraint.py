# https://leetcode.cn/problems/lexicographically-smallest-string-after-operations-with-constraint/

class Solution:
    def getSmallestString(self, s: str, k: int) -> str:
        ord_a = ord("a")
        ch2ord = {chr(ord_a+i): i for i in range(26)}
        ord2ch = [chr(ord_a+i) for i in range(26)]
        res = [ch for ch in s]
        for i, ch in enumerate(s):
            pos = ch2ord[ch]
            if pos > 13 and 26-pos <= k:
                res[i] = "a"
                move = 26 - pos
            else:
                move = min(pos, k)
                res[i] = ord2ch[pos-move]
            k -= move
            if k == 0:
                break
        return "".join(res)