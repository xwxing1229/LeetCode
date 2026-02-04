# https://leetcode.cn/problems/trionic-array-ii/

class Solution:
    def maxSumTrionic(self, nums: list[int]) -> int:
        res = 0
        init = False
        n, l = len(nums), 0
        while l < n:
            p, q, r = l, l, l
            for i in range(l+1, n):
                if nums[i] > nums[i-1]:
                    p = i
                else:
                    break
            for i in range(p+1, n):
                if nums[i] < nums[i-1]:
                    q = i
                else:
                    break
            for i in range(q+1, n):
                if nums[i] > nums[i-1]:
                    r = i
                else:
                    break
            if p == l:
                l += 1
                continue
            elif q == l or r == l:
                l = p + 1
                continue
            
            # dp[i]: maximum sum of subarray that ends with nums[l+i].
            dp = [nums[l] for _ in range(p-l)]
            for i in range(1, p-l):
                dp[i] = max(dp[i-1]+nums[l+i], nums[l+i])
            curr = dp[-1] + sum(nums[p: q+1])
            cumsum, tmp = nums[q+1], nums[q+1]
            for i in range(q+2, r+1):
                cumsum += nums[i]
                tmp = max(tmp, cumsum)
            curr += tmp
            
            if not init or res < curr:
                res = curr
                init = True
            
            l = q
        
        return res