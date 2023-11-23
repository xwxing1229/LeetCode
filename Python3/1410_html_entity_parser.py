# https://leetcode.cn/problems/html-entity-parser/

class Solution:
    def entityParser(self, text):
        """
        Inputs:
            text: str
        Outputs:
            res: str
        """
        table = {"&quot;": "\"",
                 "&apos;": "\'",
                 "&amp;": "&",
                 "&gt;": ">",
                 "&lt;": "<",
                 "&frasl;": "/"}
        res = ""
        n = len(text)
        start, i = 0, 0
        added = True
        while i < n:
            while i < n and text[i] != "&":
                i += 1
            res += text[start: i]
            start = i
            i += 1
            added = False
            while i < n and i - start <= 7:
                if text[i] == "&":
                    res += text[start: i]
                    start = i
                    added = True
                    break
                tmp = text[start: i+1]
                if tmp in table:
                    res += table[tmp]
                    start = i + 1
                    added = True
                    break
                i += 1
        if not added and start < n:
            res += text[start: n]
        return res