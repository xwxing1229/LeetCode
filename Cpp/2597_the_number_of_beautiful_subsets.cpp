// https://leetcode.cn/problems/the-number-of-beautiful-subsets/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <functional>

using namespace std;

class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int res = -1, n = nums.size();
        sort(nums.begin(), nums.end());
        unordered_map<int, int> cnts;

        function<void(int)> dfs = [&](int idx) {
            if (idx == n) {
                res += 1;
                return;
            }
            dfs(idx+1);
            int num = nums[idx];
            if (cnts[num-k] == 0) {
                cnts[num] += 1;
                dfs(idx+1);
                cnts[num] -= 1;
            }
        };
        dfs(0);
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2,3,4,5,9,10};
    int k = 1;
    cout << sol.beautifulSubsets(nums, k) << '\n';
    return 0;
}