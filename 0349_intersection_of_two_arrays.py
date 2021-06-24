# https://leetcode-cn.com/problems/intersection-of-two-arrays/

class Solution:
    def intersection(self, nums1, nums2):
        """
        Inputs:
            nums1: list[int]
            nums2: list[int]
        Outputs:
            res: list[int]
        """

        # Check elements in nums1.
        tmp = {}
        for i in nums1:
            if not tmp.get(i):
                tmp[i] = 1

        # Check if these elements are in nums2.
        res = []
        for i in nums2:
            if tmp.get(i):
                res.append(i)
                tmp[i] = 0

        return res