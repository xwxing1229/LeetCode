// https://leetcode.cn/problems/number-of-distinct-averages/

class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        unordered_set<int> s;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n/2; ++i) {
            s.insert(nums[i] + nums[n-1-i]);
        }
        return s.size();
    }
};