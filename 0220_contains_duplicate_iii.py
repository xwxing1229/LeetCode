# https://leetcode-cn.com/problems/contains-duplicate-iii/

class Solution:
    def containsNearbyAlmostDuplicate(self, nums, k, t):
        """
        Inputs:
            nums: list[int]
            k: int
            t: int
        Outputs:
            res: bool
        """
        
        # We want to know if there exist i and j such that
        # 1. nums[i]-t <= nums[j] <= nums[i]+t; and
        # 2. |i-j| <= k.
        
        # We maintain a window of length k+1, where the elements are
        # sorted.
        # We first check if there exists an element a in the window such
        # that nums[i]-t <= a.
        # If such an a exists, we then check if a <= nums[i]+t.
        
        window = []
        
        for i in range(len(nums)):
            # Remove the first element in the window.
            # Now the length of the window is <= k.
            if i > k:
                window.remove(nums[i-k-1])
            
            # Find the index of the element which is >= nums[i]-t and is
            # closest to nums[i]-t.
            idx = bisect.bisect_left(window, nums[i]-t)
            if window and idx < len(window) and window[idx]-nums[i] <= t:
                return True
            
            # Insert nums[i].
            # Now the length of the window is <= k+1.
            idx = bisect.bisect_left(window, nums[i])
            window.insert(idx, nums[i])
        
        return False