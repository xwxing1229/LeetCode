# https://leetcode.cn/problems/longest-increasing-subsequence/

class Solution:
    def lengthOfLIS(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """
        arr = [nums[0]]
        for i in range(1, len(nums)):
            num = nums[i]
            if num > arr[-1]:
                arr.append(num)
            else:
                # Find a minimum i such that arr[i] >= num.
                left = 0
                right = len(arr) - 1
                tmp = len(arr) - 1
                while left <= right:
                    mid = left + (right - left) // 2
                    if arr[mid] >= num:
                        right = mid - 1
                        tmp = mid
                    else:
                        left = mid + 1
                arr[tmp] = num
        return len(arr)
