# https://leetcode.cn/problems/letter-tile-possibilities/

class Solution:
    def numTilePossibilities(self, tiles):
        """
        Inputs:
            tiles: str
        Outputs:
            res: int
        """
        self.res = 0
        self.check = set()
        used = [0 for _ in range(len(tiles))]
        for length in range(1, len(tiles)+1):
            self.dfs(tiles, "", used, length)
        return self.res

    def dfs(self, tiles, cur, used, n):
        if len(cur) == n:
            if cur not in self.check:
                self.res += 1
                self.check.add(cur)
            return

        for i in range(len(tiles)):
            if used[i]:
                continue
            used[i] = 1
            self.dfs(tiles, cur+tiles[i], used, n)
            used[i] = 0