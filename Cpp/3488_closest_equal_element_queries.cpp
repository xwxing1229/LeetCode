// https://leetcode.cn/problems/closest-equal-element-queries/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> position;
        for (int i = 0; i < n; ++i) {
            position[nums[i]].push_back(i);
        }
        unordered_map<int, int> closest;
        for (const auto &[num, pos]: position) {
            int k = pos.size();
            if (k < 2) continue;
            for (int i = 1; i < k-1; ++i) {
                int p = pos[i];
                closest[p] = min(p-pos[i-1], pos[i+1]-p);
            }
            closest[pos[0]] = min(pos[0]+n-pos[k-1], pos[1]-pos[0]);
            closest[pos[k-1]] = min(pos[k-1]-pos[k-2], pos[0]+n-pos[k-1]);
        }
        vector<int> res(queries.size(), -1);
        for (int i = 0; i < queries.size(); ++i) {
            if (closest.count(queries[i])) {
                res[i] = closest[queries[i]];
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,3,1,4,1,3,2};
    vector<int> queries = {0,3,5};
    auto res = sol.solveQueries(nums, queries);
    for (const auto &val: res) cout << val << ", ";
    cout << '\n';
    return 0;
}