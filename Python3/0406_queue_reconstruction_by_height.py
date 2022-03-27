# https://leetcode-cn.com/problems/queue-reconstruction-by-height/

class Solution:
    def reconstructQueue(self, people):
        """
        Inputs:
            people: list[list[int]]
        Outputs:
            res: list[list[int]]
        """

        people.sort()
        n = len(people)
        res = [0 for i in range(n)]

        for person in people:
            i = person[1]
            count = 0
            # Check how many empty places or places occupied by a
            # person with same or larger height.
            for j in range(i):
                if not res[j] or res[j][0] >= person[0]:
                    count = count + 1

            while True:
                if count == person[1] and not res[i]:
                    break
                else:
                    i = i + 1
                    if not res[i-1] or res[i-1][0] >= person[0]:
                        count = count + 1

            res[i] = person
        return res

        # Another way.
        '''
        people.sort(key=lambda x:(x[0],-x[1]))
        n = len(people)
        res = [0 for i in range(n)]

        for person in people:
            num = person[1]
            for i in range(n):
                if not res[i]:
                    num = num - 1
                if num == -1:
                    res[i] = person
                    break
        return res
        '''