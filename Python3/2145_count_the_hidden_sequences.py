
# https://leetcode.cn/problems/count-the-hidden-sequences/

class Solution:
    def numberOfArrays(self, differences, lower, upper):
        """
        Inputs:
            differences: list[int]
            lower, upper: int
        Outputs:
            res: int
        """
        min_, max_, diff = 0, 0, 0
        for d in differences:
            diff += d
            min_ = min(min_, diff)
            max_ = max(max_, diff)
        
        return max(upper-lower-(max_-min_)+1, 0)