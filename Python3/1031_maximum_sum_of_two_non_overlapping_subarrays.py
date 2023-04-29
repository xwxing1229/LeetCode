# https://leetcode.cn/problems/maximum-sum-of-two-non-overlapping-subarrays/

class Solution:
    def maxSumTwoNoOverlap(self, nums, firstLen, secondLen):
        """
        Inputs:
            nums: list[int]
            firstLen, secondLen: int
        Outputs:
            res: int
        """
        n = len(nums)
        # max_first[i]: max(nums[j-firstLen+1] + ... + nums[j]) for j = firstLen-1, ..., i
        # max_second[i]: max(nums[j-secondLen+1] + ... + nums[j]) for j = secondLen-1, ..., i
        max_first, max_second = [0 for _ in range(n)], [0 for _ in range(n)]
        s_first, s_second = 0, 0
        cum_sum = [0 for _ in range(n+1)]
        for i in range(n):
            s_first += nums[i]
            s_second += nums[i]
            if i >= firstLen - 1:
                max_first[i] = s_first
                s_first -= nums[i - firstLen + 1]
                if i > firstLen - 1 and max_first[i] < max_first[i-1]:
                    max_first[i] = max_first[i-1]

            if i >= secondLen - 1:
                max_second[i] = s_second
                s_second -= nums[i - secondLen + 1]
                if i > secondLen - 1 and max_second[i] < max_second[i-1]:
                    max_second[i] = max_second[i-1]
            
            cum_sum[i+1] = cum_sum[i] + nums[i]
        
        res = 0
        dp_first, dp_second = [0 for _ in range(n)], [0 for _ in range(n)]
        for i in range(firstLen + secondLen - 1, n):
            dp_first[i] = cum_sum[i+1] - cum_sum[i + 1 - firstLen] + max_second[i - firstLen]
            dp_second[i] = cum_sum[i+1] - cum_sum[i + 1 - secondLen] + max_first[i - secondLen]
            res = max(res, dp_first[i], dp_second[i])
        return res