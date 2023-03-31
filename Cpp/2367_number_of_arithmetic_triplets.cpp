// https://leetcode.cn/problems/number-of-arithmetic-triplets/

class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        unordered_set<int> s(nums.begin(), nums.end());
        int res = 0;
        for (int num: nums) {
            if (s.find(num+diff) != s.end() &&
                s.find(num+diff+diff) != s.end()) {
                res += 1;
            }
        }
        return res;
    }
};
