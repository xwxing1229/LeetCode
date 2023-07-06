# https://leetcode.cn/problems/k-items-with-the-maximum-sum/

class Solution:
    def kItemsWithMaximumSum(self, numOnes, numZeros, numNegOnes, k):
        """
        Inputs:
            numOnes, numZeros, numNegOnes, k: int
        Outputs:
            res: int
        """
        res = 0
        tmp = min(numOnes, k)
        res += tmp
        k -= tmp
        if k:
            tmp = min(numZeros, k)
            k -= tmp
        if k:
            tmp = min(numNegOnes, k)
            res -= tmp
            k -= tmp
        return res