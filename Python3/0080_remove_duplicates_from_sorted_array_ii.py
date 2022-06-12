# https://leetcode.cn/problems/combinations/

class Solution:
    def removeDuplicates(self, nums):
        """
        Inputs:
            n: list[int]
        Outputs:
            res: int
        """

        cnt = 1
        idx = 1
        val = nums[0]
        for i in range(1, n):
            if nums[i] == val:
                cnt = cnt + 1
                if cnt < 3:
                    nums[idx] = nums[i]
                    idx = idx + 1
            else:
                nums[idx] = nums[i]
                cnt = 1
                idx = idx + 1
                val = nums[i]
        return res
