# https://leetcode.cn/problems/minimum-length-of-anagram-concatenation/

class Solution:
    def minAnagramLength(self, s: str) -> int:
        n = len(s)
        for k in range(1, n):
            if n % k != 0:
                continue

            cnts = Counter(s[:k])
            valid = True
            for idx in range(k, n, k):
                cnts_tmp = Counter(s[idx: idx+k])
                if cnts_tmp != cnts:
                    valid = False
                    break
            if valid:
                return k
        return n