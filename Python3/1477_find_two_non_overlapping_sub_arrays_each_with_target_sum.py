# https://leetcode.cn/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/

class Solution:
    def minSumOfLengths(self, arr: list[int], target: int) -> int:
        n = len(arr)
        # f[i]: min length of substr in arr[i:] with sum equal to target.
        f = [n for _ in range(n)]
        rightmin = n
        right, s = n-1, 0
        for left in range(n-1, -1, -1):
            s += arr[left]
            while s > target:
                s -= arr[right]
                right -= 1
            if s == target:
                rightmin = min(rightmin, right - left + 1)
            f[left] = rightmin

        left, s = 0, 0
        res = n + 1
        for right in range(n-1):
            s += arr[right]
            while s > target:
                s -= arr[left]
                left += 1
            if s == target:
                tmp = right - left + 1 + f[right+1]
                res = min(res, tmp)
        return res if res <= n else -1