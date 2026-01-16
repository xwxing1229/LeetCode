# https://leetcode.cn/problems/maximum-square-area-by-removing-fences-from-a-field/

class Solution:
    def maximizeSquareArea(self, m: int, n: int, hFences: list[int], vFences: list[int]) -> int:
        mod = int(1e9) + 7

        hFences += [1, m]
        vFences += [1, n]

        sides_h = set()
        for i, hfi in enumerate(hFences):
            for j in range(i+1, len(hFences)):
                sides_h.add(abs(hFences[j] - hfi))
        
        side = 0
        for i, vfi in enumerate(vFences):
            for j in range(i+1, len(vFences)):
                tmp = abs(vFences[j] - vfi)
                if tmp in sides_h and tmp > side:
                    side = tmp
        return side * side % mod if side else -1