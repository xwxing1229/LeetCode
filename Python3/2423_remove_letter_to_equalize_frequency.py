# https://leetcode.cn/problems/remove-letter-to-equalize-frequency/

class Solution:
    def equalFrequency(self, word):
        """
        Inputs:
            word: str
        Outputs:
            res: bool
        """
        cnt_tmp = [0 for _ in range(26)]
        for ch in word:
            cnt_tmp[ord(ch)-ord("a")] += 1
        cnt = []
        for c in cnt_tmp:
            if c:
                cnt.append(c)
        for i in range(len(cnt)):
            if cnt[i] == 1:
                tmp = cnt[:i] + cnt[i+1:]
            else:
                tmp = cnt[:i] + [cnt[i]-1] + cnt[i+1:]
            if len(set(tmp)) == 1:
                return True
        return False