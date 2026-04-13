// https://leetcode.cn/problems/minimum-distance-to-the-target-element/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int res = nums.size();
        for (int i = 0; i < nums.size(); ++ i) {
            if (nums[i] == target) {
                int d = abs(i - start);
                if (res > d) res = d;
                else break;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1};
    int target = 1;
    int start = 0;
    cout << sol.getMinDistance(nums, target, start) << '\n';
    return 0;
}