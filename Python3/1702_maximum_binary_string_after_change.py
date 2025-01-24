# https://leetcode.cn/problems/maximum-binary-string-after-change/

class Solution:
    def maximumBinaryString(self, binary: str) -> str:
        res = ["1" for _ in range(len(binary))]
        idx = -1
        for i, ch in enumerate(binary):
            if ch == "0":
                if idx < 0:
                    idx = i
                else:
                    idx += 1
        if idx >= 0:
            res[idx] = "0"
        return "".join(res)
