// https://leetcode.cn/problems/maximum-k-to-sort-a-permutation/

#include <vector>

using namespace std;

class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        if (nums[0] != 0) return 0;
        int res = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i) {
                res &= nums[i];
            }
        }
        return max(res, 0);
    }
};