# https://leetcode.cn/problems/find-common-elements-between-two-arrays/

class Solution:
    def findIntersectionValues(self, nums1, nums2):
        """
        Inputs:
            nums1, nums2: list[int]
        Outputs:
            res: list[int]
        """
        s1, s2 = set(nums1), set(nums2)
        cnt1, cnt2 = 0, 0
        for num in nums1:
            if num in s2:
                cnt1 += 1
        for num in nums2:
            if num in s1:
                cnt2 += 1
        return [cnt1, cnt2]