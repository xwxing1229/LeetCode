# https://leetcode.cn/problems/number-of-different-subsequences-gcds/

class Solution:
    def countDifferentSubsequenceGCDs(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """
        max_ = max(nums)
        occured = [False for _ in range(max_+1)]
        for num in nums:
            occured[num] = True
        res = 0
        for i in range(1, max_+1):
            sub_gcd = 0
            for j in range(i, max_+1, i):
                if occured[j]:
                    if sub_gcd == 0:
                        sub_gcd = j
                    else:
                        sub_gcd = gcd(sub_gcd, j)
                    if sub_gcd == i:
                        res += 1
                        break
        return res