# https://leetcode.cn/problems/check-if-binary-string-has-at-most-one-segment-of-ones/

class Solution:
    def checkOnesSegment(self, s):
        """
        Inputs:
            s: str
        Outputs:
            res: bool
        """
        start_to_check_1 = False
        for ch in s:
            if ch == "0":
                start_to_check_1 = True
            elif start_to_check_1:
                return False
        return True