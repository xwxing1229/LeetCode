# https://leetcode.cn/problems/expressive-words/

class Solution:
    def expressiveWords(self, s, words):
        """
        Inputs:
            s: str
            words: list[str]
        Outputs:
            int
        """
        ss = ""
        nums = []
        cnt = 1
        for i in range(1, len(s)):
            if s[i] != s[i-1]:
                ss += s[i-1]
                nums.append(cnt)
                cnt = 1
            else:
                cnt += 1
        ss += s[len(s)-1]
        nums.append(cnt)

        res = len(words)
        for word in words:
            word += " "
            j, cnt = 0, 1
            for i in range(1, len(word)):
                if word[i] != word[i-1]:
                    if j == len(ss):
                        res -= 1
                        break
                    if (word[i-1] != ss[j]) or\
                        (cnt != nums[j] and nums[j] < 3) or\
                        (cnt > nums[j]):
                        break
                    cnt = 1
                    j += 1
                else:
                    cnt += 1
            if j != len(ss):
                res -= 1
        return res