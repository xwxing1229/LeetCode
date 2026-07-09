// https://leetcode.cn/problems/path-existence-queries-in-a-graph-i/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> valid(n, 0);
        int right = 0;
        for (int i = 0; i < n; ++i) {
            right = max(i+1, right);
            while (right < n && nums[right] - nums[right-1] <= maxDiff) {
                right += 1;
            }
            valid[i] = right - 1;
        }

        vector<bool> res(queries.size(), false);
        for (int i = 0; i < queries.size(); ++i) {
            int l = min(queries[i][0], queries[i][1]);
            int r = queries[i][0] + queries[i][1] - l;
            res[i] = valid[l] >= r;
        }
        return res;
    }
};