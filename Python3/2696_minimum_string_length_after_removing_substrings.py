# https://leetcode.cn/problems/minimum-string-length-after-removing-substrings/

class Solution:
    def minLength(self, s):
        """
        Inputs:
            s: str
        Outputs:
            res: int
        """

        n, i = len(s), 0
        res = n
        remove = [0 for _ in range(n)]
        while i < n-1:
            if s[i:i+2] == "AB" or s[i:i+2] == "CD":
                res -= 2
                remove[i] = 1
                remove[i+1] = 1
                left, right = i, i+1
                while left >= 0 and right < n:
                    while left >= 0 and remove[left]:
                        left -= 1
                    while right < n and remove[right]:
                        right += 1
                    if left >= 0 and right < n:
                        tmp = s[left] + s[right]
                        if tmp == "AB" or tmp == "CD":
                            res -= 2
                            remove[left] = 1
                            remove[right] = 1
                        else:
                            break
                i = right
            else:
                i += 1
        return res