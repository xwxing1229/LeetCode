# https://leetcode.cn/problems/combination-sum-ii/

class Solution:
    def combinationSum2(self, candidates, target):
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
        count = {}
        for cand in candidates:
            count[cand] = count.get(cand,0) + 1

        for i in range(cands_min, target+1):
            if i in candidates:
                res[i].append([i])

            for tar1 in range(cands_min, i):
                tar2 = i - tar1
                if tar2 < cands_min:
                    break

                for res1 in res[tar1]:
                    for res2 in res[tar2]:
                        res_tmp = res1 + res2
                        count_tmp = {}
                        flag_tmp = True
                        # Check if each element in candidates is used at most once.
                        for cand in res_tmp:
                            count_tmp[cand] = count_tmp.get(cand,0) + 1
                            if count_tmp[cand] > count[cand]:
                                flag_tmp = False
                                break
                        # Check if current combination already exists.
                        if flag_tmp:
                            res_tmp.sort()
                            if res_tmp not in res[i]:
                                res[i].append(res_tmp)

        return res[-1]