# https://leetcode.cn/problems/remove-k-digits/

class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        """
        Inputs:
            num: str
            k: int
        Outputs:
            res: str
        """

        st = []
        for i in num:
            while k > 0 and st and st[-1] > i:
                st.pop()
                k = k - 1
            st.append(i)
        while k > 0:
            st.pop()
            k = k - 1
        res = "".join(st)
        while res != "" and res[0] == "0":
            res = res[1:]
        if res == "":
            res = "0"
        return res