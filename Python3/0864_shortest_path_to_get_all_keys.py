# https://leetcode.cn/problems/shortest-path-to-get-all-keys/

import collections
import heapq

class Solution1:
    def shortestPathAllKeys(self, grid):
        """
        Inputs:
            grid: list[str]
        Output:
            int
        """
        rows, cols = len(grid), len(grid[0])
        id_cur = -1
        pick_done = (1 << 6) - 1 # "111111"
        pick_cur = pick_done # 0: not picked, 1: picked
        for i in range(rows):
            for j in range(cols):
                ch = grid[i][j]
                if ch == "@":
                    id_cur = i * cols + j
                elif ch in "abcdef":
                    # Each key is unique.
                    pick_cur = pick_cur ^ (1 << (ord(ch) - ord("a")))

        # BFS.
        q = collections.deque()
        q.append((id_cur, pick_cur, 0))
        visited = {(id_cur, pick_cur)}
        directions = [[1,0], [-1,0], [0,1], [0,-1]]
        while len(q) > 0:
            n = len(q)
            for i in range(n):
                id_cur, pick_cur, steps = q.popleft()
                if pick_cur == pick_done: # all keys are picked up
                    return steps

                cur = [id_cur//cols, id_cur%cols]
                for d in directions:
                    neigh = [cur[0]+d[0], cur[1]+d[1]]
                    if neigh[0] < 0 or neigh[0] >= rows or\
                        neigh[1] < 0 or neigh[1] >= cols:
                        continue

                    ch = grid[neigh[0]][neigh[1]]
                    if ch == "#":
                        continue
                    if ch in "ABCDEF":
                        if (pick_cur >> (ord(ch) - ord("A"))) % 2 == 0: # locked
                            continue

                    if ch in "abcdef":
                        pick_neigh = pick_cur | (1 << (ord(ch) - ord("a")))
                    else:
                        pick_neigh = pick_cur
                    id_neigh = neigh[0] * cols + neigh[1]
                    if (id_neigh, pick_neigh) in visited:
                        continue
                    
                    q.append((id_neigh, pick_neigh, steps+1))
                    visited.add((id_neigh, pick_neigh))
        return -1
