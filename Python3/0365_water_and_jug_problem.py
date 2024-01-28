# https://leetcode.cn/problems/water-and-jug-problem/

class Solution:
    def canMeasureWater(self, jug1Capacity, jug2Capacity, targetCapacity):
        """
        Inputs:
            jug1Capacity, jug2Capacity, targetCapacity: int
        Outputs:
            res: bool
        """
        stack = [(0, 0)]
        self.seen = set()
        while stack:
            remain_1, remain_2 = stack.pop()
            if remain_1 == targetCapacity or remain_2 == targetCapacity or remain_1 + remain_2 == targetCapacity:
                return True
            if (remain_1, remain_2) in self.seen:
                continue
            self.seen.add((remain_1, remain_2))
            # Fill 1.
            stack.append((jug1Capacity, remain_2))
            # Fill 2.
            stack.append((remain_1, jug2Capacity))
            # Empty 1.
            stack.append((0, remain_2))
            # Empty 2.
            stack.append((remain_1, 0))
            # Put the water in 1 to 2 until 1 is empty or 2 is full.
            stack.append((remain_1 - min(remain_1, jug2Capacity - remain_2), remain_2 + min(remain_1, jug2Capacity - remain_2)))
            # Put the water in 2 to 1 until 2 is empty or 1 is full.
            stack.append((remain_1 + min(remain_2, jug1Capacity - remain_1), remain_2 - min(remain_2, jug1Capacity - remain_1)))
        return False