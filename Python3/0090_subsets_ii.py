# https://leetcode.cn/problems/subsets-ii/

class Solution:
    def subsetsWithDup(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: list[list[int]]
        """

        nums.sort()
        self.res = []
        check = [0 for _ in range(n)]
        self.backtrack(nums, [], check, 0)
        return self.res

    def backtrack(self, nums, tmp, check, idx):
        self.res.append(tmp)

        for i in range(idx, len(nums)):
            if i > 0 and nums[i] == nums[i-1] and not check[i-1]:
                continue

            check[i] = 1
            self.backtrack(nums, tmp+[nums[i]], check, i+1)
            check[i] = 0