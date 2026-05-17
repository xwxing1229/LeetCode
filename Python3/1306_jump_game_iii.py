# https://leetcode.cn/problems/jump-game-iii/

from collections import deque

class Solution:
    def canReach(self, arr: list[int], start: int) -> bool:
        n = len(arr)
        q = deque()
        q.append(start)
        visited = [0 for _ in range(n)]
        visited[start] = 1
        while q:
            i = q.popleft()
            if arr[i] == 0:
                return True
            for idx in [i+arr[i], i-arr[i]]:
                if idx < 0 or idx >= n or visited[idx]:
                    continue
                q.append(idx)
                visited[idx] = 1
        return False