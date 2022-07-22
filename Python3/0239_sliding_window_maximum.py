# https://leetcode.cn/problems/sliding-window-maximum/

class Solution:
    def maxSlidingWindow(self, nums, k):
        """
        Inputs:
            nums: list[int]
            k: int
        Outputs:
            res: list[int]
        """
        
        # # Indexes of a decreasing sequence are recorded in queue.
        # queue = []
        # res = []
        # for i in range(len(nums)):
        #     # While the number corresponding to the last element
        #     # of queue is less than or equal to nums[i], remove the
        #     # index of this number, which is queue[-1].
        #     while queue and nums[queue[-1]] <= nums[i]:
        #         queue.pop()
        #     queue.append(i)
            
        #     # If the leftmost element in queue is out of the current
        #     # window, remove this element, which is queue[0].
        #     while queue and queue[0] < i - k + 1:
        #         queue.pop(0)
            
        #     # Add the largest value of the current window to res,
        #     # starting from i = k - 1.
        #     if i >= k - 1:
        #         res.append(nums[queue[0]])
        # return res


        # res = []
        # window = []
        # for i in range(k):
        #     heapq.heappush(window, (-nums[i], i))
        # res.append(-window[0][0])

        # for i in range(k, len(nums)):
        #     heapq.heappush(window, (-nums[i], i))
        #     while (i-k+1 > window[0][1]):
        #         heapq.heappop(window)

        #     res.append(-window[0][0])
        # return res


        res = []
        deq = [] # deq saves indices
        for i in range(k):
            while (deq) and (nums[deq[-1]] <= nums[i]):
                deq.pop()
            deq.append(i)

        res.append(nums[deq[0]])

        for i in range(k, len(nums)):
            while (deq) and (nums[deq[-1]] <= nums[i]):
                deq.pop()
            deq.append(i)

            while i-k+1 > deq[0]:
                deq.pop(0)

            res.append(nums[deq[0]])
        return res