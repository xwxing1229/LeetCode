# https://leetcode.cn/problems/average-salary-excluding-the-minimum-and-maximum-salary/

class Solution:
    def average(self, salary):
        """
        Inputs:
            salary: list[int]
        Outputs:
            res: float
        """
        min_, max_ = salary[0], salary[0]
        s = 0.
        for val in salary:
            min_ = min(min_, val)
            max_ = max(max_, val)
            s += val
        res = (s - min_ - max_) / (len(salary) - 2)
        return res