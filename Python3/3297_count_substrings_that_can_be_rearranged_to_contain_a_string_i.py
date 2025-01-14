# https://leetcode.cn/problems/count-substrings-that-can-be-rearranged-to-contain-a-string-i/

class Solution:
    def validSubstringCount(self, word1: str, word2: str) -> int:
        # from collections import defaultdict

        # cnt2 = defaultdict(int)
        # for ch in word2:
        #     cnt2[ch] += 1
        
        # n = len(word1)
        # dp = [0 for _ in range(n)]
        # if word1[0] == word2:
        #     dp[0] = 1
        # cnt1 = defaultdict(int)
        # cnt1[word1[0]] += 1
        # left = 0
        # for i in range(1, n):
        #     cnt1[word1[i]] += 1

        #     valid = True
        #     for ch, cnt in cnt2.items():
        #         if cnt1[ch] < cnt:
        #             valid = False
        #             break
        #     if not valid:
        #         dp[i] = dp[i-1]
        #         continue

        #     while left < i:
        #         ch = word1[left]
        #         tmp = cnt1[ch] - 1
        #         if tmp < cnt2[ch]:
        #             break
        #         left += 1
        #         cnt1[ch] = tmp
        #     dp[i] = left + 1

        # return sum(dp)


        ord_a = ord("a")
        cnt2 = [0 for _ in range(26)]
        for ch in word2:
            cnt2[ord(ch) - ord_a] += 1
        
        n, left = len(word1), 0
        res, pre = 0, 0
        cnt1 = [0 for _ in range(26)]
        for i in range(n):
            cnt1[ord(word1[i]) - ord_a] += 1

            valid = True
            for k in range(26):
                if cnt1[k] < cnt2[k]:
                    valid = False
                    break
            if not valid:
                res += pre
                continue

            while left < i:
                k = ord(word1[left]) - ord_a
                tmp = cnt1[k] - 1
                if tmp < cnt2[k]:
                    break
                left += 1
                cnt1[k] = tmp
            pre = left + 1
            res += pre

        return res