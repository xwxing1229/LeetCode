# https://leetcode.cn/problems/score-of-parentheses/

class Solution:
    def scoreOfParentheses(self, s):
        """
        Inputs:
            s: str
        Outputs:
            int
        """
        record = []
        idx = -1
        for ch in s:
            if ch == "(":
                record.append(ch)
                idx = idx + 1
            else:
                if record[idx] == "(":
                    record[idx] = 1
                else:
                    tmp = 0
                    while idx >= 0 and record[idx] != "(":
                        tmp = tmp + record.pop()
                        idx = idx - 1
                    if idx >= 0 and record[idx] == "(":
                        record[idx] = tmp * 2
        return sum(record)