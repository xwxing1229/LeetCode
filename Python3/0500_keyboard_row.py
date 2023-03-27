# https://leetcode.cn/problems/keyboard-row/

class Solution:
    def findWords(self, words: List[str]) -> List[str]:
        """
        Inputs:
            words: list[str]
        Outputs:
            res: list[str]
        """
        res = []
        table = {
            0: {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p',
                'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P'},
            1: {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l',
                'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L'},
            2: {'z', 'x', 'c', 'v', 'b', 'n', 'm',
                'Z', 'X', 'C', 'V', 'B', 'N', 'M'}
        }
        for word in words:
            idx = 0
            for i in range(3):
                if word[0] in table[i]:
                    idx = i
                    break
            can = True
            for ch in word:
                if ch not in table[idx]:
                    can = False
                    break
            if can:
                res.append(word)
        return res