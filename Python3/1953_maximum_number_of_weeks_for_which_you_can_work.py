# https://leetcode.cn/problems/maximum-number-of-weeks-for-which-you-can-work/

class Solution:
    def numberOfWeeks(self, milestones):
        """
        Inputs:
            milestones: list[int]
        Outputs:
            res: int
        """
        longest = max(milestones)
        rest = sum(milestones) - longest
        return 2*rest+1 if longest > rest+1 else longest+rest