# https://leetcode.cn/problems/count-largest-group/

from collections import defaultdict

class Solution:
    def countLargestGroup(self, n: int) -> int:
        def digitsum(num):
            res = 0
            while num:
                res += num % 10
                num //= 10
            return res
        
        cnt = defaultdict(int)
        cnt_max, res = 0, 0
        for num in range(1, n+1):
            value = digitsum(num)
            cnt[value] += 1
            if cnt[value] > cnt_max:
                cnt_max = cnt[value]
                res = 1
            elif cnt[value] == cnt_max:
                res += 1
        return res