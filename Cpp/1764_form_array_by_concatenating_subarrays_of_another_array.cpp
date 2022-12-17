// https://leetcode.cn/problems/form-array-by-concatenating-subarrays-of-another-array/

class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int i = 0, n = nums.size();
        for (vector<int>& group: groups) {
            int exist = 0, n_ = group.size();
            while (i + n_ <= n) {
                int equal = 1;
                for (int j = 0; j < n_; ++j) {
                    if (group[j] != nums[i+j]) {
                        equal = 0;
                        break;
                    }
                }
                if (!equal) i += 1;
                else {
                    i += n_;
                    exist = 1;
                    break;
                }
            }
            if (!exist) return false;
        }
        return true;
    }
};