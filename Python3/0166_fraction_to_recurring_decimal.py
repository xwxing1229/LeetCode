# https://leetcode.cn/problems/fraction-to-recurring-decimal/

class Solution:
    def fractionToDecimal(self, numerator, denominator):
        """
        Inputs:
            numerator: int
            denominator: int
        Outputs:
            res: str
        """

        res = ""
        if (numerator > 0) and (denominator < 0):
            res = "-"
            denominator = -denominator
        elif (numerator < 0) and (denominator > 0):
            res = "-"
            numerator = -numerator

        quo = numerator // denominator
        rem = numerator - denominator * quo
        res = res + str(quo)
        if rem == 0:
            return res

        res = res + "."
        start_idx = len(res)
        record = dict()
        idx = 0
        while True:
            tmp = rem * 10
            quo = tmp // denominator
            rem = tmp - denominator * quo

            if rem == 0:
                res = res + str(quo)
                return res

            if tmp not in record:
                res = res + str(quo)
                record[tmp] = idx
                idx = idx + 1
            else:
                break
        res = res[: start_idx+record[tmp]] + "(" + res[start_idx+record[tmp]:] + ")"
        return res
