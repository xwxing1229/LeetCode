// https://leetcode.cn/problems/find-all-k-distant-indices-in-an-array/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> res;
        int n = nums.size(), cnt = 0;
        
        for (int i = 0; i < min(n, k+1); ++i) {
            if (nums[i] == key) cnt += 1;
        }
        if (cnt > 0) res.push_back(0);

        for (int i = 1; i < n; ++i) {
            if (i + k < n) cnt += (nums[i+k] == key);
            if (i - k - 1 >= 0) cnt -= (nums[i-k-1] == key);
            if (cnt > 0) res.push_back(i);
        }
        return res;
    }
};

int main() {
    Solution sol;
    // vector<int> nums = {3,4,9,1,3,9,5};
    // int key = 9;
    // int k = 1;
    vector<int> nums = {2,2,2,2,2};
    int key = 2;
    int k = 2;
    auto res = sol.findKDistantIndices(nums, key, k);
    for (auto &val: res) cout << val << ", ";
    cout << '\n';
    return 0;
}