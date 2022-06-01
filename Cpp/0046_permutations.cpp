// https://leetcode.cn/problems/jump-game-ii/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res = {{}};
        for (int num: nums) {
            int n = res.size();
            for (int i = 0; i < n; ++i) {
                vector<int> vec = res[i];
                for (int j = 0; j <= vec.size(); ++j) {
                    vector<int> res_tmp(vec);
                    res_tmp.insert(res_tmp.begin()+j, num);
                    res.push_back(res_tmp);
                }
            }
            res.erase(res.begin(), res.begin()+n);
        }
        return res;
    }
};
