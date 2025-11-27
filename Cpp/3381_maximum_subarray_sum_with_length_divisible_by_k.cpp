// https://leetcode.cn/problems/maximum-subarray-sum-with-length-divisible-by-k/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> cumsum(n+1, 0);
        for (int i = 0; i < n; ++i) {
            cumsum[i+1] = cumsum[i] + nums[i];
        }

        long long res = cumsum[k];
        // min_left[j]: min(sum(nums[0], ..., nums[i])) with (i - j) % k = 0.
        vector<long long> min_left(cumsum.begin()+1, cumsum.begin()+k+1);
        min_left[k-1] = min((long long)0, min_left[k-1]);
        for (int i = k; i < n; ++i) {
            int match = i % k;
            res = max(res, cumsum[i+1]-min_left[match]);
            min_left[match] = min(min_left[match], cumsum[i+1]);
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2};
    int k = 1;
    cout << sol.maxSubarraySum(nums, k) << '\n';
    return 0;
}