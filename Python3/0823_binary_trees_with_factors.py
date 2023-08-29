# https://leetcode.cn/problems/binary-trees-with-factors/

class Solution:
    def numFactoredBinaryTrees(self, arr):
        """
        Inputs:
            arr: list[int]
        Outputs:
            res: int
        """
        arr.sort()
        dp = [1 for _ in range(len(arr))]
        idxs = dict()
        mod = 1000000007
        for i, val in enumerate(arr):
            root, j = int(sqrt(val)), 0
            while j < i and arr[j] <= root:
                if val % arr[j] != 0 or val//arr[j] not in idxs:
                    pass
                elif val == arr[j] * arr[j]:
                    dp[i] = (dp[i] + (dp[j] % mod) * (dp[idxs[val//arr[j]]] % mod)) % mod
                else:
                    dp[i] = (dp[i] + (dp[j] % mod) * (dp[idxs[val//arr[j]]] % mod) * 2) % mod
                j += 1
            idxs[val] = i

        res = 0
        for cnt in dp:
            res = (cnt + res) % mod
        return res