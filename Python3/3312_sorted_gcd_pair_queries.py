# https://leetcode.cn/problems/sorted-gcd-pair-queries/

class Solution:
    def gcdValues(self, nums: list[int], queries: list[int]) -> list[int]:
        mx = max(nums)
        cnt_num = [0 for _ in range(mx+1)]
        for num in nums:
            cnt_num[num] += 1

        cnt_gcd = [0 for _ in range(mx+1)]
        for gcd_ in range(mx, 0, -1):
            cnt = 0
            for num in range(gcd_, mx+1, gcd_):
                cnt += cnt_num[num]
                cnt_gcd[gcd_] -= cnt_gcd[num] # exclude 2*gcd, 3*gcd, ...
            cnt_gcd[gcd_] += cnt * (cnt - 1) // 2
        
        cumsum = [cnt for cnt in cnt_gcd]
        for i in range(1, mx+1):
            cumsum[i] = cumsum[i-1] + cnt_gcd[i]
        
        res = [0 for _ in range(len(queries))]
        for i, q in enumerate(queries):
            left, right = 0, mx
            while left <= right:
                mid = (left + right) // 2
                if cumsum[mid] > q:
                    res[i] = mid
                    right = mid - 1
                else:
                    left = mid + 1
        return res