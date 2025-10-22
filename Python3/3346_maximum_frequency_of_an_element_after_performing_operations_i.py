# https://leetcode.cn/problems/maximum-frequency-of-an-element-after-performing-operations-i/

class Solution:
    def maxFrequency(self, nums, k, numOperations):
        """
        Inputs:
            nums: list[int]
            k: int
            numOperations: int
        Outputs:
            res: int
        """
        mx = max(nums)
        cnt = [0 for _ in range(mx+1)]
        for num in nums:
            cnt[num] += 1
        # prefix[i]: how many numbers whose values are in [0, i].
        prefix = [0 for _ in range(mx+1)]
        prefix[0] = cnt[0]
        for i in range(1, mx+1):
            prefix[i] = prefix[i-1] + cnt[i]
        
        res = 0
        for tar in range(mx+1):
            cnt_original = cnt[tar]
            left = max(0, tar-k)
            right = min(mx, tar+k)
            if left == 0:
                total = prefix[right]
            else:
                total = prefix[right] - prefix[left-1]
            convert = min(numOperations, total-cnt_original)
            res = max(res, cnt_original+convert)
        return res
