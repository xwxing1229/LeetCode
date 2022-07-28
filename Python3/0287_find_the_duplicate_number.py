# https://leetcode.cn/problems/find-the-duplicate-number/

class Solution:
    def findDuplicate(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """

        # Time complexity: O(n*log(n)), space complexity: O(1).
        left = 0
        right = len(nums) - 1
        while left < right:
            mid = left + (right - left) // 2
            
            cnt = 0
            for num in nums:
                if num <= mid:
                    cnt = cnt + 1

            if cnt > mid:
                right = mid
            else:
                left = mid + 1
        return left
