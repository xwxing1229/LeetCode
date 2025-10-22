// https://leetcode.cn/problems/maximum-frequency-of-an-element-after-performing-operations-i/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int mx = nums[0];
        for (auto num: nums) mx = max(mx, num);
        // prefix[i]: how many numbers whose values are in [0, i].
        vector<int> cnt(mx+1, 0), prefix(mx+1, 0);
        for (auto num: nums) cnt[num] += 1;
        prefix[0] = cnt[0];
        for (int i = 1; i <= mx; ++i) prefix[i] = prefix[i-1] + cnt[i];

        int res = 0;
        for (int tar = 0; tar <= mx; ++tar) {
            int cnt_original = cnt[tar];
            int left = max(0, tar-k), right = min(mx, tar+k);
            int total = prefix[right];
            if (left > 0) total -= prefix[left-1];
            int convert = min(numOperations, total-cnt_original);
            res = max(res, cnt_original+convert);
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,4,5};
    int k = 1;
    int numOperations = 2;
    cout << sol.maxFrequency(nums, k, numOperations) << '\n';
    return 0;
}