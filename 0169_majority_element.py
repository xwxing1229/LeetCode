# https://leetcode-cn.com/problems/majority-element/

class Solution:
    def majorityElement(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """
        
        '''
        times = {}
        for i in nums:
            times[i] = times.get(i,0) + 1
        res = max(times, key=times.get)
        return res
        '''
        
        # Boyer-Moore Majority Vote Algorithm.
        count = 0
        for i in nums:
            if count == 0:
                res = i
            if res == i:
                count = count + 1
            else:
                count = count - 1
        return res