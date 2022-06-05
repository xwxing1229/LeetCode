# https://leetcode.cn/problems/group-anagrams/

class Solution:
    def groupAnagrams(self, strs):
        """
        Inputs:
            strs: list[str]
        Outputs:
            res: list[list[str]]
        """

        res = []

        record = {}
        idx = 0
        for s in strs:
            count_s = self.count(s)
            if count_s not in record:
                res.append([s])
                record[count_s] = idx
                idx = idx + 1
            else:
                res[record[count_s]].append(s)
        return res

    def count(self, s):
        res = [0 for _ in range(26)]
        for c in s:
            idx = ord(c) - ord('a')
            res[idx] = res[idx] + 1
        return tuple(res)