# https://leetcode.cn/problems/count-substrings-that-can-be-rearranged-to-contain-a-string-ii/

class Solution:
    def validSubstringCount(self, word1: str, word2: str) -> int:
        ord_a = ord("a")
        cnt2 = [0 for _ in range(26)]
        for ch in word2:
            cnt2[ord(ch) - ord_a] += 1
        
        left = 0
        res, pre = 0, 0
        cnt1 = [0 for _ in range(26)]
        for i, ch in enumerate(word1):
            cnt1[ord(ch) - ord_a] += 1

            valid = True
            for k in range(26):
                if cnt1[k] < cnt2[k]:
                    valid = False
                    break
            if not valid:
                res += pre
                continue

            while left < i:
                idx = ord(word1[left]) - ord_a
                tmp = cnt1[idx] - 1
                if tmp < cnt2[idx]:
                    break
                left += 1
                cnt1[idx] = tmp
            res += left + 1
            pre = left + 1
        return res