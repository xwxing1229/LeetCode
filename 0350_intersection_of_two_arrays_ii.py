# https://leetcode-cn.com/problems/intersection-of-two-arrays-ii/

class Solution:
    def intersect(self, nums1, nums2):
        """
        Inputs:
            nums1: list[int]
            nums2: list[int]
        Outputs:
            res: list[int]
        """

        n1 = len(nums1)
        n2 = len(nums2)
        if n2 < n1:
            nums1, nums2 = nums2, nums1

        # Check the numbers in nums1 and how many times they occur.
        count = {}
        for i in nums1:
            count[i] = count.get(i,0) + 1

        res = []
        for i in nums2:
            if count.get(i):
                res.append(i)
                count[i] = count[i] - 1

        return res