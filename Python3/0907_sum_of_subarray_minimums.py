# https://leetcode.cn/problems/sum-of-subarray-minimums/

class Solution:
    def sumSubarrayMins(self, arr):
        """
        Inputs:
            arr: list[int]
        Outputs:
            res: int
        """

        n = len(arr)
        dp = [0 for i in range(n)]
        st = [] # save indices s.t. arr[st[i]] >= arr[st[j]] for i < j
        res, cnt = 0, 0
        for i in range(n):
            while st and arr[st[-1]] > arr[i]:
                st.pop()

            if st:
                cnt = i - st[-1]
            else:
                cnt = i + 1
            dp[i] = cnt * arr[i]
            if st:
                dp[i] += dp[st[-1]]
                
            st.append(i)

            res = (res + dp[i]) % 1000000007
        return res