# https://leetcode.cn/problems/previous-permutation-with-one-swap/

class Solution:
    def prevPermOpt1(self, arr):
        """
        Inputs:
            arr: list[int]
        Outputs:
            res: list[int]
        """
        n = len(arr)
        left, right = -1, -1
        for i in range(n-2, -1, -1):
            if arr[i] > arr[i+1]:
                left = i
                break
        if left == -1:
            return arr

        # Find the maximum number in arr[left+1:] which is less than arr[left].
        max_ = 0
        for i in range(left+1, n):
            if arr[left] > arr[i] and arr[i] > max_:
                max_ = arr[i]
                right = i
        arr[left], arr[right] = arr[right], arr[left]
        return arr

sol = Solution()
arr = [1,9,4,6,7] # [1,7,4,6,9]
print(sol.prevPermOpt1(arr))
