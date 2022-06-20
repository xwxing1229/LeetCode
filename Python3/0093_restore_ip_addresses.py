# https://leetcode.cn/problems/restore-ip-addresses/

class Solution:
    def restoreIpAddresses(self, s):
        """
        Inputs:
            s: str
        Outputs:
            res: list[str]
        """

        self.res = []
        self.backtrack(s, [], 1)
        return self.res

    def backtrack(self, s, tmp_idx, idx):
        if len(tmp_idx) == 3:
            flag, tmp_res = self.check_valid(s, tmp_idx)
            if flag:
                self.res.append(tmp_res)
            return

        for i in range(idx, len(s)):
            self.backtrack(s, tmp_idx+[i], i+1)

    def check_valid(self, s, tmp_idx):
        tmp_idx = [0] + tmp_idx + [len(s)]
        tmp_res = []
        for i in range(4):
            s_sub = s[tmp_idx[i]: tmp_idx[i+1]]
            if (len(s_sub) > 3) or ((len(s_sub) > 1) and (s_sub[0] == "0")):
                return False, ""

            val = int(s_sub)
            if val > 255:
                return False, ""

            tmp_res.append(s_sub)

        return True, ".".join(tmp_res)
        