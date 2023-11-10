# https://leetcode.cn/problems/single-number-iii/

class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: list[int]
        """
        xor_all = nums[0]
        for i in range(1, len(nums)):
            xor_all ^= nums[i]

        low_bit = xor_all & (-xor_all)

        res = [0, 0]
        for num in nums:
            res[(num & low_bit) != 0] ^= num
        return res