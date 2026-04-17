# https://leetcode.cn/problems/minimum-absolute-distance-between-mirror-pairs/

class Solution:
    def minMirrorPairDistance(self, nums: list[int]) -> int:
        def computeMirror(num: int) -> int:
            res = 0
            while num > 0:
                res = res * 10 + num % 10
                num //= 10
            return res
        
        res = len(nums)
        target = dict()
        for i, num in enumerate(nums):
            if num in target:
                res = min(res, i - target[num])
            
            target[computeMirror(num)] = i
            
        return res if res < len(nums) else -1