// https://leetcode.cn/problems/subsets/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> tmp;
        int n = nums.size();
        backtrack(nums, tmp, n, 0);
        return res;
    }

private:
    void backtrack(vector<int> nums, vector<int>& tmp, int n, int idx) {
        res.push_back(tmp);

        for (int i = idx; i < n; ++i) {
            tmp.push_back(nums[i]);
            backtrack(nums, tmp, n, i+1);
            tmp.pop_back();
        }
    }

    vector<vector<int>> res;
};
