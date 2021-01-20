# https://leetcode-cn.com/problems/maximum-subarray/

# Let res[i] denote the maximum sum of subarraies that stop at nums[i].
# Then we have:
# res[0] = nums[0],
# res[1] = max(res[0]+nums[1], nums[1]),
# res[2] = max(res[1]+nums[2], nums[2])....
# Finally, we extract the maximum value in res.

class Solution:
    def maxSubArray(self, nums:List[int]) -> int:
        res = [nums[0]]
        for i in range(1,len(nums)):
            res.append(max(res[i-1]+nums[i], nums[i]))
        return max(res)
