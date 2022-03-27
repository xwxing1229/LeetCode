# https://leetcode-cn.com/problems/permutations/
class Solution:
    def permute(self, nums):
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
            res_tmp = self.permute(nums)
            res = []
            for i in range(len(res_tmp)):
                list_o = res_tmp[i] # the original list

                # Insert val at different locations.
                for j in range(len(list_o)+1):
                    list_c = list_o.copy()
                    list_c.insert(j, val)
                    res.append(list_c)

            return res