// https://leetcode.cn/problems/minimum-moves-to-equal-array-elements/

#include <vector>

using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int s = 0, mn = nums[0];
        for (const auto num: nums) {
            s += num;
            mn = min(mn, num);
        }
        return s - mn * nums.size();
    }
};