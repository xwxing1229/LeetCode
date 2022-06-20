// https://leetcode.cn/problems/subsets-ii/

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> tmp;
        vector<int> check(nums.size(), 0);
        backtrack(nums, tmp, check, 0);
        return res;
    }

private:
    void backtrack(vector<int> nums, vector<int> &tmp, vector<int> &check,
        int idx) {
        res.push_back(tmp);

        for (int i = idx; i < nums.size(); ++i) {
            if ((i > 0) && (nums[i] == nums[i-1]) && (!check[i-1])) {
                continue;
            }

            tmp.push_back(nums[i]);
            check[i] = 1;
            backtrack(nums, tmp, check, i+1);
            tmp.pop_back();
            check[i] = 0;
        }
    }

    vector<vector<int>> res;
};
