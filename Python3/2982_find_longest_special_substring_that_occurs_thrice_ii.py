# https://leetcode.cn/problems/find-longest-special-substring-that-occurs-thrice-ii/

class Solution:
    def maximumLength(self, s: str) -> int:
        record = [[] for _ in range(26)]
        pre = s[0]
        pre_id, ord_a = 0, ord("a")
        for i in range(1, len(s)):
            if s[i] != pre:
                record[ord(pre) - ord_a].append(i - pre_id)
                pre = s[i]
                pre_id = i
        record[ord(pre) - ord_a].append(len(s) - pre_id)

        res = -1
        for rec in record:
            if len(rec) == 0:
                continue
            rec.sort(reverse=True)
            res = max(res, rec[0]-2)
            if len(rec) >= 2:
                if rec[0] == rec[1]:
                    res = max(res, rec[0]-1)
                else:
                    res = max(res, rec[1])
            if len(rec) >= 3:
                res = max(res, rec[2])
        return res if res > 0 else -1