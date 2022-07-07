# https://leetcode.cn/problems/happy-number/

class Solution:
    def isHappy(self, n):
        """
        Inputs:
            n: int
        Outputs:
            res: bool
        """

        '''
        record = dict()
        while n != 1:
            sqsum = 0
            while n > 0:
                quo = n // 10
                rem = n - quo * 10
                sqsum = sqsum + rem * rem
                n = quo

            if sqsum == 1:
                return True
            elif record.get(sqsum, 0) > 0:
                return False
            else:
                record[sqsum] = 1
                n = sqsum
        return True
        '''

        # O(1) space complexity using double pointers.
        slow = n
        fast = self.getNext(n)
        while slow != fast:
            slow = self.getNext(slow)
            fast = self.getNext(self.getNext(fast))

        if slow == 1:
            return True
        else:
            return False

    def getNext(self, n):
        sqsum = 0
        while n > 0:
            rem = n % 10
            sqsum = sqsum + rem * rem
            n = n // 10
        return sqsum
