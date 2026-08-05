# https://leetcode.cn/problems/remove-methods-from-project/

from collections import deque

class Solution:
    def remainingMethods(self, n: int, k: int, invocations: list[list[int]]) -> list[int]:
        forward = [[] for _ in range(n)]
        for a, b in invocations:
            forward[a].append(b)

        bugs = [False for _ in range(n)]
        bugs[k] = True
        q = deque()
        q.append(k)
        while q:
            curr = q.popleft()
            for node in forward[curr]:
                if not bugs[node]:
                    bugs[node] = True
                    q.append(node)

        for curr, bug in enumerate(bugs):
            if bug:
                continue
            for node in forward[curr]:
                if bugs[node]:
                    return [i for i in range(n)]
        res = [curr for curr, bug in enumerate(bugs) if not bug]
        return res