# https://leetcode.cn/problems/count-substrings-that-satisfy-k-constraint-ii/

class Solution:
    def countKConstraintSubstrings(self, s, k, queries):
        """
        Inputs:
            s: str
            k: int
            queries: list[list[int]]
        Outputs:
            list[int]
        """
        i, n = 0, len(s)
        valid = [0 for _ in range(n)]
        cumsum = [0 for _ in range(n+1)]
        cnt = [0, 0]
        for j, ch in enumerate(s):
            cnt[int(ch)] += 1
            while cnt[0] > k and cnt[1] > k and i <= j:
                cnt[int(s[i])] -= 1
                i += 1
            valid[j] = i
            cumsum[j+1] = cumsum[j] + j - i + 1
        
        res = [0 for _ in range(len(queries))]
        for idx, q in enumerate(queries):
            ql, qr = q[0], q[1]
            # Find the maximum j such that valid[j] <= ql.
            a, b, j = ql, qr, ql
            while a <= b:
                mid = (a + b) // 2
                if valid[mid] <= ql:
                    a = mid + 1
                    j = mid
                else:
                    b = mid - 1
            res[idx] = (j - ql + 2) * (j - ql + 1) // 2 + cumsum[qr+1] - cumsum[j+1]
        return res