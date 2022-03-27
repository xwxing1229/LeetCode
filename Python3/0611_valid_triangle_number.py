# https://leetcode-cn.com/problems/valid-triangle-number/
class Solution:
    def triangleNumber(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """

        nums.sort()
        n = len(nums)
        res = 0
        for i in range(n-2):
            num_i = nums[i]
            for j in range(i+1, n-1):
                num_j = nums[j]

                l = j + 1
                r = n - 1
                while l < r:
                    m = (l + r) // 2
                    if num_i + num_j > nums[m]:
                        l = m + 1
                    else:
                        r = m - 1

                if num_i + num_j > nums[l]:
                    res = res + l - j
                else:
                    res = res + l - j - 1

        return res