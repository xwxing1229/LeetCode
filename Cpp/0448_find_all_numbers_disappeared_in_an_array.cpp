// https://leetcode.cn/problems/find-all-numbers-disappeared-in-an-array/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> cnt(n, 0);
        for (int i: nums) {
            cnt[i-1] = 1;
        }
        vector<int> res;
        for (int i = 0; i < n; ++i) {
            if (cnt[i] == 0) {
                res.push_back(i+1);
            }
        }
        return res;
    }
};
