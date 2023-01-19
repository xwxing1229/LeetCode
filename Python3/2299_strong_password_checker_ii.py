# https://leetcode.cn/problems/strong-password-checker-ii/

class Solution:
    def strongPasswordCheckerII(self, password):
        """
        Inputs:
            password: str
        Outputs:
            res: bool
        """
        if len(password) < 8:
            return False
        specials = {
            "!", "@", "#", "$", "%", "^", "&", "*", "(", ")", "-", "+"
        }
        lower, upper, digit, special = False, False, False, False
        idx_a, idx_z, idx_A, idx_Z = ord("a"), ord("z"), ord("A"), ord("Z")
        for i, ch in enumerate(password):
            if i > 0 and ch == password[i-1]:
                return False
            idx = ord(ch)
            if idx >= idx_a and idx <= idx_z:
                lower = True
            elif idx >= idx_A and idx <= idx_Z:
                upper = True
            elif ch.isdigit():
                digit = True
            elif ch in specials:
                special = True
        return lower and upper and digit and special