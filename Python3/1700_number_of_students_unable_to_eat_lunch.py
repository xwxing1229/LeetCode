# https://leetcode.cn/problems/number-of-students-unable-to-eat-lunch/

class Solution:
    def countStudents(self, students, sandwiches):
        """
        Inputs:
            students: list[int]
            sandwiches: list[int]
        Outputs:
            res: int
        """

        eat1 = sum(students)
        eat0 = len(students) - eat1

        for sand in sandwiches:
            if sand == 0 and eat0 > 0:
                eat0 -= 1
            elif sand == 1 and eat1 > 0:
                eat1 -= 1
            else:
                break
        return eat0 + eat1
