// https://leetcode.cn/problems/find-x-value-of-array-i/

#include <vector>

using namespace std;

class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> res(k, 0);
        int n = nums.size();
        vector<vector<long long>> dp(n+1, vector<long long>(k, 0));
        for (int i = 0; i < n; ++i) {
            long long num = nums[i];
            dp[i+1][num%k] = 1;
            for (int mod = 0; mod < k; ++mod) {
                dp[i+1][num*mod%k] += dp[i][mod];
            }
            for (int mod = 0; mod < k; ++mod) {
                res[mod] += dp[i+1][mod];
            }
        }
        return res;
    }
};