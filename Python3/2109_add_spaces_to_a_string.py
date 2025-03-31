# https://leetcode.cn/problems/adding-spaces-to-a-string/

class Solution:
    def addSpaces(self, s, spaces):
        """
        Inputs:
            s: str
            spaces: list[int]
        Outputs:
            res: str
        """
        n1, n2 = len(s), len(spaces)
        res = [" " for _ in range(n1+n2)]
        i2, ires = 0, 0
        for i1 in range(n1):
            if i2 < n2 and i1 == spaces[i2]:
                i2 += 1
                ires += 1
            res[ires] = s[i1]
            ires += 1
        return "".join(res)
    
s = "LeetcodeHelpsMeLearn"
spaces = [8, 13, 15]
print(Solution().addSpaces(s, spaces))