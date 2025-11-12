// https://leetcode.cn/problems/minimum-number-of-operations-to-make-all-array-elements-equal-to-1/

#include <vector>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), cnt1 = 0, g = 0;
        for (int &num: nums) {
            cnt1 += (num == 1);
            g = gcd(g, num);
        }
        if (cnt1 > 0) return n - cnt1;
        if (g > 1) return -1;

        int min_len = n; // minimum length of subarray whose gcd is 1
        for (int i = 0; i < n; ++i) {
            g = 0;
            for (int j = i; j < n; ++j) {
                g = gcd(g, nums[j]);
                if (g == 1) {
                    min_len = min(min_len, j-i+1);
                    break;
                }
            }
        }
        return min_len - 1 + n - 1;
    }
};