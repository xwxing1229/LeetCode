# https://leetcode.cn/problems/minimum-deletions-to-make-string-balanced/

class Solution:
    def minimumDeletions(self, s):
        """
        Inputs:
            s: str
        Outputs:
            res: int
        """
        n = len(s)
        cnt_left_b, cnt_right_a = [0 for _ in range(n)], [0 for _ in range(n)]
        for i in range(1, n):
            # Count how many bs on the left side of the current position.
            if s[i-1] == "b":
                cnt_left_b[i] = cnt_left_b[i-1] + 1
            else:
                cnt_left_b[i] = cnt_left_b[i-1]
            # Count how many as on the right side of the current position.
            if s[n-i] == "a":
                cnt_right_a[n-i-1] = cnt_right_a[n-i] + 1
            else:
                cnt_right_a[n-i-1] = cnt_right_a[n-i]

        res = n
        for i in range(n):
            tmp = cnt_left_b[i] + cnt_right_a[i]
            if tmp < res:
                res = tmp
        return res