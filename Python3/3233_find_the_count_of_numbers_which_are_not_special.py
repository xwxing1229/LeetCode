# https://leetcode.cn/problems/find-the-count-of-numbers-which-are-not-special/

class Solution:
    def nonSpecialCount(self, l: int, r: int) -> int:
        cnt = 0
        for num in range(3, int(sqrt(r))+1, 2):
            prime = True
            for factor in range(3, int(sqrt(num))+1, 2):
                if num % factor == 0:
                    prime = False
                    break

            if prime and num * num >= l:
                cnt += 1

        res = r - l + 1 - cnt
        if 4 >= l and 4 <= r:
            res -= 1
        return res