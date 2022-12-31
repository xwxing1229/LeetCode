# https://leetcode.cn/problems/minimum-number-of-moves-to-seat-everyone/

class Solution:
    def minMovesToSeat(self, seats, students):
        """
        Inputs:
            seats: list[int]
            students: list[int]
        Outputs:
            res: int
        """
        seats.sort()
        students.sort()
        res = 0
        for i, stu in enumerate(students):
            res += abs(stu - seats[i])
        return res