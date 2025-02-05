// https://leetcode.cn/problems/subsets-ii/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res = {{}, {nums[0]}};
        int add = 1;
        for (int i = 1; i < nums.size(); ++i) {
            int num = nums[i];
            int n = res.size();
            if (num != nums[i-1]) {
                add = n;
            }
            for (int k = n-add; k < n; ++k) {
                auto cur = res[k];
                cur.push_back(num);
                res.push_back(cur);
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,2,2};
    // vector<int> nums = {5,5,5};
    auto res = sol.subsetsWithDup(nums);
    for (auto element: res) {
        for (auto val: element) cout << val << ", ";
        cout << '\n';
    }
    return 0;
}