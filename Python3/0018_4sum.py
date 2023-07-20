# https://leetcode-cn.com/problems/4sum/

class Solution:
    def fourSum(self, nums, target):
        """
        Inputs:
            nums: list[int]
            target: int
        Outputs:
            res: list[list[int]]
        """
        
        res = []
        n = len(nums)
        nums.sort()
        for a in range(n-3):
            if a > 0 and nums[a] == nums[a-1]:
                continue
            if nums[a] + nums[a+1] + nums[a+2] + nums[a+3] > target:
                break
            if nums[a] + nums[n-3] + nums[n-2] + nums[n-1] < target:
                continue
            for b in range(a+1, n-2):
                if b > a+1 and nums[b] == nums[b-1]:
                    continue
                if nums[a] + nums[b] + nums[b+1] + nums[b+2] > target:
                    break
                if nums[a] + nums[b] + nums[n-2] + nums[n-1] < target:
                    continue
                cur = nums[a] + nums[b]
                c, d = b+1, n-1
                while c < d:
                    s = cur + nums[c] + nums[d]
                    if s == target:
                        res.append([nums[a], nums[b], nums[c], nums[d]])
                        while c+1 < d and nums[c+1] == nums[c]:
                            c += 1
                        while d-1 > c and nums[d-1] == nums[d]:
                            d -= 1
                        c += 1
                        d -= 1
                    elif s > target:
                        d -= 1
                    else:
                        c += 1
        return res
