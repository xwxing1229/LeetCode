# https://leetcode.cn/problems/triples-with-bitwise-and-equal-to-zero/

class Solution:
    def countTriplets(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """
        cnt = defaultdict(int)
        for i in range(len(nums)):
            for j in range(len(nums)):
                cnt[nums[i] & nums[j]] += 1
        
        res = 0
        for num in nums:
            for k, v in cnt.items():
                if num & k == 0:
                    res += v
        return res