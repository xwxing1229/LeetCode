// https://leetcode.cn/problems/smallest-stable-index-i/

#include <vector>

using namespace std;

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sufmin(n, nums.back());
        for (int i = n-2; i >= 0; --i) {
            sufmin[i] = min(sufmin[i+1], nums[i]);
        }
        int premax = nums[0];
        for (int i = 0; i < n; ++i) {
            premax = max(premax, nums[i]);
            if (premax - sufmin[i] <= k) {
                return i;
            }
        }
        return -1;
    }
};