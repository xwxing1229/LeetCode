# https://leetcode-cn.com/problems/boats-to-save-people/
class Solution:
    def numRescueBoats(self, people, limit):
        """
        Inputs:
            people: list[int]
            limit: int
        Outputs:
            res: int
        """

        n = len(people)
        people.sort()
        l = 0
        r = n - 1
        while people[r] >= limit:
            r = r - 1
        res = n - r - 1

        while l < r:
            if people[l] + people[r] <= limit:
                l = l + 1
                r = r - 1
            else:
                r = r - 1

            res = res + 1

        if l == r:
            res = res + 1

        return res