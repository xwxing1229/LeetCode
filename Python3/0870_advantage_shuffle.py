# https://leetcode.cn/problems/advantage-shuffle/

class Solution:
    def advantageCount(self, nums1, nums2):
        """
        Inputs:
            nums1: list[int]
            nums2: list[int]
        Outputs:
            res: list[int]
        """

        n = len(nums1)
        idx1 = [i for i in range(n)]
        idx2 = [i for i in range(n)]
        idx1.sort(key = lambda x: nums1[x])
        idx2.sort(key = lambda x: nums2[x])

        res = [0 for i in range(n)]
        left, right = 0, n-1
        for i in idx1:
            if nums1[i] > nums2[idx2[left]]:
                res[idx2[left]] = nums1[i]
                left = left + 1
            else:
                res[idx2[right]] = nums1[i]
                right = right - 1
        return res