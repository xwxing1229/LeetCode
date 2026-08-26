# https://leetcode.cn/problems/shortest-and-lexicographically-smallest-beautiful-string/

class Solution:
    def shortestBeautifulSubstring(self, s: str, k: int) -> str:
        beautiful = []
        size_min = len(s)
        cnt, left = 0, 0
        for i, ch in enumerate(s):
            cnt += (ch == "1")
            while cnt >= k:
                cnt -= (s[left] == "1")
                left += 1
            if cnt == k-1 and left > 0:
                size = i - left + 2
                sub = s[left-1: i+1]
                if size == size_min:
                    beautiful.append(sub)
                elif size < size_min:
                    beautiful = [sub]
                    size_min = size
        if not beautiful:
            return ""
        res = beautiful[0]
        for sub in beautiful:
            res = min(res, sub)
        return res