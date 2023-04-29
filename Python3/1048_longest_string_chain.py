# https://leetcode.cn/problems/longest-string-chain/

class Solution:
    def longestStrChain(self, words):
        """
        Inputs:
            words: list[str]
        Outputs:
            res: int
        """
        words.sort(key=len)
        cnt = dict()
        res = 0
        for word in words:
            cnt[word] = 1
            for i in range(len(word)):
                pre = word[:i] + word[i+1:]
                if pre in cnt:
                    tmp = cnt[pre] + 1
                    if tmp > cnt[word]:
                        cnt[word] = cnt[pre] + 1
                if cnt[word] > res:
                    res = cnt[word]
        return res
