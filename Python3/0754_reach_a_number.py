# https://leetcode.cn/problems/reach-a-number/

class Solution:
    def reachNumber(self, target):
        """
        Inputs:
            target: int
        Outputs:
            res: int
        """
        if target < 0:
            target = -target
        
        # Find the smallest n s.t. 1 + 2 + ... + n >= target.
        n = ceil((sqrt(8 * target + 1) - 1) / 2)
        cur = n * (n + 1) // 2
        if (cur - target) % 2 == 0: # cur == target or (cur-target)%2 == 0
            return n
        else:
            return n + 1 + n%2