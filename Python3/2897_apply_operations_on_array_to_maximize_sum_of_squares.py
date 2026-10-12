# https://leetcode.cn/problems/apply-operations-on-array-to-maximize-sum-of-squares/

class Solution:
    def maxSum(self, nums: list[int], k: int) -> int:
        length = 30
        cnt = [0 for _ in range(length)]
        for num in nums:
            for i in range(length):
                cnt[i] += ((num >> i) & 1)

        mod = int(1e9 + 7)
        res = 0
        for _ in range(k):
            num = 0
            for i in range(length):
                if cnt[i] > 0:
                    cnt[i] -= 1
                    num |= (1 << i)
            res = (res + num * num) % mod
        return res