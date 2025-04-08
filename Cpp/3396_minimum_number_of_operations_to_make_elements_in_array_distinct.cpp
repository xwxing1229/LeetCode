// https://leetcode.cn/problems/minimum-number-of-operations-to-make-elements-in-array-distinct/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int, int> cnt;
        vector<int> remove;
        for (int num: nums) cnt[num] += 1;
        for (auto it = cnt.begin(); it != cnt.end(); ++it) {
            if (it->second <= 1) remove.push_back(it->first);
        }
        for (int num: remove) cnt.erase(num);
        int res = 0, i = 0, n = nums.size();
        while (i + 2 < n) {
            if (cnt.size() == 0) break;
            for (int j = i; j < i+3; ++j) {
                int num = nums[j];
                cnt[num] -= 1;
                if (cnt[num] <= 1) cnt.erase(num);
            }
            res += 1;
            i += 3;
        }
        res += ((i < n) && (cnt.size() != 0));
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,2,3,4,2,3,3,5,7};
    cout << sol.minimumOperations(nums) << '\n';
    return 0;
}
