# https://leetcode.cn/problems/isomorphic-strings/

class Solution:
    def isIsomorphic(self, s, t):
        """
        Inputs:
            s: str
            t: str
        Outputs:
            res: bool
        """

        ns = len(s)
        nt = len(t)
        if ns != nt:
            return False

        s2t = dict()
        t2s = dict()
        for i in range(ns):
            si = s[i]
            ti = t[i]
            ch1 = s2t.get(si, 0)
            ch2 = t2s.get(ti, 0)
            if ch1 == 0 and ch2 == 0:
                s2t[si] = ti
                t2s[ti] = si
            elif (ch1 == ti) and (ch2 == si):
                continue
            else:
                return False
        return True