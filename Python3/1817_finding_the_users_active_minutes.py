# https://leetcode.cn/problems/finding-the-users-active-minutes/

class Solution:
    def findingUsersActiveMinutes(self, logs, k):
        """
        Inputs:
            logs: list[list[int]]
            k: int
        Outputs:
            res: list[int]
        """
        cnt = defaultdict(set)
        for log in logs:
            cnt[log[0]].add(log[1])
        res = [0 for _ in range(k)]
        for _, v in cnt.items():
            res[len(v)-1] += 1
        return res