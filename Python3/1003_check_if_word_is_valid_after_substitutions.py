# https://leetcode.cn/problems/check-if-word-is-valid-after-substitutions/

class Solution:
    def isValid(self, s):
        """
        Inputs:
            s: str
        Outpus:
            res: bool
        """
        if len(s) % 3 != 0:
            return False
        st = []
        for ch in s:
            if ch == "c":
                n = len(st)
                if n >= 2 and st[n-1] == "b" and st[n-2] == "a":
                    st.pop()
                    st.pop()
                else:
                    st.append(ch)
            else:
                st.append(ch)
        if st:
            return False
        else:
            return True