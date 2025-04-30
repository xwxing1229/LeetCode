// https://leetcode.cn/problems/count-complete-subarrays-in-an-array/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
        
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int, int> s, cnt;
        for (auto &num: nums) {
            s[num] += 1;
        }
        auto n = s.size();
        int res = 0, left = 0;
        for (auto &num: nums) {
            cnt[num] += 1;
            while (cnt.size() == n) {
                int out = nums[left];
                cnt[out] -= 1;
                if (cnt[out] == 0) {
                    cnt.erase(out);
                }
                left += 1;
            }
            res += left;
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,3,1,2,2};
    cout << sol.countCompleteSubarrays(nums) << '\n';
    return 0;
}