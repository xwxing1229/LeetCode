# https://leetcode.cn/problems/two-out-of-three/

class Solution:
    def twoOutOfThree(self, nums1, nums2, nums3):
        """
        Inputs:
            nums1, nums2, nums3: list[int]
        Outputs:
            res: list[int]
        """
        s1, s2, s3 = set(nums1), set(nums2), set(nums3)
        inter1 = s1.intersection(s2)
        inter2 = s2.intersection(s3)
        inter3 = s3.intersection(s1)
        res = list(inter1.union(inter2, inter3))
        return res