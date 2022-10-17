# https://leetcode.cn/problems/pacific-atlantic-water-flow/

class Solution:
    def pacificAtlantic(self, heights):
        """
        Inputs:
            heights: list[list[int]]
        Outputs:
            res: list[list[int]]
        """

        self.res = {
            "p": set(), "a": set()
        }
        self.dirs = [[0,1], [0,-1], [1,0], [-1,0]]
        rows, cols = len(heights), len(heights[0])
        # Search for positions from which rain can flow to the Pacific Ocean.
        self.check = [[0 for j in range(cols)] for i in range(rows)]
        for i in range(rows):
            self.dfs(heights, [i,0], "p")
        for j in range(cols):
            self.dfs(heights, [0,j], "p")
        # Search for positions from which rain can flow to the Atlantic Ocean.
        self.check = [[0 for j in range(cols)] for i in range(rows)]
        for i in range(rows):
            self.dfs(heights, [i,cols-1], "a")
        for j in range(cols):
            self.dfs(heights, [rows-1,j], "a")

        res = []
        for pos in self.res["p"]:
            if pos in self.res["a"]:
                res.append([pos//500, pos%500])
        return res

    def dfs(self, heights, start, ocean):
        if self.check[start[0]][start[1]]:
            return

        self.res[ocean].add(500*start[0]+start[1])
        self.check[start[0]][start[1]] = 1

        rows, cols = len(heights), len(heights[0])
        for d in self.dirs:
            pos = [start[0]+d[0], start[1]+d[1]]
            if pos[0] >= 0 and pos[0] < rows and\
                pos[1] >= 0 and pos[1] < cols:
                if heights[pos[0]][pos[1]] >= heights[start[0]][start[1]]:
                    self.dfs(heights, pos, ocean)
