# https://leetcode.cn/problems/longest-subsequence-with-limited-sum/

class Solution:
    def answerQueries(self, nums, queries):
        """
        Inputs:
            nums, queries: list[int]
        Outputs:
            res: list[int]
        """
        n, m = len(nums), len(queries)
        res = [0 for _ in range(m)]

        nums.sort()
        idxs = [query_idx[0] for query_idx in sorted(enumerate(queries), key=lambda x: x[1])]
        i, cumsum = 0, 0
        for j in range(m):
            idx = idxs[j]
            query = queries[idx]
            while i < n and cumsum <= query:
                cumsum += nums[i]
                i += 1

            if cumsum <= query:
                res[idx] = i
            else:
                res[idx] = i - 1
        return res