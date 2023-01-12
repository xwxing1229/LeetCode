# https://leetcode.cn/problems/evaluate-the-bracket-pairs-of-a-string/

class Solution:
    def evaluate(self, s, knowledge):
        """
        Inputs:
            s: str
            knowledge: list[list[str]]
        Outputs:
            res: str
        """
        table = dict()
        for k, v in knowledge:
            table[k] = v

        res, key = "", ""
        for ch in s:
            if ch == ")":
                if key[1:] in table:
                    res += table[key[1:]]
                else:
                    res += "?"
                key = ""
            elif ch == "(" or key != "":
                key += ch
            else:
                res += ch
        return res
