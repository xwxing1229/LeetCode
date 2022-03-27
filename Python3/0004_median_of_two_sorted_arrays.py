# https://leetcode-cn.com/problems/median-of-two-sorted-arrays

# Refer to the official explanation.
class Solution():
    def findMedianSortedArrays(self, nums1, nums2):
        """
        Inputs:
            nums1: list[int]
            nums2: list[int]
        Outputs:
            res: float
        """
        
        if len(nums1) > len(nums2):
            tmp = nums1.copy()
            nums1 = nums2.copy()
            nums2 = tmp.copy()
        
        n1 = len(n1)
        n2 = len(n2)
        
        # An easy condition.
        if n1 == 0:
            mid = n2 // 2
            if n2 % 2 == 0:
                res = (nums2[mid+1] + nums2[mid]) / 2
            else:
                res = nums2[mid]
            return res
        
        i = n1 - 1 # pointer for nums1
        j = n2 - (n1 + n2) //2 - 1 # pointer for nums2
        # Adjust the splitting method.
        while i >= 0:
            if nums1[i] > nums2[j+1]:
                i = i - 1
                j = j + 1
            else:
                break
        
        # Boundary conditions.
        if i < 0:
            left_max = nums2[j]
            if j < n2 - 1:
                right_min = min(nums1[i+1], nums2[j+1])
            else:
                right_min = nums1[i+1]
        elif i == n1 - 1:
            right_min = nums2[j+1]
            if j < 0:
                left_max = nums1[i]
            else:
                left_max = max(nums1[i], nums2[j])
        else:
            left_max = max(nums1[i], nums2[j])
            right_min = min(nums1[i+1], nums2[j+2])
            
        if (n1 + n2) % 2 == 0:
            res = (left_max + right_min) / 2
        else:
            res = left_max
        return res