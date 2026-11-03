// https://leetcode.cn/problems/minimum-moves-to-equal-array-elements-iii/

#include <vector>

using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mx = nums[0], s = 0, n = nums.size();
        for (int num: nums) {
            mx = max(mx, num);
            s += num;
        }
        return mx * n - s;
    }
};