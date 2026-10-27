# https://leetcode.cn/problems/create-grid-with-exactly-one-path/

class Solution:
    def createGrid(self, m: int, n: int) -> list[str]:
        res = ["#" * (n-1) + "." for _ in range(m)]
        res[0] = "." * n
        return res