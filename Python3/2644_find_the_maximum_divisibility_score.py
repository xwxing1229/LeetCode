# https://leetcode.cn/problems/find-the-maximum-divisibility-score/

class Solution:
    def maxDivScore(self, nums, divisors):
        """
        Inputs:
            nums, divisors: list[list[int]]
        Outputs:
            res: int
        """
        cnt = defaultdict(int)
        for num in nums:
            cnt[num] += 1
        res, score = divisors[0], 0
        for d in divisors:
            tmp = 0
            for k, v in cnt.items():
                if k % d == 0:
                    tmp += v
            if tmp > score:
                res = d
                score = tmp
            elif tmp == score:
                res = min(res, d)
        return res