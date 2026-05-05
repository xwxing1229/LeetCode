# https://leetcode.cn/problems/check-if-strings-can-be-made-equal-with-operations-ii/

class Solution:
    def checkStrings(self, s1: str, s2: str) -> bool:
        cnt1 = [[0,0] for _ in range(26)]
        cnt2 = [[0,0] for _ in range(26)]
        for i in range(len(s1)):
            ch1 = ord(s1[i]) - ord("a")
            ch2 = ord(s2[i]) - ord("a")
            cnt1[ch1][i%2] += 1
            cnt2[ch2][i%2] += 1
        for i in range(26):
            if cnt1[i][0]  != cnt2[i][0] or cnt1[i][1] != cnt2[i][1]:
                return False
        return True