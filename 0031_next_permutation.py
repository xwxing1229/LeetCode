# https://leetcode-cn.com/problems/next-permutation/

class Solution:
    def nextPermutation(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            None
        """
        
        """
        Do not return anything, modify nums in-place instead.
        """
        
        n = len(nums)
        i, j = n-2, n-1
        flag = False
        while i >= 0 :
            if nums[i] < nums[j]:
                flag = True
                break
            else:
                i = i - 1
                j = j - 1
        
        if not flag:
            nums.sort()
        else:
            k = n - 1
            while k >= j:
                if nums[k] > nums[i]:
                    nums[i], nums[k] = nums[k], nums[i]
                    # Sort nums[j:n].
                    for idx in range((n-j)//2):
                        nums[j+idx], nums[n-1-idx] = nums[n-1-idx], nums[j+idx]
                    break
                else:
                    k = k - 1