// https://leetcode.cn/problems/partition-array-according-to-given-pivot/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> left, right;
        left.reserve(n);
        right.reserve(n);
        int cnt_pivot = 0;
        for (const int &num: nums) {
            if (num < pivot) left.push_back(num);
            else if (num > pivot) right.push_back(num);
            else cnt_pivot += 1;
        }
        vector<int> mid(cnt_pivot, pivot);
        left.insert(left.end(), mid.begin(), mid.end());
        left.insert(left.end(), right.begin(), right.end());
        return left;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {9,12,5,10,14,3,10};
    int pivot = 10;
    auto res = sol.pivotArray(nums, pivot);
    for (const auto &val: res) cout << val << ", ";
    cout << '\n';
    return 0;
}