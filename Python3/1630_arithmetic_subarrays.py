# https://leetcode.cn/problems/arithmetic-subarrays/

class Solution:
    def checkArithmeticSubarrays(self, nums, l, r):
        """
        Inputs:
            nums, l, r: list[int]
        Outputs:
            res: list[bool]
        """
        n, m = len(nums), len(l)
        idxs = [i for i in range(n)]
        pairs = sorted(zip(idxs, nums), key=lambda x: x[1])

        res = [True for i in range(m)]
        for i in range(m):
            left, right = l[i], r[i]
            pre, diff = 0, 0
            first, second = False, False
            for j in range(n):
                idx = pairs[j][0]
                if idx < left or idx > right:
                    continue

                if not first:
                    pre = pairs[j][1]
                    first = True
                elif not second:
                    diff = pairs[j][1] - pre
                    pre = pairs[j][1]
                    second = True
                else:
                    if pairs[j][1] - pre != diff:
                        res[i] = False
                        break
                    else:
                        pre = pairs[j][1]
        return res