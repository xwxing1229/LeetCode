# https://leetcode.cn/problems/partition-array-according-to-given-pivot/

class Solution:
    def pivotArray(self, nums: list[int], pivot: int) -> list[int]:
        n = len(nums)
        left, right = [0 for _ in range(n)], [0 for _ in range(n)]
        cnt_left, cnt_pivot, cnt_right = 0, 0, 0
        for i, num in enumerate(nums):
            if num < pivot:
                left[cnt_left] = num
                cnt_left += 1
            elif num > pivot:
                right[cnt_right] = num
                cnt_right += 1
            else:
                cnt_pivot += 1
        return left[:cnt_left] + [pivot for _ in range(cnt_pivot)] + right[:cnt_right]