# https://leetcode.cn/problems/check-if-one-string-swap-can-make-strings-equal/

class Solution:
    def areAlmostEqual(self, s1, s2):
        """
        Inputs:
            s1: str
            s2: str
        Outputs:
            res: bool
        """

        cnt_diff = 0
        do_swap = False
        tmp1, tmp2 = "0", "0"
        for i in range(len(s1)):
            ch1, ch2 = s1[i], s2[i]
            if ch1 != ch2:
                if ch1 == tmp2 and ch2 == tmp1:
                    cnt_diff = cnt_diff - 1
                    do_swap = True
                    tmp1, tmp2 = "0", "0"
                else:
                    cnt_diff = cnt_diff + 1
                    tmp1, tmp2 = ch1, ch2
                    
                if (cnt_diff > 0 and do_swap) or cnt_diff > 1:
                    return False
        if cnt_diff > 0:
            return False
        else:
            return True