# https://leetcode.cn/problems/longest-repeating-character-replacement/

class Solution:
    def characterReplacement(self, s, k):
        """
        Inputs:
            s: str
            k: int
        Outputs:
            res: int
        """

        left, right = 0, 0
        ord_A = ord("A")
        cnt = [0 for i in range(26)]
        res = 0
        while right < len(s):
            cnt[ord(s[right]) - ord_A] += 1
            while not self.isValid(cnt, k):
                cnt[ord(s[left]) - ord_A] -= 1
                left += 1

            tmp = right - left + 1
            if tmp > res:
                res = tmp

            right += 1

        return res

    def isValid(self, cnt, k):
        if sum(cnt) - max(cnt) <= k:
            return True
        else:
            return False