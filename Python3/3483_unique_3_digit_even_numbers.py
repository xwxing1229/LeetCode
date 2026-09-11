# https://leetcode.cn/problems/unique-3-digit-even-numbers/

class Solution:
    def totalNumbers(self, digits: list[int]) -> int:
        s = set()
        # The number is cba.
        for ia, a in enumerate(digits):
            if a % 2 == 1:
                continue
            for ib, b in enumerate(digits):
                if ib == ia:
                    continue
                for ic, c in enumerate(digits):
                    if c == 0 or ic == ia or ic == ib:
                        continue
                    s.add(c * 100 + b * 10 + a)
        return len(s)