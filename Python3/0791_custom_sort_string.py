# https://leetcode-cn.com/problems/custom-sort-string/

class Solution:
    def customSortString(self, order, s):
        """
        Inputs:
            order: str
            s: str
        Outputs:
            res: str
        """
        
        count = {}
        for i in s:
            count[i] = count.get(i,0) + 1
            
        res = []
        for i in order:
            if i in count:
                res.extend([i * count[i]])
                count.pop(i)
        
        for k,v in count.items():
            res.extend([k * v])
        
        return ''.join(res)