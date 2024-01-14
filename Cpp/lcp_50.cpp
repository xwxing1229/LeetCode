// https://leetcode.cn/problems/WHnhjV/

class Solution {
public:
    int giveGem(vector<int>& gem, vector<vector<int>>& operations) {
        for (auto &op: operations) {
            int n = gem[op[0]] / 2;
            gem[op[0]] -= n;
            gem[op[1]] += n;
        }
        int min_ = gem[0], max_ = gem[0];
        for (auto g: gem) {
            min_ = min(min_, g);
            max_ = max(max_, g);
        }
        return max_ - min_;
    }
};
