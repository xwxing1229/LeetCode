# https://leetcode.cn/problems/relocate-marbles/

class Solution:
    def relocateMarbles(self, nums, moveFrom, moveTo):
        """
        Inputs:
            nums, moveFrom, moveTo: list[int]
        Outputs:
            res: list[int]
        """
        res = set(nums)
        for i, pos_from in enumerate(moveFrom):
            res.remove(pos_from)
            res.add(moveTo[i])
        return sorted(list(res))