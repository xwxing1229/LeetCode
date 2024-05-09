# https://leetcode.cn/problems/watering-plants-ii/

class Solution:
    def minimumRefill(self, plants, capacityA, capacityB):
        """
        Inputs:
            plants: list[int]
            capacityA, capacityB: int
        Outputs:
            res: int
        """
        res = 0
        left, right = 0, len(plants)-1
        curA, curB = capacityA, capacityB
        while left < right:
            if curA >= plants[left]:
                curA -= plants[left]
            else:
                curA = capacityA - plants[left]
                res += 1

            left += 1
            if curB >= plants[right]:
                curB -= plants[right]
            else:
                curB = capacityB - plants[right]
                res += 1
            right -= 1
        if left == right and max(curA, curB) < plants[left]:
            res += 1
        return res