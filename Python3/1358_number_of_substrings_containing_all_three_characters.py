# https://leetcode.cn/problems/number-of-substrings-containing-all-three-characters/

class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        res = 0
        n = len(s)
        right = 0
        count = [0, 0, 0]
        for left in range(n):
            while right < n and (count[0] < 1 or count[1] < 1 or count[2] < 1):
                count[ord(s[right]) - ord("a")] += 1
                right += 1
            if count[0] > 0 and count[1] > 0 and count[2] > 0:
                res += n - right + 1
            count[ord(s[left]) - ord("a")] -= 1
        return res