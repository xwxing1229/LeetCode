# https://leetcode.cn/problems/two-best-non-overlapping-events/

class Solution:
    def maxTwoEvents(self, events: list[list[int]]) -> int:
        res = 0
        events.sort(key=lambda x: (x[1], -x[2]))
        stack = [(0,0)] # (end_time, value)
        for start, end, value in events:
            left, right = 0, len(stack)-1
            best = 0
            while left <= right:
                mid = left + (right - left) // 2
                if stack[mid][0] < start:
                    best = mid
                    left = mid + 1
                else:
                    right = mid - 1
            res = max(res, value + stack[best][1])
            if value > stack[-1][1]:
                stack.append((end, value))
        return res