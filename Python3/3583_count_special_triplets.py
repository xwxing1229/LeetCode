# https://leetcode.cn/problems/count-special-triplets/

from collections import defaultdict

class Solution:
    def specialTriplets(self, nums: list[int]) -> int:
        res = 0
        mod = 10**9 + 7
        position = defaultdict(list)
        for i, num in enumerate(nums):
            position[num].append(i)
        for num, pos in position.items():
            tar = num * 2
            if tar not in position:
                continue
            tar_pos = position[tar]
            n = len(tar_pos)
            for p in pos:
                left, right = 0, n-1
                k = -1
                while left <= right:
                    mid = (left + right) // 2
                    if tar_pos[mid] < p:
                        left = mid + 1
                        k = mid
                    else:
                        right = mid - 1
                if k >= 0:
                    left, right = k+1, n-k-1-(num==0)
                    res = (res + left * right) % mod
        return res