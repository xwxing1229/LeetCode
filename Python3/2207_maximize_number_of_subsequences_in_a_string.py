# https://leetcode.cn/problems/maximize-number-of-subsequences-in-a-string/

class Solution:
    def maximumSubsequenceCount(self, text: str, pattern: str) -> int:
        cnts = []
        cnt1, cnt2 = 0, 0
        for ch in text:
            if ch == pattern[0]:
                if cnt2 > 0:
                    cnts.append([cnt1, cnt2])
                    cnt1 = 1
                    cnt2 = 0
                else:
                    cnt1 += 1
            elif ch == pattern[1]:
                cnt2 += 1
        cnts.append([cnt1, cnt2])

        # Special case.
        if pattern[0] == pattern[1]:
            n = cnts[0][0]
            return (n+1)*n//2
        
        # Add pattern[0] at the beginning of text, or add pattern[1] at the end of text.
        tmp1, tmp2 = 0, 0
        cnt1_sum, cnt2_sum = 0, 0
        for i in range(len(cnts)-1, -1, -1):
            cnt2_sum += cnts[i][1]
            tmp1 += cnts[i][0] * cnt2_sum
        tmp1 += cnt2_sum

        for i in range(len(cnts)):
            cnt1_sum += cnts[i][0]
            tmp2 += cnts[i][1] * cnt1_sum
        tmp2 += cnt1_sum
        return max(tmp1, tmp2)