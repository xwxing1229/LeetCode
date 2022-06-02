// https://leetcode.cn/problems/permutations-ii/

class Solution {
public:
    vector<vector<int>> res;
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> check(nums.size(), 0);
        
        backTrack({}, nums, check);
    
        return res;
    }

    void backTrack(vector<int> res_tmp, vector<int> nums, vector<int> check) {
        int n = nums.size();
        if (res_tmp.size() == n) {
            res.push_back(res_tmp);
            return;
        }

        for (int i = 0; i < n; ++i) {
            if (check[i] == 1) {
                continue;
            }
            if ((i > 0) && (nums[i] == nums[i-1]) && (check[i-1] == 0)) {
                continue;
            }

            vector<int> res_new(res_tmp);
            res_new.push_back(nums[i]);
            check[i] = 1;
            backTrack(res_new, nums, check);
            check[i] = 0;
        }
    }
};
