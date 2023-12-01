# https://leetcode.cn/problems/determine-if-two-strings-are-close/

class Solution:
    def closeStrings(self, word1, word2):
        """
        Inputs:
            word1, word2: str
        Outputs:
            res: int
        """
        if len(word1) != len(word2):
            return False
        cnt1, cnt2 = [0 for _ in range(26)], [0 for _ in range(26)]
        ord_a = ord("a")
        for i in range(len(word1)):
            cnt1[ord(word1[i]) - ord_a] += 1
            cnt2[ord(word2[i]) - ord_a] += 1
        for i in range(26):
            if cnt1[i] == 0 and cnt2[i] != 0:
                return False
        cnt1.sort()
        cnt2.sort()
        for i in range(26):
            if cnt1[i] != cnt2[i]:
                return False
        return True