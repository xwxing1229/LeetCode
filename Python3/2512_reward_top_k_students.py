# https://leetcode.cn/problems/reward-top-k-students/

class Solution:
    def topStudents(self, positive_feedback, negative_feedback, report, student_id, k):
        """
        Inputs:
            positive_feedback, negative_feedback, report: list[str]
            student_id: list[int]
            k: int
        Outputs:
            res: list[int]
        """
        posset, negset = set(positive_feedback), set(negative_feedback)
        n = len(student_id)
        scores = [0 for _ in range(n)]
        for i, s in enumerate(report):
            r = s.split(" ")
            for ch in r:
                if ch in posset:
                    scores[i] += 3
                elif ch in negset:
                    scores[i] -= 1
        res = [(student_id[i], score) for i, score in enumerate(scores)]
        res.sort(key=lambda x: (-x[1], x[0]))
        return [res[i][0] for i in range(k)]