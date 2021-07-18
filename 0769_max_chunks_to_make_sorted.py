# https://leetcode-cn.com/problems/max-chunks-to-make-sorted/
class Solution:
    def maxChunksToSorted(self, arr):
        """
        Inputs:
            arr: list[int]
        Outputs:
            res: int
        """

        max_ = 0
        res = 0
        for i in range(len(arr)):
            if max_ < arr[i]:
                max_ = arr[i]

            if max_ == i:
                res = res + 1

        return res