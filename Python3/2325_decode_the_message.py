# https://leetcode.cn/problems/decode-the-message/

class Solution:
    def decodeMessage(self, key, message):
        """
        Inputs:
            key, message: str
        Outputs:
            res: str
        """
        table = ["" for _ in range(26)]
        idx, ord_a = ord("a"), ord("a")
        for ch in key:
            if ch != " " and table[ord(ch) - ord_a] == "":
                table[ord(ch) - ord_a] = chr(idx)
                idx += 1

        res = ""
        for ch in message:
            if ch == " ":
                res += ch
            else:
                res += table[ord(ch) - ord_a]
        return res