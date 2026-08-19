# https://leetcode.cn/problems/cinema-seat-allocation/

from collections import defaultdict

class Solution:
    def maxNumberOfFamilies(self, n: int, reservedSeats: list[list[int]]) -> int:
        reserved = defaultdict(int)
        for row, seat in reservedSeats:
            if seat >= 2 and seat <= 9:
                reserved[row] |= (1 << seat)
        res = 2 * (n - len(reserved))
        tmp1 =     0b111100
        tmp2 =   0b11110000
        tmp3 = 0b1111000000
        for seat in reserved.values():
            if (seat & tmp1) == 0 or (seat & tmp2) == 0 or (seat & tmp3) == 0:
                res += 1
        return res