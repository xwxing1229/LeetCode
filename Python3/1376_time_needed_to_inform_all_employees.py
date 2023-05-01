# https://leetcode.cn/problems/time-needed-to-inform-all-employees/

class Solution:
    def numOfMinutes(self, n, headID, manager, informTime):
        """
        Inputs:
            n, headID: int
            manager, informTime: list[int]
        Outputs:
            res: int
        """
        graph = defaultdict(list)
        for i in range(n):
            graph[manager[i]].append(i)

        res = 0
        q = [headID]
        minutes = [0 for i in range(n)]
        while q:
            length = len(q)
            for i in range(length):
                cur = q.pop(0)
                for employee in graph[cur]:
                    q.append(employee)
                    minutes[employee] = minutes[cur] + informTime[cur]
                    if res < minutes[employee]:
                        res = minutes[employee]
        return res