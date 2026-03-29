# https://leetcode.cn/problems/check-if-strings-can-be-made-equal-with-operations-i/

class Solution:
    def canBeEqual(self, s1: str, s2: str) -> bool:
        l1, l2 = list(s1), list(s2)
        for i in range(len(l1)-2):
            if l1[i] == l2[i]:
                continue
            elif l1[i+2] == l2[i]:
                l1[i], l1[i+2] = l1[i+2], l1[i]
            else:
                return False
        return l1[-2] == l2[-2] and l1[-1] == l2[-1]