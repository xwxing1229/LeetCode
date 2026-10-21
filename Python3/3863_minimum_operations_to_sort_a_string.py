# https://leetcode.cn/problems/minimum-operations-to-sort-a-string/

class Solution:
    def minOperations(self, s: str) -> int:
        mn, mx = "z", "a"
        mn_cnt, mx_cnt = 0, 0
        prev = "a"
        sort = True
        for ch in s:
            if ch < mn:
                mn = ch
                mn_cnt = 1
            elif ch == mn:
                mn_cnt += 1

            if ch > mx:
                mx = ch
                mx_cnt = 1
            elif ch == mx:
                mx_cnt += 1

            if ch < prev:
                sort = False
            prev = ch

        if sort:
            return 0
        elif len(s) == 2:
            return -1
        elif s[0] == mn or s[-1] == mx:
            return 1
        elif s[0] == mx and s[-1] == mn and mn_cnt == 1 and mx_cnt == 1:
            return 3
        else:
            return 2