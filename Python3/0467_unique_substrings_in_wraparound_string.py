# https://leetcode.cn/problems/unique-substrings-in-wraparound-string/

class Solution:
    def findSubstringInWraproundString(self, p):
        """
        Inputs:
            p: str
        Outputs:
            res: int
        """

        # record[i]: maximum length of substring that ends with the ith letter.
        record = [0 for i in range(26)]
        n = 1
        record[ord(p[0]) - ord("a")] = n
        for i in range(1, len(p)):
            diff = ord(p[i]) - ord(p[i-1])
            if diff == 1 or diff == -25:
                n += 1
            else:
                n = 1
            if record[ord(p[i]) - ord("a")] < n:
                record[ord(p[i]) - ord("a")] = n
        res = 0
        for i in record:
            res += i
        return res