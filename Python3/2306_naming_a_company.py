# https://leetcode.cn/problems/naming-a-company/

class Solution:
    def distinctNames(self, ideas):
        """
        Inputs:
            ideas: list[str]
        Outputs:
            res: int
        """
        groups = [[] for _ in range(26)]
        for s in ideas:
            groups[ord(s[0]) - ord("a")].append(s[1:])
        res = 0
        for i in range(26):
            set1 = set(groups[i])
            for j in range(i+1, 26):
                common = 0
                for s in groups[j]:
                    if s in set1:
                        common += 1
                res += 2 * (len(groups[i]) - common) * (len(groups[j]) - common)
        return res