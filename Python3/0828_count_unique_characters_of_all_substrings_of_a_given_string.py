# https://leetcode.cn/problems/count-unique-characters-of-all-substrings-of-a-given-string/

class Solution:
    def uniqueLetterString(self, s):
        """
        Inputs:
            s: str
        Outputs:
            res: int
        """
        char_idxs = collections.defaultdict(list)
        for i, ch in enumerate(s):
            char_idxs[ch].append(i)

        res = 0
        for idxs in char_idxs.values():
            idxs = [-1] + idxs + [len(s)]
            for i in range(1, len(idxs)-1):
                res += (idxs[i] - idxs[i-1]) * (idxs[i+1] - idxs[i])
        return res