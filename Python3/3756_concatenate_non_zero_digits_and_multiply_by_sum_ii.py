# https://leetcode.cn/problems/concatenate-non-zero-digits-and-multiply-by-sum-ii/

class Solution:
    def sumAndMultiply(self, s: str, queries: list[list[int]]) -> list[int]:
        mod = int(1e9) + 7
        pow10 = [1 for _ in range(int(1e5)+1)]
        for i in range(1, int(1e5)+1):
            pow10[i] = pow10[i-1] * 10 % mod
        
        n = len(s)
        cumsum = [0 for _ in range(n+1)]
        nums = [0 for _ in range(n+1)]
        cnts = [0 for _ in range(n+1)] # number of non-zero digits
        for i, ch in enumerate(s):
            val = int(ch)
            cumsum[i+1] = cumsum[i] + val
            nums[i+1] = (nums[i] * 10 + val) % mod if val > 0 else nums[i]
            cnts[i+1] = cnts[i] + (val > 0)

        res = [0 for _ in range(len(queries))]
        for i, q in enumerate(queries):
            l, r = q[0], q[1] + 1
            x = nums[r] - nums[l] * pow10(cnts[r] - cnts[l]) % mod + mod
            res[i] = x * (cumsum[r] - cumsum[l]) % mod
        return res