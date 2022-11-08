# https://leetcode.cn/problems/circular-array-loop/

class Solution:
    def circularArrayLoop(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: bool
        """
        # If a position is visited, label it by directly chaning the
        # corresponding number in the original array.
        n = len(nums)
        flag = 2000 * n # -1000 <= nums[i] <= 1000
        for i in range(n):
            # Only consider unvisited positive numbers.
            if nums[i] >= 2000 or nums[i] < 0:
                continue
            j, circular = i, 0
            while nums[j] > 0:
                cur, step = j, nums[j]
                nums[j] = flag # label the jth position
                circular += 1
                j = (j + step) % n
                if nums[j] == flag:
                    if circular > 1 and j != cur:
                        return True
                    break
            flag += n
            
        flag = -2000 * n
        for i in range(n):
            # Only consider unvisited negative numbers.
            if nums[i] <= -2000 or nums[i] > 0:
                continue
            j, circular = i, 0
            while nums[j] < 0:
                cur, step = j, nums[j]
                nums[j] = flag
                circular += 1
                # Notice the difference of modulo operators in different
                # programming languages.
                j = (j + step) % n
                if nums[j] == flag:
                    if circular > 1 and j != cur:
                        return True
                    break
            flag -= n
            
        return False

        # Another solution is based on fast and slow pointers.
        # Check details in the solution section on LeetCode.