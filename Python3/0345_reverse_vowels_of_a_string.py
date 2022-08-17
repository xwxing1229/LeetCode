# https://leetcode.cn/problems/reverse-vowels-of-a-string/

class Solution:
    def reverseVowels(self, s: str) -> str:
        """
        Inputs:
            s: str
        Outputs:
            res: str
        """
        vowels = "aeiouAEIOU"
        n = len(s)
        left = 0
        right = n - 1
        res = list(s)
        while left < right:
            while left < n and res[left] not in vowels:
                left = left + 1
            while right >= 0 and res[right] not in vowels:
                right = right - 1
            
            if left >= right:
                break

            ch = res[left]
            res[left] = res[right]
            res[right] = ch
            left = left + 1
            right = right - 1
        return "".join(res)