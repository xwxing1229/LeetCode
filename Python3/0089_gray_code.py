# https://leetcode.cn/problems/gray-code/

class Solution:
    def grayCode(self, n):
        """
        Inputs:
            n: int
        Outputs:
            res: list[int]
        """

        res = [0]
        tmp = 1
        for i in range(n):            
            for j in range(len(res)-1, -1, -1):
                res.append(res[j] + tmp)

            tmp = tmp << 1
        return res
