# https://leetcode.cn/problems/possible-bipartition/

class Solution:
    def possibleBipartition(self, n, dislikes):
        """
        Inputs:
            n: int
            dislikes: list[list[int]]
        Outputs:
            res: bool
        """
        table = {i: [] for i in range(n)}
        for a, b in dislikes:
            table[a-1].append(b-1)
            table[b-1].append(a-1)
        # people[i] = 1: first group
        # people[i] = 2: second group
        people = [0 for i in range(n)]

        def dfs(person, group):
            people[person] = group
            for i in table[person]:
                if people[i] == group:
                    return False
                elif people[i] == 0:
                    tmp = dfs(i, 3-group)
                    if not tmp:
                        return False
            return True
        
        for i in range(n):
            if people[i] == 0:
                tmp = dfs(i, 1)
                if not tmp:
                    return False
        return True