# https://leetcode.cn/problems/minimum-genetic-mutation/

class Solution:
    def minMutation(self, start, end, bank):
        """
        Inputs:
            start: str
            end: str
            bank: list[str]
        Outputs:
            res: int
        """
        self.res = len(bank) + 1
        check = {start}
        self.dfs(end, bank, start, 0, check)
        if self.res > len(bank):
            return -1
        return self.res

    def dfs(self, end, bank, cur, cnt, check):
        if cur == end:
            if cnt < self.res:
                self.res = cnt
            return

        for gene in bank:
            if gene in check:
                continue

            diff = 0
            for i in range(8):
                if cur[i] != gene[i]:
                    diff += 1
            if diff == 1:
                check.add(gene)
                self.dfs(end, bank, gene, cnt+1, check)
                check.remove(gene)