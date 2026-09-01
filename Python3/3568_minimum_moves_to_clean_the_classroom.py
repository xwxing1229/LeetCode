# https://leetcode.cn/problems/minimum-moves-to-clean-the-classroom/

class Solution:
    def minMoves(self, classroom: list[str], energy: int) -> int:
        m, n = len(classroom), len(classroom[0])
        idx = [[0 for _ in range(n)] for _ in range(m)]
        cnt = 0 # count of litter
        sx, sy = 0, 0
        for i, row in enumerate(classroom):
            for j, ch in enumerate(row):
                if ch == "L":
                    idx[i][j] = 1 << cnt
                    cnt += 1
                elif ch == "S":
                    sx, sy = i, j
        if cnt == 0:
            return 0

        dirs = [[1,0], [-1,0], [0,1], [0,-1]]
        res = 0
        q = [(sx, sy, energy, 0)]
        max_energy = [[[-1] * (1 << cnt) for _ in range(n)] for _ in range(m)]
        max_energy[sx][sy][0] = energy
        full_mask = (1 << cnt) - 1
        while q:
            tmp = q
            q = []
            for x, y, e, mask in tmp:
                if mask == full_mask:
                    return res
                if e == 0:
                    continue
                for dx, dy in dirs:
                    nx, ny = x + dx, y + dy
                    if 0 <= nx < m and 0 <= ny < n and classroom[nx][ny] != 'X':
                        ne = e - 1
                        if classroom[nx][ny] == "R":
                            ne = energy
                        nmask = mask | idx[nx][ny]
                        if ne > max_energy[nx][ny][nmask]:
                            q.append((nx, ny, ne, nmask))
                            max_energy[nx][ny][nmask] = ne
            res += 1
        return -1