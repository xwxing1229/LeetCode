// https://leetcode.cn/problems/permutations-ii/

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> check(n, 0);

        function<void(vector<int> &)> dfs = [&](vector<int> &cur) {
            if (cur.size() == n) {
                res.push_back(cur);
            }
            for (int i = 0; i < n; ++i) {
                if (i > 0 && nums[i] == nums[i-1] && (!check[i-1])) continue;
                else if (check[i]) continue;

                cur.push_back(nums[i]);
                check[i] = 1;
                dfs(cur);
                cur.pop_back();
                check[i] = 0;
            }
        };
        
        vector<int> cur;
        dfs(cur);
        return res;
    }
};

int main()
{
    Solution solu;
    vector<int> nums = {1,1,2};
    auto res = solu.permuteUnique(nums);
    for (auto element: res) {
        for (auto val: element) cout << val << ", ";
        cout << '\n';
    }
    
    return 0;
}