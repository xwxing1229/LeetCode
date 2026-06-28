# https://leetcode.cn/problems/find-the-maximum-number-of-elements-in-subset/
    
from collections import Counter

class Solution:
    def maximumLength(self, nums: list[int]) -> int:
        cnt = Counter(nums)

        # If cnt[1] is odd, res = cnt[1].
        # Otherwise, res = cnt[1] - 1.
        res = (cnt[1] - 1) | 1
        del cnt[1]

        for num in cnt:
            tmp = 0
            x = num
            while cnt.get(x, 0) >= 2:
                tmp += 2
                x *= x
            res = max(res, tmp + (1 if x in cnt else -1))
        return res