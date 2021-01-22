# https://leetcode-cn.com/problems/merge-sorted-array/

class Solution:
    def merge(self, nums1, m, nums2, n):
        """
        Inputs:
            nums1: list[int]
            m: int
            nums2: list[int]
            n: int
        Outputs:
            None
        """
        
        """
        Do not return anything, modify nums1 in-place instead.
        """
        p1 = m - 1
        p2 = n - 1
        p3 = m + n - 1
        
        while p2 >= 0:
            if p1 >= 0 and nums1[p1] > nums2[p2]:
                nums1[p3] = nums1[p1]
                p1 = p1 - 1
            else:
                nums1[p3] = nums2[p2]
                p2 = p2 - 1
            p3 = p3 - 1