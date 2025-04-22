# https://leetcode.cn/problems/count-good-triplets/

class Solution:
    def countGoodTriplets(self, arr, a, b, c):
        """
        Inputs:
            arr: list[int]
            a, b, c: int
        Outputs:
            res: int
        """
        res, n = 0, len(arr)
        for i in range(n):
            num_i = arr[i]
            for j in range(i+1, n):
                num_j = arr[j]
                if num_i - num_j > a or num_j - num_i > a:
                    continue
                for k in range(j+1, n):
                    num_k = arr[k]
                    if num_j - num_k > b or num_k - num_j > b \
                        or num_i - num_k > c or num_k - num_i > c:
                        continue
                    res += 1
        return res