# https://leetcode.cn/problems/minimum-swaps-to-make-strings-equal/

class Solution:
    def minimumSwap(self, s1, s2):
        """
        Inputs:
            s1, s2: str
        Outputs:
            res: int
        """
        s1_x, s1_y = 0, 0
        for i in range(len(s1)):
            if s1[i] != s2[i]:
                if s1[i] == "x":
                    s1_x += 1
                else:
                    s1_y += 1

        res = s1_x // 2 + s1_y // 2
        remain = s1_x % 2 + s1_y % 2
        if remain == 1:
            return -1
        elif remain == 0:
            return res
        else:
            return res + 2