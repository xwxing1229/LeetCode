// https://leetcode.cn/problems/minimum-distance-between-three-equal-elements-ii/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int res = -1;
        int n = nums.size();
        vector<vector<int>> position(n+1, vector<int>(2, -1));
        for (int i = 0; i < n; ++i) {
            int num = nums[i];
            auto &pos = position[num];
            if (pos[0] >= 0) {
                int d = i - pos[0];
                if (res < 0 || res > d) {
                    res = d;
                }
            }
            pos[0] = pos[1];
            pos[1] = i;
        }
        return res > 0 ? res * 2 : -1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,1,2,3,2,1,2};
    cout << sol.minimumDistance(nums) << '\n';
    return 0;
}