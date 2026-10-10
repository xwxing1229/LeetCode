# https://leetcode.cn/problems/minimum-sum-of-squared-difference/

class Solution:
    def minSumSquareDiff(self, nums1: list[int], nums2: list[int], k1: int, k2: int) -> int:
        n = len(nums1)
        diff = [abs(nums1[i] - nums2[i]) for i in range(n)]
        diff.sort(reverse=True)
        diff.append(0)

        res = 0
        k = k1 + k2
        val = diff[0]
        i, val = 0, diff[0]
        while i < n:
            need = (diff[i] - diff[i+1]) * (i + 1)
            if need <= k:
                # (i+1) numbers can be updated to val.
                k -= need
                val = diff[i+1]
                i += 1
            else:
                d = k // (i + 1)
                r = k % (i + 1)
                # (i+1-r) numbers can be updated to (val-d),
                # and (r) numbers can be updated to (val-d-1).
                res = (val - d) ** 2 * (i + 1 - r) \
                    + (val - d - 1) ** 2 * r
                break
        for idx in range(i+1, n):
            res += diff[idx] ** 2
        return res