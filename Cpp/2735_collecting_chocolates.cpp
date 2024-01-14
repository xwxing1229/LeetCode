// https://leetcode.cn/problems/collecting-chocolates/
        
class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        long long res = 0;
        for (int num: nums) {
            res += num;
        }
        int n = nums.size();
        vector<int> mins(nums.begin(), nums.end());
        for (int i = 1; i < n; ++i) {
            long long tmp = 0;
            for (int j = 0; j < n; ++j) {
                mins[j] = min(mins[j], nums[(j+n-i)%n]);
                tmp += mins[j];
            }
            res = min(res, tmp+(long long)i*x);
        }
        return res;
    }
};