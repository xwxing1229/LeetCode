# https://leetcode.cn/problems/queue-reconstruction-by-height/

class Solution:
    def reconstructQueue(self, people):
        """
        Inputs:
            people: list[list[int]]
        Outputs:
            res: list[list[int]]
        """

        people = sorted(people, key=lambda x: (x[0], -x[1]))
        n = len(people)
        idxs = [i for i in range(n)]
        res = [[] for i in range(n)]
        for person in people:
            idx = idxs[person[1]]
            res[idx] = person
            idxs.pop(person[1])
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