# https://leetcode.cn/problems/split-array-with-same-average/

class Solution:
    def splitArraySameAverage(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: bool
        """
        n = len(nums)
        if n == 1:
            return False

        # nums[i] = nums[i] - avg: sum(nums) = 0.
        # nums[i] = (nums[i] - avg) * n: sum(nums) = 0.
        s = sum(nums)
        for i in range(n):
            nums[i] = nums[i] * n - s

        # Check if there is a subset sub1 of half1 and a subset sub2 of half2
        # s.t. sum(sub1) + sum(sub2) = 0.
        n1 =  n // 2
        half1 = nums[: n1]
        s1_set = set()
        for i in range(1, 1<<n1):
            sub1 = [num for k,num in enumerate(half1) if (i>>k) & 1 == 1]
            s1 = sum(sub1)
            if s1 == 0:
                return True
            s1_set.add(s1)

        half2 = nums[n1:]
        for i in range(1, 1<<(n-n1)):
            sub2 = [num for k,num in enumerate(half2) if (i>>k) & 1 == 1]
            s2 = sum(sub2)
            if s2 == 0 or ((-s2 in s1_set) and (i+1 != 1<<(n-n1))):
                return True
        return False