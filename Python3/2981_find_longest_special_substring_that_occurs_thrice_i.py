# https://leetcode.cn/problems/find-longest-special-substring-that-occurs-thrice-i/

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
            cnts = defaultdict(int)
            for n in rec:
                for length in range(1, n+1):
                    cnts[length] += n + 1 - length
                    if cnts[length] >= 3 and length > res:
                        res = length
        return res
