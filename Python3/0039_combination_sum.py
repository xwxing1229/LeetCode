# https://leetcode.cn/problems/combination-sum/

class Solution:
    def combinationSum(self, candidates, target):
        """
        Inputs:
            candidates: list[int]
            target: int
        Outputs:
            res: list[list[int]]
        """

        # Define tar1 and tar2 such that target = tar1 + tar2.
        # We can get the combinations for target from those for tar1 and tar2.

        cands_min = min(candidates)
        if target < cands_min:
            return []

        res = [[] for _ in range(target+1)]
        res[cands_min].append([cands_min])
        for i in range(cands_min+1, target+1):
            for tar1 in range(cands_min, i):
                tar2 = i - tar1
                if tar2 < cands_min:
                    continue

                for res_tar1 in res[tar1]:
                    for res_tar2 in res[tar2]:
                        res_i = res_tar1 + res_tar2
                        res_i.sort()
                        if res_i not in res[i]:
                            res[i].append(res_i)

            if i in candidates:
                res[i].append([i])

        return res[-1]