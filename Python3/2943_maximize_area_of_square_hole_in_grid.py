# https://leetcode.cn/problems/maximize-area-of-square-hole-in-grid/

class Solution:
    def maximizeSquareHoleArea(self, n: int, m: int, hBars: list[int], vBars: list[int]) -> int:
        def MaxCont(bars: list[int]):
            bars.sort()
            res, cont = 1, 1
            for i in range(1, len(bars)):
                if bars[i] - bars[i-1] == 1:
                    cont += 1
                    res = max(res, cont)
                else:
                    cont = 1
            return res
        
        side = min(MaxCont(hBars), MaxCont(vBars)) + 1
        return side * side