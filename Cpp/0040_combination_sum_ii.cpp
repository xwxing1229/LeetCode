// https://leetcode.cn/problems/combination-sum-ii/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // Define tar1 and tar2 such that target = tar1 + tar2.
        // We can get the combinations for target from those for tar1 and tar2.
        int cand_min = *min_element(candidates.begin(), candidates.end());
        if (target < cand_min) {
            return vector<vector<int>>();
        }

        vector<vector<vector<int>>> res(target+1);
        unordered_map<int, int> count;
        for (int cand: candidates) {
            count[cand] = count[cand] + 1;
        }

        for (int i = cand_min; i <= target; ++i) {
            if (find(candidates.begin(), candidates.end(), i) != candidates.end()) {
                vector<int> res_tmp = {i};
                res[i].push_back(res_tmp);
            }
            for (int tar1 = cand_min; tar1 < i; ++tar1) {
                int tar2 = i - tar1;
                if (tar2 < cand_min) break;

                for (vector<int> res1: res[tar1]) {
                    for (vector<int> res2: res[tar2]) {
                        vector<int> res_tmp(res1);
                        res_tmp.insert(res_tmp.end(), res2.begin(), res2.end());
                        // Check if each element in candidates is used at most once.
                        unordered_map<int, int> count_tmp;
                        bool flag_tmp = true;
                        for (int cand: res_tmp) {
                            count_tmp[cand] = count_tmp[cand] + 1;
                            if (count_tmp[cand] > count[cand]) {
                                flag_tmp = false;
                                break;
                            }
                        }
                        // Check if current combination already exists.
                        if (flag_tmp) {
                            sort(res_tmp.begin(), res_tmp.end());
                            if (find(res[i].begin(), res[i].end(), res_tmp) == res[i].end()) {
                                res[i].push_back(res_tmp);
                            }
                        }
                    }
                }
            }
        }
        return res[target];
    }
};
