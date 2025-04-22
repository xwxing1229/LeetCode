// https://leetcode.cn/problems/count-equal-and-divisible-pairs-in-an-array/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int res = 0;
        unordered_map<int, vector<int>> cnt;
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            for (const auto &j: cnt[num]) {
                if (i * j % k == 0) {
                    res += 1;
                }
            }
            cnt[num].push_back(i);
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3,1,2,2,2,1,3};
    int k = 2;
    cout << sol.countPairs(nums, k) << '\n';
    return 0;
}