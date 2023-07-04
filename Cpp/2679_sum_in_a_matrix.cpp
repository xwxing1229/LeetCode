// https://leetcode.cn/problems/sum_in_a_matrix/

class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        for (auto &row: nums) {
            sort(row.begin(), row.end());
        }
        int res = 0, m = nums.size(), n = nums[0].size();
        for (int j = 0; j < n; ++j) {
            int max_ = nums[0][j];
            for (int i = 1; i < m; ++i) {
                max_ = max(max_, nums[i][j]);
            }
            res += max_;
        }
        return res;
    }
};