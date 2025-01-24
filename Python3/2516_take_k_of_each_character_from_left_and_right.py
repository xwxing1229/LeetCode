# https://leetcode.cn/problems/take-k-of-each-character-from-left-and-right/

class Solution:
    def takeCharacters(self, s: str, k: int) -> int:
        # Find a substr with the maximum length that contains at most cnts_max[k]
        # for the kth char, where k = 0, 1, 2 corresponds to "a", "b", and "c".
        cnts_max = [-k for _ in range(3)]
        for ch in s:
            cnts_max[ord(ch) - ord("a")] += 1
        if cnts_max[0] < 0 or cnts_max[1] < 0 or cnts_max[2] < 0:
            return -1
        
        cnts = [0 for _ in range(3)]
        left, n = 0, len(s)
        res = n
        for right in range(n):
            ch = s[right]
            cnts[ord(ch) - ord("a")] += 1
            while left <= right:
                if cnts[0] <= cnts_max[0] and cnts[1] <= cnts_max[1] and cnts[2] <= cnts_max[2]:
                    res = min(res, n-(right-left+1))
                    break
                ch = s[left]
                cnts[ord(ch) - ord("a")] -= 1
                left += 1
        return res