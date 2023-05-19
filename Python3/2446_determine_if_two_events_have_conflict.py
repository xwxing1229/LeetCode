# https://leetcode.cn/problems/determine-if-two-events-have-conflict/

class Solution:
    def haveConflict(self, event1, event2):
        """
        Inputs:
            event1, event2: list[str]
        Outputs:
            res: bool
        """
        def getTime(t):
            res = int(t[0:2]) * 60 + int(t[3:5])
            return res
        e1_start, e1_end = getTime(event1[0]), getTime(event1[1])
        e2_start, e2_end = getTime(event2[0]), getTime(event2[1])
        if e1_end < e2_start or e2_end < e1_start:
            return False
        else:
            return True