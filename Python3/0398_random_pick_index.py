# https://leetcode.cn/problems/random-pick-index/

class Solution:

    def __init__(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            None
        """
        self.idxs = dict()
        for i, num in enumerate(nums):
            if num not in self.idxs:
                self.idxs[num] = [i]
            else:
                self.idxs[num].append(i)

    def pick(self, target):
        """
        Inputs:
            target: int
        Outputs:
            res: int
        """
        return self.idxs[target][random.randint(0, len(self.idxs[target])-1)]


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.pick(target)