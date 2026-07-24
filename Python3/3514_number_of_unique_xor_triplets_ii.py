# https://leetcode.cn/problems/number-of-unique-xor-triplets-ii/

class Solution:
    def uniqueXorTriplets(self, nums: list[int]) -> int:
        n, mx = len(nums), max(nums)
        u = 1
        while u <= mx:
            u <<= 1

        ab = [0 for _ in range(u)]
        for i in range(n):
            for j in range(i, n):
                ab[nums[i] ^ nums[j]] = 1
                
        abc = [0 for _ in range(u)]
        for num, exist in enumerate(ab):
            if exist:
                for c in nums:
                    abc[num ^ c] = 1
        return sum(abc)