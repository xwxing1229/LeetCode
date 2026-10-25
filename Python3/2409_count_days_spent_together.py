# https://leetcode.cn/problems/count-days-spent-together/

class Solution:
    def countDaysTogether(self, arriveAlice: str, leaveAlice: str, arriveBob: str, leaveBob: str) -> int:
        days = [31, 28, 31, 30, 31, 30,
                31, 31, 30, 31, 30, 31]
        cumsum = [0 for _ in range(12)]
        for i in range(1, 12):
            cumsum[i] = cumsum[i-1] + days[i-1]

        def convert(s: str) -> int:
            return cumsum[int(s[:2]) - 1] + int(s[3:])

        alice = [convert(arriveAlice), convert(leaveAlice)]
        bob = [convert(arriveBob), convert(leaveBob)]
        return max(min(alice[1], bob[1]) - max(alice[0], bob[0]) + 1, 0)