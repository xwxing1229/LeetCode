# https://leetcode-cn.com/problems/fair-candy-swap/
class Solution:
    def fairCandySwap(self, aliceSizes, bobSizes):
        """
        Inputs:
            aliceSizes: list[int]
            bobSizes: list[int]
        Outputs:
            res: list[int]
        """

        diff = (sum(aliceSizes) - sum(bobSizes)) // 2

        # Convert a list to a set for speedup.
        set_bob = set(bobSizes)
        for i in aliceSizes:
            if i - diff in set_bob:
                return [i, i-diff]