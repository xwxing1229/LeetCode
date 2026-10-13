// https://leetcode.cn/problems/maximum-alternating-sum-of-squares/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> vals(n);
        for (int i = 0; i < n; ++i) {
            vals[i] = abs(nums[i]);
        }
        sort(vals.begin(), vals.end());

        long long res = 0;
        int left = 0, right = n-1;
        while (left < right) {
            long long small = vals[left], big = vals[right];
            res += big * big - small * small;
            left += 1;
            right -= 1;
        }
        res += (long long)vals[left] * vals[left] * (left == right);
        return res;
    }
};