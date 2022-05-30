// https://leetcode.cn/problems/combination-sum/

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
        vector<vector<int>> res_i = {{cand_min}};
        res[cand_min] = res_i;
        for (int i = cand_min + 1; i <= target; ++i) {
            for (int tar1 = cand_min; tar1 < i; ++tar1) {
                int tar2 = i - tar1;
                if (tar2 < cand_min) continue;

                for (vector<int> res_tar1: res[tar1]) {
                    for (vector<int> res_tar2: res[tar2]) {
                        vector<int> res_i(res_tar1);
                        res_i.insert(res_i.end(), res_tar2.begin(), res_tar2.end());
                        
                        // If res_i has not been added to res[i], add res_i to res[i].
                        sort(res_i.begin(), res_i.end());
                        if (find(res[i].begin(), res[i].end(), res_i) == res[i].end()) {
                            res[i].push_back(res_i);
                        }
                    }
                }
            }

            // If i is in candidates, add {i} to res[i].
            if (find(candidates.begin(), candidates.end(), i) != candidates.end()) {
                vector<int> res_i = {i};
                res[i].push_back(res_i);
            } 
        }

        return res[target];
    }
};
