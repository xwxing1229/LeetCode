# https://leetcode-cn.com/problems/valid-anagram/

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
        
        s_count = [0] * 26
        t_count = [0] * 26
        for i in range(len(s)):
            s_count[ord(s[i]-97)] = s_count[ord(s[i]-97)] + 1
            t_count[ord(t[i]-97)] = t_count[ord(t[i]-97)] + 1
        
        return s_count == t_count