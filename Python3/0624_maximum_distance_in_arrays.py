# https://leetcode.cn/problems/maximum-distance-in-arrays/

class Solution:
    def maxDistance(self, arrays):
        """
        Inputs:
            arrays: list[list[int]]
        Outputs:
            res: int
        """

        # # Method 1.
        # min1, min1_idx = min(arrays[0][0], arrays[1][0]), 0
        # min2, min2_idx = max(arrays[0][0], arrays[1][0]), 1
        # if min1 != arrays[0][0]:
        #     min1_idx, min2_idx = 1, 0
        # max1, max1_idx = max(arrays[0][-1], arrays[1][-1]), 0
        # max2, max2_idx = min(arrays[0][-1], arrays[1][-1]), 1
        # if max1 != arrays[0][-1]:
        #     max1_idx, min2_idx = 1, 0
        # for i in range(2, len(arrays)):
        #     num_min, num_max = arrays[i][0], arrays[i][-1]
        #     if num_min <= min1:
        #         min2, min2_idx = min1, min1_idx
        #         min1, min1_idx = num_min, i
        #     elif num_min < min2:
        #         min2, min2_idx = num_min, i
        #     if num_max >= max1:
        #         max2, max2_idx = max1, max1_idx
        #         max1, max1_idx = num_max, i
        #     elif num_max > max2:
        #         max2, max2_idx = num_max, i
        
        # res = max1 - min1
        # if max1_idx == min1_idx:
        #     res = max(max1-min2, abs(max2-min1))
        # return res
        
        # Method 2.
        res = 0
        min_, max_ = arrays[0][0], arrays[0][-1]
        for i in range(1, len(arrays)):
            min_i, max_i = arrays[i][0], arrays[i][-1]
            res = max(res, max_i-min_, max_-min_i)
            min_ = min(min_, min_i)
            max_ = max(max_, max_i)
        return res