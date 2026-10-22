// https://leetcode.cn/problems/minimum-operations-to-sort-a-permutation/

#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return 0;
        }
        int diff = nums[1] - nums[0];
        if (abs(diff) != 1) {
            diff = nums[2] - nums[1];
            if (abs(diff) != 1) {
                return -1;
            }
        }
        int pos = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] - nums[i-1] != diff) {
                if (pos > 0) {
                    return -1;
                }
                pos = i;
            }
        }
        if (diff == 1) return min(pos, n-pos+2);
        else return min(pos+1, n-pos+1);
    }
};