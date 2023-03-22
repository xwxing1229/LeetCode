# https://leetcode.cn/problems/reformat-phone-number/

class Solution:
    def reformatNumber(self, number: str) -> str:
        """
        Inputs:
            number: str
        Outputs:
            res: str
        """
        number = "".join(number.split("-"))
        number = "".join(number.split(" "))
        res = ""
        n = len(number)
        for i in range(0, n, 3):
            if n - i == 4:
                res = res + number[i: i+2] + "-" + number[i+2: i+4]
                break
            elif n - i == 2:
                res = res + number[i: i+2];
                break
            else:
                res = res + number[i: i+3]
                if n - i > 4:
                    res = res + "-"
        return res