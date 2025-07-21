# https://leetcode.cn/problems/delete-characters-to-make-fancy-string/

class Solution:
    def makeFancyString(self, s: str) -> str:
        res = ["-"]
        cnt = 0
        for ch in s:
            if ch != res[-1]:
                res.append(ch)
                cnt = 1
            elif cnt < 2:
                res.append(ch)
                cnt += 1
        return "".join(res[1:])