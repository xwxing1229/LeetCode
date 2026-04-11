// https://leetcode.cn/problems/minimum-distance-between-three-equal-elements-ii/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> position;
        for (int i = 0; i < nums.size(); ++i) {
            position[nums[i]].push_back(i);
        }
        int res = -1;
        for (const auto &[num, pos]: position) {
            for (int i = 2; i < pos.size(); ++i) {
                int d = 2 * (pos[i] - pos[i-2]);
                if (res < 0 || res > d) {
                    res = d;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,1,2,3,2,1,2};
    cout << sol.minimumDistance(nums) << '\n';
    return 0;
}