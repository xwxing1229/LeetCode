# https://leetcode-cn.com/problems/task-scheduler/
class Solution:
    def leastInterval(self, tasks, n):
        """
        Inputs:
            tasks: list[str]
            n: int
        Outputs:
            res: int
        """

        count = {}
        max_task = 0
        for i in tasks:
            count[i] = count.get(i,0) + 1
            if count[i] > max_task:
                max_task = count[i]

        num_max_task = 0
        for i in count:
            if count[i] == max_task:
                num_max_task = num_max_task + 1

        # A, B, C, ...
        # A, B, C, ...
        # A, B
        # row: max_task
        
        if num_max_task >= n+1:
            res_tmp = max_task * num_max_task
            vacant = 0
        else:
            res_tmp = (max_task-1) * (n+1) + num_max_task
            vacant = (max_task-1) * (n+1-num_max_task)
        total = len(tasks)
        res = res_tmp + max(0, total-max_task*num_max_task-vacant)
        return res