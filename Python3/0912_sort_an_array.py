# https://leetcode.cn/problems/sort-an-array/

class Solution:
    def sortArray(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: list[int]
        """
        n = len(nums)
        self.res = [0 for _ in range(n)]
        for i in range(n):
            self.res[i] = nums[i]
        self.mergeSorted(nums, 0, n-1)
        return self.res

    def mergeSorted(self, nums, left, right):
        if left >= right:
            return

        mid = left + (right - left) // 2
        self.mergeSorted(nums, left, mid)
        self.mergeSorted(nums, mid+1, right)
        self.mergeTwoSorted(nums, left, mid, right)

    def mergeTwoSorted(self, nums, left, mid, right):
        # Similar to #0088.
        if self.res[mid] <= self.res[mid+1]:
            return
            
        for i in range(left, right+1):
            nums[i] = self.res[i]

        i1 = mid
        i2 = right
        for idx in range(right, left-1, -1):
            if i2 <= mid:
                return
            elif (i1 >= left) and (self.res[i1] > nums[i2]):
                self.res[idx] = self.res[i1]
                i1 = i1 - 1
            else:
                self.res[idx] = nums[i2]
                i2 = i2 - 1
