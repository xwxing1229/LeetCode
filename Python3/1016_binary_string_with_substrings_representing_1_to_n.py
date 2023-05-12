# https://leetcode.cn/problems/binary-string-with-substrings-representing-1-to-n/

class Solution:
    def queryString(self, s, n):
        """
        Inputs:
            s: str
            n: int
        Outputs:
            res: bool
        """
        check = set()
        for i in range(len(s)):
            num = int(s[i])
            if num <= n and num > 0:
                check.add(num)
            else:
                continue
            for j in range(i+1, len(s)):
                num = num * 2 + int(s[j])
                if num <= n and num > 0:
                    check.add(num)
                else:
                    break
        return len(check) == n