# https://leetcode.cn/problems/repeated-substring-pattern/

class Solution:
    def repeatedSubstringPattern(self, s):
        """
        Inputs:
            s: str
        Outputs:
            res: bool
        """
        n = len(s)
        for i in range(1, n//2+1):
            if (s[i] == s[0]) and (n % i == 0):
                sub = s[0: i] # length of sub is i
                repeat = n // i
                cnt = 1
                for j in range(1, repeat):
                    if s[j*i: j*i+i] == sub:
                        cnt += 1
                    else:
                        break
                if cnt == repeat:
                    return True
        return False
