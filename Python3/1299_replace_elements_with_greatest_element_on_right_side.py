# https://leetcode.cn/problems/replace-elements-with-greatest-element-on-right-side/

class Solution:
    def replaceElements(self, arr):
        """
        Inputs:
            arr: list[int]
        Outputs:
            res: int
        """
        max_right = -1
        for i in range(len(arr)-1, -1, -1):
            tmp = arr[i]
            arr[i] = max_right
            max_right = max(max_right, tmp)
        return arr