# https://leetcode.cn/problems/making-file-names-unique/

class Solution:
    def getFolderNames(self, names):
        """
        Inputs:
            names: list[str]
        Outputs:
            res: list[str]
        """
        res = []
        records = dict()
        for name in names:
            if name in records:
                i = records[name]
                while True:
                    tmp =  name + "(" + str(i) + ")"
                    if tmp not in records:
                        res.append(tmp)
                        records[name] = i + 1
                        records[tmp] = 1
                        break
                    i += 1
            else:
                res.append(name)
                records[name] = 1
        return res