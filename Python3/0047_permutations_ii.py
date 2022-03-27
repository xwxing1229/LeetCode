# https://leetcode-cn.com/problems/permutations-ii/
class Solution:
    def permuteUnique(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: list[list[int]]
        """

        if len(nums) == 1:
            return [nums]
        else:
            val = nums.pop()
            res_tmp = self.permuteUnique(nums)
            res_set = set()
            for i in range(len(res_tmp)):
                list_o = res_tmp[i] # the original list

                # Insert val at different locations.
                for j in range(len(list_o)+1):
                    list_c = list_o.copy()
                    list_c.insert(j, val)
                    # A list cannot be added to a set since list objects
                    # are unhashable.
                    res_set.add(tuple(list_c))

            res = []
            for v in res_set:
                res.append(list(v))

            return res