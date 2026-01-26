# https://leetcode.cn/problems/minimum-absolute-difference/

class Solution:
    def minimumAbsDifference(self, arr: list[int]) -> list[list[int]]:
        arr.sort()
        diff_min = arr[1] - arr[0]
        for i in range(1, len(arr)):
            diff_min = min(diff_min, arr[i] - arr[i-1])
        res = []
        for i in range(1, len(arr)):
            if arr[i] - arr[i-1] == diff_min:
                res.append([arr[i-1], arr[i]])
        return res