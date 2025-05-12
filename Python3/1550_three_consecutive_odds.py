# https://leetcode.cn/problems/three-consecutive-odds/

class Solution:
    def threeConsecutiveOdds(self, arr):
        """
        Inputs:
            arr: list[int]
        Outputs:
            res: bool
        """
        for i in range(1, len(arr)-1):
            if arr[i-1] % 2 and arr[i] % 2 and arr[i+1] % 2:
                return True
        return False