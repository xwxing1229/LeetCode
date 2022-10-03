# https://leetcode.cn/problems/longest-absolute-file-path/

class Solution:
    def lengthLongestPath(self, input):
        """
        Inputs:
            input: str
        Outputs:
            res: int
        """

        res = 0
        cnt = {-1: 0}
        for line in input.split("\n"):
            depth = line.count("\t")
            cnt[depth] = cnt[depth-1] + len(line) - depth
            if line.count(".") > 0:
                res = max(res, cnt[depth] + depth)
        return res