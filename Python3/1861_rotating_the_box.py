# https://leetcode.cn/problems/rotating-the-box/

class Solution:
    def rotateTheBox(self, boxGrid: list[list[str]]) -> list[list[str]]:
        n, m = len(boxGrid), len(boxGrid[0])
        res = [["." for _ in range(n)] for _ in range(m)]
        for i in range(m):
            for j in range(n):
                res[i][j] = boxGrid[n-1-j][i]
        for j in range(n):
            empty = m - 1
            for i in range(m-1, -1, -1):
                element = res[i][j]
                if element == "#":
                    res[i][j] = "."
                    res[empty][j] = "#"
                    empty -= 1
                elif element == "*":
                    empty = i - 1
                else:
                    empty = max(empty, i)

        return res