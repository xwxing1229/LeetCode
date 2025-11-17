// https://leetcode.cn/problems/check-if-all-1s-are-at-least-length-k-places-away/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int pre = -k - 1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 1) {
                if (i - pre - 1 < k) {
                    return false;
                }
                pre = i;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,0,0,0,1,0,0,1};
    int k = 2;
    cout << sol.kLengthApart(nums, k) << '\n';
    return 0;
}