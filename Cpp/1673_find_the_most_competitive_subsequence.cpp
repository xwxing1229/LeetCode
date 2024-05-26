// https://leetcode.cn/problems/find-the-most-competitive-subsequence/

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> res;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int num = nums[i];
            while (res.size() > 0 && num < res.back() && res.size() + n - i > k) {
                res.pop_back();
            }
            res.push_back(num);
        }
        res.resize(k);
        return res;
    }
};