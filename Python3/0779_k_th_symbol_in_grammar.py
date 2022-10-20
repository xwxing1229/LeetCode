# https://leetcode.cn/problems/k-th-symbol-in-grammar/

class Solution:
    def kthGrammar(self, n, k):
        """
        Inputs:
            n: int
            k: int
        Outputs:
            res: int
        """

        if n == 1:
            return 0
        
        tmp = (1 << (n-2))
        if k <= tmp:
            return self.kthGrammar(n-1, k)
        else:
            return 1 - self.kthGrammar(n-1, k-tmp)