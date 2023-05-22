# https://leetcode.cn/problems/o8SXZn/

class Solution:
    def storeWater(self, bucket, vat):
        """
        Inputs:
            bucket, vat: List[int]
        Outputs:
            res: int
        """
        k_max = max(vat)
        if k_max == 0:
            return 0
        
        res = inf
        for k in range(1, k_max+1):
            t = 0
            for i in range(len(bucket)):
                t += max(0, (vat[i]+k-1)//k - bucket[i])
            res = min(res, k+t)
            if k >= res:
                break
        return res