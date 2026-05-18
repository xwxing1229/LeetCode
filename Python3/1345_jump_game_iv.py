# https://leetcode.cn/problems/jump-game-iv/

from collections import defaultdict, deque

class Solution:
    def minJumps(self, arr: list[int]) -> int:
        position = defaultdict(list)
        for i, num in enumerate(arr):
            position[num].append(i)

        n = len(arr)
        q = deque()
        q.append(0)
        visited = [False for _ in range(n)]
        visited[0] = True
        res = 0
        while True:
            n_q = len(q)
            for _ in range(n_q):
                i = q.popleft()
                if i == n-1:
                    return res
                
                if not visited[i+1]:
                    q.append(i+1)
                    visited[i+1] = True
                if i > 0 and not visited[i-1]:
                    q.append(i-1)
                    visited[i-1] = True

                num = arr[i]
                for j in position[num]:
                    if not visited[j]:
                        q.append(j)
                        visited[j] = True
                position[num].clear()

            res += 1