# https://leetcode.cn/problems/find-the-losers-of-the-circular-game/

class Solution:
    def circularGameLosers(self, n, k):
        """
        Inputs:
            n, k: int
        Outputs:
            res: list[int]
        """
        check = [False for _ in range(n)]
        cur, step = 0, k
        while not check[cur]:
            check[cur] = True
            cur = (cur + step) % n
            step += k

        res = []
        for i in range(n):
            if not check[i]:
                res.append(i+1)
        return res