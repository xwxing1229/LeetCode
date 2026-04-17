// https://leetcode.cn/problems/minimum-absolute-distance-between-mirror-pairs/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        auto ComputeMirror = [](int num) {
            int res = 0;
            while (num > 0) {
                res = res * 10 + num % 10;
                num /= 10;
            }
            return res;
        };

        int n = nums.size();
        int res = n;
        unordered_map<int, int> target;
        for (int i = 0; i < n; ++i) {
            int num = nums[i];
            if (target.count(num)) {
                res = min(res, i - target[num]);
            }
            target[ComputeMirror(num)] = i;
        }
        return res < n ? res : -1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {120, 21};
    cout << sol.minMirrorPairDistance(nums) << '\n';
    return 0;
}