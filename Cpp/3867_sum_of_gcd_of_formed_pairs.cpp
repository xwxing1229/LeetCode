// https://leetcode.cn/problems/sum-of-gcd-of-formed-pairs/

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        int mx = nums[0];
        vector<int> prefixGcd(n);
        for (int i = 0; i < n; ++i) {
            mx = max(mx, nums[i]);
            prefixGcd[i] = gcd(mx, nums[i]);
        }
        sort(prefixGcd.begin(), prefixGcd.end());
        long long res = 0;
        for (int i = 0; i < n/2; ++i) {
            res += gcd(prefixGcd[i], prefixGcd[n-1-i]);
        }
        return res;
    }
};