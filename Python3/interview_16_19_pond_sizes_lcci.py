# https://leetcode.cn/problems/pond-sizes-lcci/

class Solution:
    def pondSizes(self, land):
        """
        Inputs:
            land: list[list[int]]
        Outputs:
            res: list[int]
        """
        res = []
        dirs = [
            [-1,-1], [-1,0], [-1,1],
            [0,-1], [0,1],
            [1,-1], [1,0], [1,1]
        ]
        rows, cols = len(land), len(land[0])
        for i in range(rows):
            for j in range(cols):
                if land[i][j] != 0:
                    continue
                q = deque()
                q.append((i,j))
                land[i][j] = -1
                cnt = 0
                while q:
                    curi, curj = q.popleft()
                    cnt += 1
                    for dx, dy in dirs:
                        x, y = curi + dx, curj + dy
                        if x < 0 or x >= rows or y < 0 or y >= cols:
                            continue
                        if land[x][y] != 0:
                            continue
                        q.append((x,y))
                        land[x][y] = -1
                res.append(cnt)
        res.sort()
        return res