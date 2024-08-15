# https://leetcode.cn/problems/maximum-points-inside-the-square/

class Solution:
    def maxPointsInsideSquare(self, points, s):
        """
        Inputs:
            points: list[list[int]]
            s: str
        Outputs:
            res: int
        """
        m = defaultdict(list)
        for i, (x,y) in enumerate(points):
            d = max(abs(x), abs(y))
            m[d].append(i)
        
        res = 0
        visited = set()
        for d in sorted(m):
            idxs = m[d]
            for i in idxs:
                label = s[i]
                if label in visited:
                    return res
                visited.add(label)
            res += len(idxs)
        return res