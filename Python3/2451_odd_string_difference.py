# https://leetcode.cn/problems/odd-string-difference/

class Solution:
    def oddString(self, words):
        """
        Inputs:
            words: list[str]
        Outputs:
            res: str
        """
        for i in range(len(words[0])-1):
            diff = ord(words[0][i+1]) - ord(words[0][i])
            cnt = 1
            for j in range(1, len(words)):
                if diff == ord(words[j][i+1]) - ord(words[j][i]):
                    cnt += 1
                elif cnt == 1 and j == 1 and\
                    diff != ord(words[j+1][i+1]) - ord(words[j+1][i]):
                    return words[0]
                else:
                    return words[j]
        return "Invalid input"