// https://leetcode.cn/problems/find-subsequence-of-length-k-with-the-largest-sum/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> idxs(n);
        for (int i = 0; i < n; ++i) {
            idxs[i] = i;
        }
        sort(idxs.begin(), idxs.end(), [&](const int i, const int j) {
            return nums[i] > nums[j];
        });
        idxs.resize(k);
        sort(idxs.begin(), idxs.end());
        vector<int> res(k);
        for (int i = 0; i < k; ++i) {
            res[i] = nums[idxs[i]];
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2,1,3,3};
    int k = 2;
    auto res = sol.maxSubsequence(nums, k);
    for (auto &val: res) cout << val << ", ";
    cout << '\n';
    return 0;
}