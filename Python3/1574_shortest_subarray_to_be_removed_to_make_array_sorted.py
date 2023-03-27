# https://leetcode.cn/problems/shortest-subarray-to-be-removed-to-make-array-sorted/

class Solution:
    def findLengthOfShortestSubarray(self, arr):
        """
        Inputs:
            arr: list[int]
        Outputs:
            res: int
        """
        self.arr = arr
        n, i = len(arr), 0
        res = 0
        while i < n:
            if i + 1 < n and arr[i] > arr[i+1]:
                j = self.checkBackward(n-1, i, arr[i]) # keep arr[0], ...,  arr[i]
                res = j - i
                
                while i > 0: # keep arr[0], ..., arr[k] with 0 < k < i
                    j = self.checkBackward(j, i-1, arr[i-1])
                    res = min(res, j-i+1)
                    i -= 1
                j = self.checkBackward(j, 0, 0) # not keep arr[0]
                res = min(res, j+1)
                break

            i += 1
        return res
    
    def checkBackward(self, j, i, start):
        n = len(self.arr)
        while self.arr[j] >= start and (j == n-1 or (j >= i and j < n-1 and self.arr[j] <= self.arr[j+1])):
            j -= 1
        return j
