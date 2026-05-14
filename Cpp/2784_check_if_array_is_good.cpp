// https://leetcode.cn/problems/check-if-array-is-good/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.back(), size = nums.size();
        if (size != n+1 || nums[size-2] != n) return false;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i+1) return false;
        }
        return true;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,3,2,3};
    cout << sol.isGood(nums) << '\n';
    return 0;
}