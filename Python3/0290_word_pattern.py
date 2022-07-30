# https://leetcode.cn/problems/word-pattern/

class Solution:
    def wordPattern(self, pattern, s):
        """
        Inputs:
            pattern: str
            s: str
        Outputs:
            res: bool
        """
        words = s.split()
        if len(pattern) != len(words):
            return False

        hash_ps = dict()
        hash_sp = dict()
        for i in range(len(pattern)):
            p = pattern[i]
            word = words[i]
            if hash_ps.get(p, -1) == -1 and hash_sp.get(word, -1) == -1:
                hash_ps[p] = word
                hash_sp[word] = p
            
            elif hash_ps.get(p, -1) != word or hash_sp.get(word, -1) != p:
                return False

        return True