# https://leetcode-cn.com/problems/sliding-window-maximum/

class Solution:
    def maxSlidingWindow(self, nums, k):
        """
        Inputs:
            nums: list[int]
            k: int
        Outputs:
            res: list[int]
        """
        
        # Indexes of a nondecreasing sequence are recorded
        # in queue.
        queue = []
        res = []
        
        n = len(nums)
        for i in range(n):
            # While the number corresponding to the last element
            # of queue is less than nums[i], remove the index of
            # this number, which is queue[-1].
            while queue and nums[queue[-1]] < nums[i]:
                queue.pop()
            queue.append(i)
            
            # If the leftmost element in queue is out of the current
            # window, remove this element, which is queue[0].
            if queue and queue[0] < i - k + 1:
                queue.pop(0)
            
            # Add the largest value of the current window to res,
            # starting from i = k - 1.
            if i >= k - 1:
                res.append(queue[0])
        return res