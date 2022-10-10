# https://leetcode.cn/problems/minimum-swaps-to-make-sequences-increasing/

class Solution:
    def minSwap(self, nums1: List[int], nums2: List[int]) -> int:
        """
        Inputs:
            nums1: list[int]
            nums2: list[int]
        Outputs:
            res: int
        """

        # dp0: do not swap nums1[i] and nums2[i]
        # dp1: do swap nums1[i] and nums2[i]
        dp0, dp1 = 0, 1
        dp0_pre, dp1_pre = 0, 1
        for i in range(1, len(nums1)):
            num1, num1_pre = nums1[i], nums1[i-1]
            num2, num2_pre = nums2[i], nums2[i-1]
            if (num1 > num1_pre and num2 > num2_pre) and (num1 > num2_pre and num2 > num1_pre):
                dp0 = min(dp0_pre, dp1_pre)
                dp1 = min(dp0_pre, dp1_pre) + 1
            elif num1 > num1_pre and num2 > num2_pre:
                dp0 = dp0_pre
                dp1 = dp1_pre + 1
            else:
                dp0 = dp1_pre
                dp1 = dp0_pre + 1
            dp0_pre = dp0
            dp1_pre = dp1
        return min(dp0, dp1)