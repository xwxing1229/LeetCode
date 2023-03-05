# https://leetcode.cn/problems/license-key-formatting/

class Solution:
    def licenseKeyFormatting(self, s: str, k: int) -> str:
        """
        Inputs:
            s: str
            k: int
        Outputs:
            res: str
        """
        res = ""
        cnt = 0
        for i in range(len(s)-1, -1, -1):
            ch = s[i]
            if ch == "-":
                continue
            
            res += ch.upper()
            cnt += 1
            if cnt == k:
                res += "-"
                cnt = 0
        if len(res) and res[-1] == "-":
            res = res[:-1]
        return res[::-1]