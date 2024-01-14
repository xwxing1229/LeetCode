# https://leetcode.cn/problems/count-common-words-with-one-occurrence/

class Solution:
    def countWords(self, words1, words2):
        """
        Inputs:
            words1, words2: list[str]
        Outputs:
            res: int
        """
        cnt1, cnt2 = dict(), dict()
        for word in words1:
            cnt1[word] = cnt1.get(word,0) + 1
        for word in words2:
            cnt2[word] = cnt2.get(word,0) + 1
        
        res = 0
        for k,v in cnt1.items():
            if v == 1 and cnt2.get(k,0) == 1:
                res += 1
        return res