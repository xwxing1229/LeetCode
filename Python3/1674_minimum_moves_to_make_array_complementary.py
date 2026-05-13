# https://leetcode.cn/problems/minimum-moves-to-make-array-complementary/

class Solution:
    def minMoves(self, nums: list[int], limit: int) -> int:
        n = len(nums)
        diff = [0 for _ in range(limit*2+2)]
        for i in range(n // 2):
            a, b = nums[i], nums[n-1-i]
            left = min(a, b) + 1
            right = max(a, b) + limit

            # [2, left-1] += 2
            diff[2] += 2
            diff[left] -= 2

            # [left, right] += 1
            diff[left] += 1
            diff[right+1] -= 1

            diff[a+b] -= 1
            diff[a+b+1] += 1

            # [right+1, limit*2] += 2
            diff[right+1] += 2

        res = n
        count = 0
        for i in range(2, limit*2+1):
            count += diff[i]
            res = min(res, count)
        return res