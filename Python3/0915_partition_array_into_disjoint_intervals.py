# https://leetcode.cn/problems/partition-array-into-disjoint-intervals/

class Solution:
    def partitionDisjoint(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """

        n = len(nums)
        mins = [nums[n-1] for _ in range(n)]
        for i in range(n-2, -1, -1):
            if nums[i] < mins[i+1]:
                mins[i] = nums[i]
            else:
                mins[i] = mins[i+1]

        cur_max = nums[0]
        for i in range(1, n):
            if cur_max <= mins[i]:
                return i
            
            if cur_max < nums[i]:
                cur_max = nums[i]
        return 0

sol = Solution()
nums = [1,1,1,0,6,12]
print(sol.partitionDisjoint(nums))