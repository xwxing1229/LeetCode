# https://leetcode.cn/problems/coupon-code-validator/

class Solution:
    def validateCoupons(self, code: list[str], businessLine: list[str], isActive: list[bool]) -> list[str]:
        business_type = {
            "electronics": 0,
            "grocery": 1,
            "pharmacy": 2,
            "restaurant": 3,
        }
        valid = [[] for _ in range(4)]
        for i in range(len(code)):
            if not isActive[i] or businessLine[i] not in business_type:
                continue
            if code[i] and all(ch == "_" or ch.isalnum() for ch in code[i]):
                valid[business_type[businessLine[i]]].append(code[i])
        res = []
        for val in valid:
            val.sort()
            res += val
        return res