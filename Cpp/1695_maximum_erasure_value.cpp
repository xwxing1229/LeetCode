// https://leetcode.cn/problems/maximum-erasure-value/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int res = 0;
        int left = 0, tmp = 0;
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            while (left < i && s.find(num) != s.end()) {
                tmp -= nums[left];
                s.erase(nums[left]);
                left += 1;
            }
            tmp += num;
            s.insert(num);
            res = max(res, tmp);
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {4,2,4,5,6};
    cout << sol.maximumUniqueSubarray(nums) << '\n';
    return 0;
}