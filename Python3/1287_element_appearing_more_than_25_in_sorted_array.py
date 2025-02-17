# https://leetcode.cn/problems/element-appearing-more-than-25-in-sorted-array/

class Solution:
    def findSpecialInteger(self, arr):
        """
        Inputs:
            arr: list[int]
        Outputs:
            res: int
        """
        res = arr[0]
        n, cnt_min = len(arr), len(arr)//4+1
        start, cnt = 0, 1
        while cnt < cnt_min:
            tar = arr[start]
            left, right = start, n-1
            while left <= right:
                mid = left + (right - left) // 2
                if arr[mid] <= tar:
                    left = mid + 1
                else:
                    right = mid - 1
            cnt = right - start + 1
            res = arr[right]

            start = right + 1
        
        return res