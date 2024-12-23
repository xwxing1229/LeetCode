# https://leetcode.cn/problems/sort-the-students-by-their-kth-score/

class Solution:
    def sortTheStudents(self, score, k):
        """
        Inputs:
            score: list[list[int]]
            k: int
        Outputs:
            res: list[list[int]]
        """
        score.sort(key=lambda x: -x[k])
        return score