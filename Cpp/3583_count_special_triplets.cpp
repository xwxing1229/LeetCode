// https://leetcode.cn/problems/count-special-triplets/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int res = 0, mod = 1e9+7;
        unordered_map<int, vector<int>> position;
        for (int i = 0; i < nums.size(); ++i) {
            position[nums[i]].push_back(i);
        }
        for (auto it = position.begin(); it != position.end(); ++it) {
            int tar = it->first * 2;
            if (position.find(tar) == position.end()) continue;

            auto &tar_pos = position[tar];
            int n = tar_pos.size();
            for (int p: it->second) {
                int left = 0, right = n-1, k = -1;
                while (left <= right) {
                    int mid = left + (right - left) / 2;
                    if (tar_pos[mid] < p) {
                        left = mid + 1;
                        k = mid;
                    }
                    else {
                        right = mid - 1;
                    }
                }
                if (k >= 0) {
                    left = k + 1;
                    right = n - k - 1 - (tar == 0);
                    res = (res + (long)left * right % mod) % mod;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {6,3,6};
    cout << sol.specialTriplets(nums) << '\n';
    return 0;
}