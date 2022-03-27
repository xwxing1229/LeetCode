# https://leetcode-cn.com/problems/find-k-closest-elements/

class Solution:
    def findClosestElements(self, arr, k, x):
        """
        Inputs:
            arr: list[int]
            k: int
            x: int
        Outputs:
            res: list[int]
        """
        
        l = 0
        r = len(arr) - 1
        while r - l >= k:
            tmp1 = abs(arr[l] - x)
            tmp2 = abs(arr[r] - x)
            if tmp1 <= tmp2:
                r = r - 1
            else:
                l = l + 1
        
        res = arr[l: r+1]
        return res