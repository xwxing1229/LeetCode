# https://leetcode.cn/problems/check-if-number-has-equal-digit-count-and-digit-value/

class Solution:
    def digitCount(self, num):
        """
        Inputs:
            num: str
        Outputs:
            res: bool
        """
        cnt = [0 for i in range(10)]
        for ch in num:
            cnt[ord(ch) - ord("0")] += 1
        for i, ch in enumerate(num):
            if int(ch) != cnt[i]:
                return False
        return True
