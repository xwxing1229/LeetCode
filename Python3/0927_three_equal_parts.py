# https://leetcode.cn/problems/three-equal-parts/

class Solution:
    def threeEqualParts(self, arr):
        """
        Inputs:
            arr: list[int]
        Outputs:
            res: list[int]
        """

        sum_arr = sum(arr)
        if sum_arr % 3 != 0:
            return [-1,-1]
        partial = int(sum_arr / 3)

        n = len(arr)
        cnt = 0
        first, second, third = 0, 1, n-1
        for i in range(n):
            if arr[i] == 1:
                cnt = cnt + 1

                if cnt == 1:
                    first = i
                elif cnt == 1 + partial:
                    second = i
                elif cnt == 1 + partial * 2:
                    third = i
                    break

        length = n - third
        if (first + length <= second) and (second + length <= third):
            # Check if (sub1 == sub2) and (sub2 == sub3).
            for i in range(length):
                if (arr[first+i] != arr[second+i]) or (arr[second+i] != arr[third+i]):
                    return [-1, -1]
            return [first+length-1, second+length]
        return [-1,-1]

