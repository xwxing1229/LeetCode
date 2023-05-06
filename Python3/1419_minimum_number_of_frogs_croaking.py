# https://leetcode.cn/problems/minimum-number-of-frogs-croaking/

class Solution:
    def minNumberOfFrogs(self, croakOfFrogs):
        """
        Inputs:
            croakOfFrogs: str
        Outputs:
            res: int
        """
        res, free = 0, 0
        cnt = {ch: 0 for ch in "croak"}
        for ch in croakOfFrogs:
            cnt[ch] += 1
            if ch == "c":
                if free == 0:
                    res += 1
                else:
                    free -= 1
            elif ch == "k":
                free += 1
            else:
                for cur in "croak":
                    if cur == ch:
                        break
                    elif cnt[cur] < cnt[ch]:
                        return -1
        check = cnt["c"]
        for c in cnt.values():
            if c != check:
                return -1
        return res