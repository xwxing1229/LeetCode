// https://leetcode.cn/problems/smallest-missing-multiple-of-k/

#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int mx = nums[0];
        for (int num: nums) {
            mx = max(mx, num);
        }
        unordered_set<int> s(nums.begin(), nums.end());
        for (int x = k; x <= mx + k; x+=k) {
            if (!s.count(x)) {
                return x;
            }
        }
        return -1;
    }
};