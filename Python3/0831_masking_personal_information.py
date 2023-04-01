# https://leetcode.cn/problems/masking-personal-information/

class Solution:
    def maskPII(self, s):
        """
        Inputs:
            s: str
        Outputs:
            res: str
        """
        res = ""
        if s[0].isalpha():
            res = s[0].lower() + "*****"
            for i, ch in enumerate(s):
                if ch == "@":
                    res += s[i-1:].lower()
                    break
        else:
            nums = ""
            for ch in s:
                if ch.isdigit():
                    nums += ch
            n = len(nums)
            res = "***-***-" + nums[n-4:]
            if n > 10:
                res = "+" + (n-10) * "*" + "-" + res
        return res