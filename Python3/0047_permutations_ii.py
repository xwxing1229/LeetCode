# https://leetcode.cn/problems/permutations-ii/

class Solution:
    def permuteUnique(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: list[list[int]]
        """

        def dfs(cur):
            if len(cur) == n:
                res.append(cur)
            for i, num in enumerate(nums):
                if i > 0 and num == nums[i-1] and (not check[i-1]):
                    continue
                elif check[i]:
                    continue
                check[i] = 1
                dfs(cur+[num])
                check[i] = 0

        res = []
        n = len(nums)
        nums.sort()
        check = [0 for _ in range(n)]
        dfs([])
        return res