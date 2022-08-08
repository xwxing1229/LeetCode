# https://leetcode.cn/problems/remove-duplicate-letters/

class Solution:
    def removeDuplicateLetters(self, s):
        """
        Inputs:
            s: string
        Outputs:
            res: string
        """

        counts = [0 for _ in range(26)]
        check = [0 for _ in range(26)]
        for ch in s:
            counts[ord(ch) - ord('a')] = counts[ord(ch) - ord('a')] + 1
        
        res = ""
        for ch in s:
            idx = ord(ch) - ord('a')
            if check[idx] == 0:
                while (res != "") and (res[-1] > ch):
                    if counts[ord(res[-1]) - ord('a')] > 0:
                        check[ord(res[-1]) - ord('a')] = 0
                        res = res[: -1]
                    else:
                        break

                res = res + ch
                check[idx] = 1
            counts[idx] = counts[idx] - 1
        return res