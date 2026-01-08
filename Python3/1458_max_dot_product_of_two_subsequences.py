# https://leetcode.cn/problems/max-dot-product-of-two-subsequences/

class Solution:
    def maxDotProduct(self, nums1: list[int], nums2: list[int]) -> int:
        # dp[i1+1][i2+1]: max dot product of the subsequences of
        # nums1[0, i1] (included) and nums2[0, i2] (included).
        # Three cases:
        #   1. Choose nums1[i1] and nums2[i2].
        #   2. Choose nums1[i1], do not choose nums2[i2].
        #   3. Choose nums2[i2], do not choose nums1[i1].
        n1, n2 = len(nums1), len(nums2)
        dp = [[float("-inf") for _ in range(n2+1)] for _ in range(n1+1)]
        for i1, num1 in enumerate(nums1):
            for i2, num2 in enumerate(nums2):
                dp[i1+1][i2+1] = max(max(dp[i1][i2], 0) + num1 * num2,
                                     dp[i1][i2+1],
                                     dp[i1+1][i2])
        return dp[n1][n2]