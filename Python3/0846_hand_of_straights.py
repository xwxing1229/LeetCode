# https://leetcode-cn.com/problems/hand-of-straights/
class Solution:
    def isNStraightHand(self, hand, groupSize):
        """
        Inputs:
            hand: list[int]
            groupSize: int
        Outputs:
            res: bool
        """

        n = len(hand)
        if n % groupSize != 0:
            return False

        hand.sort()
        for i in range(n // groupSize):
            start = hand[0]
            hand.remove(start)
            j = 1
            while j < groupSize and start+j in hand:
                hand.remove(start+j)
                j = j + 1

            if j != groupSize:
                return False

        return True