// https://leetcode.cn/problems/non-decreasing-subsequences/

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        nums_ = nums;
        unordered_set<int> check;
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            if (check.find(num) == check.end()) {
                check.insert(num);
                vector<int> cur = {num};
                dfs(i+1, cur);
            }
        }
        return res_;
    }

    void dfs(int idx, vector<int> &cur) {
        unordered_set<int> check;
        for (int i = idx; i < nums_.size(); ++i) {
            int num = nums_[i];
            if (check.find(num) == check.end() && num >= cur.back()) {
                check.insert(num);
                cur.push_back(num);
                res_.push_back(cur);
                dfs(i+1, cur);
                cur.pop_back();
            }
        }
    }

    vector<int> nums_;
    vector<vector<int>> res_;
};
