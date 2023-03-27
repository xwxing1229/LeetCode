// https://leetcode.cn/problems/find-subarrays-with-equal-sum/

class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_set<int> check;
        for (int i = 1; i < nums.size(); ++i) {
            int s = nums[i] + nums[i-1];
            if (check.find(s) != check.end()) {
                return true;
            }
            check.insert(s);
        }
        return false;
    }
};
