# https://leetcode-cn.com/problems/insert-interval/

class Solution:
    def insert(self, intervals, newInterval):
        """
        Inputs:
            intervals: list[list[int]]
            newInterval: list[int]
        Outputs:
            res: list[list[int]]
        """

        # Add newInterval into intervals and sort the intervals
        # based on their first elements.
        intervals.append(newInterval)
        intervals.sort()

        # Add the first interval into result.
        res = [intervals[0]]
        idx = 0
        right = intervals[0][1]

        for i in range(1, len(intervals)):
            # Merge the two intervals.
            if right >= intervals[i][0]:
                res[idx][1] = max(right, intervals[i][1])
            
            # Add the interval into result.
            else:
                res.append(intervals[i])
                idx = idx + 1

            right = res[idx][1]

        return res