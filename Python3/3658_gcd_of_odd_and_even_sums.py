# https://leetcode.cn/problems/gcd-of-odd-and-even-sums/

import math
class Solution:
    def gcdOfOddEvenSums(self, n: int) -> int:
        odd = n * n
        even = odd + n
        return math.gcd(odd, even)