# https://leetcode.cn/problems/shortest-distance-to-target-string-in-a-circular-array/

class Solution:
    def closestTarget(self, words: list[str], target: str, startIndex: int) -> int:
        n = len(words)
        res = -1
        for i in range(startIndex, startIndex+n):
            if words[i % n] == target:
                res = i - startIndex
                break
        for i in range(startIndex, startIndex-n, -1):
            if words[(i+n) % n] == target:
                if res < 0 or res > startIndex - i:
                    res = startIndex - i
        return res