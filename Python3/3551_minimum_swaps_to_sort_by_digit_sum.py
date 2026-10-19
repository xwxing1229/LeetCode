# https://leetcode.cn/problems/minimum-swaps-to-sort-by-digit-sum/

class Solution:
    def minSwaps(self, nums: list[int]) -> int:
        n = len(nums)
        digit_sum = [0 for _ in range(n)]
        for i, num in enumerate(nums):
            s = 0
            while num > 0:
                s += num % 10
                num //= 10
            digit_sum[i] = s

        indices = [i for i in range(n)]
        indices.sort(key=lambda i: (digit_sum[i], nums[i]))

        target_pos = [0 for _ in range(n)]
        for pos, i in enumerate(indices):
            target_pos[i] = pos

        visited = [False for _ in range(n)]
        cycles = 0
        for i in range(n):
            if not visited[i]:
                cycles += 1
                j = i
                while not visited[j]:
                    visited[j] = True
                    j = target_pos[j]
        return n - cycles