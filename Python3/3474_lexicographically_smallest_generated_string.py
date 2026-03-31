# https://leetcode.cn/problems/lexicographically-smallest-generated-string/

class Solution:
    def generateString(self, str1: str, str2: str) -> str:
        n, m = len(str1), len(str2)
        res = [" " for _ in range(n+m-1)]
        for i, ch1 in enumerate(str1):
            if ch1 != "T":
                continue
            for j, ch2 in enumerate(str2):
                curr = res[i+j]
                if curr != " " and curr != ch2:
                    return ""
                res[i+j] = ch2
        
        res_prev = [ch for ch in res]
        for i in range(n+m-1):
            if res_prev[i] == " ":
                res[i] = "a"
        
        for i, ch1 in enumerate(str1):
            if ch1 != "F":
                continue
            if "".join(res[i: i+m]) != str2:
                continue
            valid = False
            for j in range(m-1, -1, -1):
                if res_prev[i+j] == " ":
                    res[i+j] = "b"
                    valid = True
                    break
            if not valid:
                return ""
        return "".join(res)