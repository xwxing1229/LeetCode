# https://leetcode.cn/problems/replace-the-substring-for-balanced-string/

class Solution:
    def balancedString(self, s):
        """
        Inputs:
            s: str
        Outputs:
            res: int
        """
        cnt = Counter(s)
        n, thr = len(s), len(s) // 4
        if cnt["Q"] == thr and cnt["W"] == thr and cnt["E"] == thr and cnt["R"] == thr:
            return 0

        res, start = n, 0
        for i, ch in enumerate(s):
            cnt[ch] -= 1
            while start <= i and cnt["Q"] <= thr and cnt["W"] <= thr and cnt["E"] <= thr and cnt["R"] <= thr:
                res = min(res, i - start + 1)
                cnt[s[start]] += 1
                start += 1
        return res