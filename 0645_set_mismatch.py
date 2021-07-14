# https://leetcode-cn.com/problems/set-mismatch/
class Solution:
    def findErrorNums(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: list[int]
        """

        count = {}
        res = []
        for i in nums:
            count[i] = count.get(i,0) + 1
            if count[i] == 2:
                repeat = i
                res.append(i)
                break

        n = len(nums)
        miss = n*(n+1)//2 + repeat - sum(nums)
        res.append(miss)
        return res