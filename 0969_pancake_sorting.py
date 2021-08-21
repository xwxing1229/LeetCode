# https://leetcode-cn.com/problems/pancake-sorting/
class Solution:
    def pancakeSort(self, arr):
        """
        Inputs:
            arr: list[int]
        Outputs:
            res: list[int]
        """

        n = len(arr)
        max_ = n
        res = []
        for i in range(n):
            idx = arr.index(max_)
            if idx == max_ - 1:
                max_ = max_ - 1
                continue

            # Move the current maximum value to the first place.
            if idx != 0:
                tmp = arr[0: idx+1]
                tmp.reverse()
                arr = tmp + arr[idx+1: n]
                res.append(idx+1)

            # Move the current maximum value to the correct place.
            tmp = arr[0: max_]
            tmp.reverse()
            arr = tmp + arr[max_: n]
            res.append(max_)

            # Update the current maximum value.
            max_ = max_ - 1

        return res