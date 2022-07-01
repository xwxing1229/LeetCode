# https://leetcode.cn/problems/compare-version-numbers/

class Solution:
    def compareVersion(self, version1, version2):
        """
        Inputs:
            version1: str
            version2: str
        Outputs:
            res: int
        """

        i1, num1, n1 = 0, 0, len(version1)
        i2, num2, n2 = 0, 0, len(version2)
        n = max(n1, n2)
        while i1 < n and i2 < n:
            while (i1 < n1) and (version1[i1] != "."):
                num1 = num1 * 10 + ord(version1[i1]) - ord("0")
                i1 = i1 + 1
            while (i2 < n2) and (version2[i2] != "."):
                num2 = num2 * 10 + ord(version2[i2]) - ord("0")
                i2 = i2 + 1

            if num1 > num2:
                return 1
            elif num1 < num2:
                return -1

            i1 = i1 + 1
            num1 = 0
            i2 = i2 + 1
            num2 = 0

        return 0
