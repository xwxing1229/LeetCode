# https://leetcode.cn/problems/card-flipping-game/

class Solution:
    def flipgame(self, fronts, backs):
        """
        Inputs:
            fronts, backs: list[int]
        Outputs:
            res: int
        """
        # Place the cards that front == back to the first segment of the list.
        cards = [(fronts[i], backs[i]) for i in range(len(fronts))]
        cards.sort(key=lambda x: (x[0]!=x[1], min(x[0], x[1])))

        s = set()
        res = 2001
        for f, b in cards:
            if f == b:
                s.add(f)
            else:
                if res > f and f not in s:
                    res = f
                if res > b and b not in s:
                    res = b
        if res == 2001:
            res = 0
        return res