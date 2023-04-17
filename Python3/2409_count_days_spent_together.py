# https://leetcode.cn/problems/count-days-spent-together/

class Solution:
    def countDaysTogether(self, arriveAlice, leaveAlice, arriveBob, leaveBob):
        """
        Inputs:
            arriveAlice, leaveAlice, arriveBob, leaveBob: str
        Outputs:
            res: int
        """
        months = [31, 28, 31, 30, 31, 30,
                  31, 31, 30, 31, 30, 31]
        alice_bob = [arriveAlice, leaveAlice, arriveBob, leaveBob]
        days = [0 for i in range(4)]
        for i in range(4):
            tmp = int(alice_bob[i][3:])
            for j in range(int(alice_bob[i][:2]) - 1):
                tmp += months[j]
            days[i] = tmp
        res = min(days[1], days[3]) - max(days[0], days[2]) + 1
        if res < 0:
            res = 0
        return res