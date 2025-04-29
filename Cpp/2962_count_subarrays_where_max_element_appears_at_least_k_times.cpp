// https://leetcode.cn/problems/count-subarrays-where-max-element-appears-at-least-k-times/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int mx = nums[0];
        int left = 0, right = 0, n = nums.size(), cnt = 0;
        long long res = 0;
        for (auto &num: nums) {
            mx = max(mx, num);
        }
        while (right < n) {
            if (nums[right] == mx) {
                cnt += 1;
            }
            right += 1;
            while (left < right && cnt >= k) {
                if (nums[left] == mx) {
                    cnt -= 1;
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
    vector<int> nums {28,5,58,91,24,91,53,9,48,85,16,70,91,91,47,91,61,4,54,61,49};
    int k = 1;
    cout << sol.countSubarrays(nums, k)<< '\n';
    return 0;
}