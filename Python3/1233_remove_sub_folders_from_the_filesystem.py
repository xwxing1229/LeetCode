# https://leetcode.cn/problems/remove-sub-folders-from-the-filesystem/

class Solution:
    def removeSubfolders(self, folder):
        """
        Inputs:
            folder: list[str]
        Outputs:
            res: list[int]
        """
        folder.sort()
        res = [folder[0]]
        for i in range(1, len(folder)):
            pre, cur = res[-1], folder[i]
            n_pre, n_cur = len(pre), len(cur)
            if n_pre > n_cur:
                res.append(cur)
            elif n_pre == n_cur:
                if pre != cur:
                    res.append(cur)
            else:
                if not (pre == cur[:n_pre] and cur[n_pre] == "/"):
                    res.append(cur)
        return res