# https://leetcode.cn/problems/convert-date-to-binary/

class Solution:
    def convertDateToBinary(self, date: str) -> str:
        def to_binary(s):
            res = ""
            num = int(s)
            while num:
                res += str(num & 1)
                num >>= 1
            res = res[::-1]
            return res

        res = []
        ymd = date.split("-")
        for s in ymd:
            res.append(to_binary(s))
        return "-".join(res)