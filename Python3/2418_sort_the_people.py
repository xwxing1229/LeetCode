# https://leetcode.cn/problems/sort-the-people/

class Solution:
    def sortPeople(self, names, heights):
        """
        Inputs:
            names: list[str]
            heights: list[int]
        Outputs:
            res: list[str]
        """
        people = []
        for i in range(len(heights)):
            people.append([heights[i], names[i]])
        people = sorted(people, key=lambda x: -x[0])
        res = []
        for height, name in people:
            res.append(name)
        return res