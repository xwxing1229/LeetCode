# https://leetcode.cn/problems/count-items-matching-a-rule/

class Solution:
    def countMatches(self, items, ruleKey:, ruleValue):
        """
        Inputs:
            items: list[list[str]]
            ruleKey: str
            ruleValue: str
        Outputs:
            res: int
        """
        rule = -1
        if ruleKey[0] == "t":
            rule = 0
        elif ruleKey[0] == "c":
            rule = 1
        else:
            rule = 2
        
        res = 0
        for i in items:
            if i[rule] == ruleValue:
                res += 1
        return res
