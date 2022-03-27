# https://leetcode-cn.com/problems/bag-of-tokens/

class Solution:
    def bagOfTokensScore(self, tokens, power):
        """
        Inputs:
            tokens: list[int]
            power: int
        Outputs:
            res: int
        """
        
        if len(tokens) == 0:
            return 0
        
        tokens.sort()
        l = 0
        r = len(tokens) - 1
        res = 0
        while l < r:
            if power >= tokens[l]:
                power = power - tokens[l]
                l =l + 1
                res = res + 1
            elif res > 0:
                power = power + tokens[r]
                r = r - 1
                res = res - 1
            else:
                break
        
        if power >= tokens[l]:
            res = res + 1
        return res