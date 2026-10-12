// https://leetcode.cn/problems/apply-operations-on-array-to-maximize-sum-of-squares/

#include <vector>

using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        int length = 30;
        vector<int> cnt(length, 0);
        for (int num: nums) {
            for (int i = 0; i < length; ++i) {
                cnt[i] += ((num >> i) & 1);
            }
        }
        long long res = 0;
        int mod = 1e9 + 7;
        for (int k_ = 0; k_ < k; ++k_) {
            long long num = 0;
            for (int i = 0; i < length; ++i) {
                if (cnt[i] > 0) {
                    cnt[i] -= 1;
                    num |= (1 << i);
                }
            }
            res = (res + num * num) % mod;
        }
        return res;
    }
};