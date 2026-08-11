// https://leetcode.cn/problems/smallest-missing-integer-greater-than-sequential-prefix-sum/

#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int res = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] - nums[i-1] != 1) {
                break;
            }
            res += nums[i];
        }
        unordered_set<int> s(nums.begin(), nums.end());
        while (s.count(res)) {
            res += 1;
        }
        return res;
    }
};