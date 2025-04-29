# https://leetcode.cn/problems/count-subarrays-where-max-element-appears-at-least-k-times/

class Solution:
    def countSubarrays(self, nums, k):
        """
        Inputs:
            nums: list[int]
            k: int
        Outputs:
            res: int
        """
        mx = max(nums)
        n, left, right = len(nums), 0, 0
        res, cnt = 0, 0
        while right < n:
            if nums[right] == mx:
                cnt += 1
            right += 1
            while left < right and cnt >= k:
                if nums[left] == mx:
                    cnt -= 1
                left += 1
            
            res += left
        return res