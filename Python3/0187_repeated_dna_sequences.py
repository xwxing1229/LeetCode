# https://leetcode.cn/problems/repeated-dna-sequences/

class Solution:
    def findRepeatedDnaSequences(self, s):
        """
        Inputs:
            s: str
        Outputs:
            res: list[str]
        """

        res = []
        cnt = dict()
        for i in range(len(s)-9):
            ssub = s[i: i+10]
            cnt[ssub] = cnt.get(ssub, 0) + 1
            if cnt[ssub] == 2:
                res.append(ssub)
        return res

solu = Solution()
s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
print(solu.findRepeatedDnaSequences(s))