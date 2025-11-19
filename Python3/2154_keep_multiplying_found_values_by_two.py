# https://leetcode.cn/problems/keep-multiplying-found-values-by-two/

class Solution:
    def findFinalValue(self, nums: list[int], original: int) -> int:
        nums.sort()
        for num in nums:
            if num == original:
                original *= 2
                if original > nums[-1]:
                    break
        return original