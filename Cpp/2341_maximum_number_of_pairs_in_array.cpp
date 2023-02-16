// https://leetcode.cn/problems/maximum-number-of-pairs-in-array/

class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int, int> cnt;

        vector<int> res(2, 0);
        for (int i: nums) {
            cnt[i] = 1 - cnt[i];
            if (cnt[i] == 0) {
                res[0] += 1;
            }
        }
        res[1] = nums.size() - 2 * res[0];
        return res;
    }
};