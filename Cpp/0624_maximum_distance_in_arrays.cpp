// https://leetcode.cn/problems/maximum-distance-in-arrays/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int res = 0;
        int min_ = arrays[0][0], max_ = arrays[0].back();
        for (int i = 1; i < arrays.size(); ++i) {
            int min_i = arrays[i][0], max_i = arrays[i].back();
            res = max(res, max(max_i-min_, max_-min_i));
            min_ = min(min_, min_i);
            max_ = max(max_, max_i);
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> arrays = {
        {1,2,3},
        {4,5},
        {1,2,3}
    };
    cout << sol.maxDistance(arrays) << '\n';
    return 0;
}

