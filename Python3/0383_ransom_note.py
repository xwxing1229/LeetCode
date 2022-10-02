# https://leetcode.cn/problems/ransom-note/

class Solution:
    def canConstruct(self, ransomNote, magazine):
        """
        Inputs:
            ransomNote: str
            magzine: str
        Outputs:
            res: bool
        """

        if len(ransomNote) > len(magazine):
            return False

        cnt = [0 for _ in range(26)]
        for ch in magazine:
            cnt[ord(ch)-ord('a')] = cnt[ord(ch)-ord('a')] + 1
        for ch in ransomNote:
            cnt[ord(ch)-ord('a')] = cnt[ord(ch)-ord('a')] - 1
            if cnt[ord(ch)-ord('a')] < 0:
                return False
        return True