# https://leetcode.cn/problems/valid-anagram/

# ord('a') = 97

class Solution:
    def isAnagram(self, s, t):
        """
        Inputs:
            s: str
            t: str
        Outputs:
            res: bool
        """
        
        if len(s) != len(t):
            return False

        hash_table = dict()
        for ch in s:
            hash_table[ch] = hash_table.get(ch, 0) + 1
        for ch in t:
            hash_table[ch] = hash_table.get(ch, 0) - 1
            if hash_table[ch] < 0:
                return False
        return True