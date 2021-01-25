# https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/

class Solution:
    def twoSum(self, numbers, target):
        """
        Inputs:
            numbers: list[int]
            target: int
        Outputs:
            return list[int]
        """
        
        i = 0
        j = len(numbers) - 1
        while i < j:
            if numbers[i] + numbers[j] < target:
                i = i + 1
            elif numbers[i] + numbers[j] > target:
                j = j - 1
            else:
                break
        return [i+1,j+1]