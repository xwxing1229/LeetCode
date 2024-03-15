# https://leetcode.cn/problems/capitalize-the-title/

class Solution:
    def capitalizeTitle(self, title: str) -> str:
        """
        Inputs:
            title: str
        Outputs:
            res: str
        """
        start, n = 0, len(title)
        res = [" " for _ in range(n)]
        for i, ch in enumerate(title):
            if ch == " ":
                if i - start > 2:
                    res[start] = res[start].upper()
                start = i + 1
            else:
                res[i] = title[i].lower()
        if n - start > 2:
            res[start] = res[start].upper()
        return "".join(res)