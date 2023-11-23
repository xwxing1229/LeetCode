# https://leetcode.cn/problems/form-smallest-number-from-two-digit-arrays/

class Solution:
    def minNumber(self, nums1, nums2):
        """
        Inputs:
            nums1, nums2: list[int]
        Outputs:
            res: int
        """
        a, b, c = nums1[0], nums2[0], 10
        check = [0 for _ in range(10)]
        for num in nums1:
            a = min(a, num)
            check[num] = 1
        for num in nums2:
            b = min(b, num)
            if check[num]:
                c = min(c, num)
        if c < 10:
            return c
        elif a == b:
            return a
        else:
            return 10*a+b if a < b else 10*b+a