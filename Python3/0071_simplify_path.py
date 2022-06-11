# https://leetcode.cn/problems/simplify-path/

class Solution:
    def simplifyPath(self, path):
        """
        Inputs:
            path: str
        Outputs:
            res: str
        """

        res = []
        sp = path.split("/")
        for s in sp:
            if s == "." or s == "":
                continue
            elif s == "..":
                if res:
                    res.pop()
            else:
                res.append("/" + s)

        if not res:
            res.append("/")
        return "".join(res)