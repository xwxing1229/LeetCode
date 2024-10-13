# https://leetcode.cn/problems/find-the-number-of-good-pairs-i/

class Solution:
    def numberOfPairs(self, nums1, nums2, k):
        """
        Inputs:
            nums1, nums2: list[int]
            k: int
        Outputs:
            res: int
        """
        res = 0
        for i in range(len(nums1)):
            num1 = nums1[i]
            if num1 % k != 0:
                continue
            num1 //= k
            for num2 in nums2:
                if num1 % num2 == 0:
                    res += 1
        return res