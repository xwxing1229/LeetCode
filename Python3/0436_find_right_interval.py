# https://leetcode-cn.com/problems/find-right-interval/

class Solution:
    def findRightInterval(self, intervals):
        """
        Inputs:
            intervals: list[list[int]]
        Outputs:
            res: list[int]
        """

        # Binary search.

        n = len(intervals)
        res = [-1 for i in range(n)]

        mapping = {}
        for i in range(n):
            mapping[i] = intervals[i]

        # Sorting based on the first element of values of the dict.
        # mapping_sort = [(idx, []), (idx, []), ...]
        mapping_sort = sorted(mapping.items(), key=lambda x:x[1])

        for i in range(n-1):
            l = i
            r = n - 1
            while l <= r:
                m = (l + r) // 2
                if mapping_sort[i][1][1] <= mapping_sort[m][1][0]:
                    r = m - 1
                    res[mapping_sort[i][0]] = mapping_sort[m][0]
                else:
                    l = m + 1
        return res

        '''
        # Low efficiency.
        for i in range(n-1):
            for j in range(i,n):
                if mapping_sort[i][1][1] <= mapping_sort[j][1][0]:
                    res[mapping_sort[i][0]] = mapping_sort[j][0]
                    break
        return res
        '''