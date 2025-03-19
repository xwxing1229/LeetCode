// https://leetcode.cn/problems/convert-an-array-into-a-2d-array-with-conditions/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res = {{nums[0]}};
        int idx = 0;
        for (int i = 1; i < nums.size(); ++i) {
            int num = nums[i];
            if (num == nums[i-1]) {
                idx += 1;
                if (idx == res.size()) res.push_back({num});
                else res[idx].push_back(num);
            }
            else {
                idx = 0;
                res[idx].push_back(num);
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,3,4,1,2,3,1};
    auto res = sol.findMatrix(nums);
    for (auto &row: res) {
        for (auto val: row) {
            cout << val << ", ";
        }
        cout << '\n';
    }
    return 0;
}