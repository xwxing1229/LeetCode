# https://leetcode.cn/problems/evaluate-division/

class Solution:
    def calcEquation(self, equations, values, queries):
        """
        Inputs:
            equations: list[list[str]]
            values: list[float]
            queries: list[list[str]]
        Outputs:
            equations: list[float]
        """
        self.table = dict()
        for i in range(len(equations)):
            num, den = equations[i]

            if num in self.table:
                self.table[num].append([den, values[i]])
            else:
                self.table[num] = [[den, values[i]]]
            if den in self.table:
                self.table[den].append([num, 1./values[i]])
            else:
                self.table[den] = [[num, 1./values[i]]]

        n = len(queries)
        res = [0. for _ in range(n)]
        for i in range(n):
            num, den = queries[i]
            res[i] = self.calcOneEq(num, den, 1, [])
        return res

    def calcOneEq(self, num, den, pre_quo, check):
        if num not in self.table or den not in self.table:
            return -1.
        elif num == den:
            return 1.

        res = -1.
        record = self.table[num]
        for tmp_den, tmp_quo in record:
            if tmp_den in check:
                continue
            elif tmp_den == den:
                return tmp_quo * pre_quo
            else:
                check.append(num)
                res = self.calcOneEq(tmp_den, den, tmp_quo*pre_quo, check)
                if res > 0:
                    return res
        return res