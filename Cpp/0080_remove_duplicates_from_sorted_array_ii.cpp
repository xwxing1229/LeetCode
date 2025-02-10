// https://leetcode.cn/problems/remove-duplicates-from-sorted-array-ii/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow = 2, n = nums.size();
        if (n <= 2) return n;
        for (int fast = 2; fast < n; ++fast) {
            if (nums[fast] != nums[slow-2]) {
                nums[slow] = nums[fast];
                slow += 1;
            }
        }
        return slow;
    }
};

int main() {
    Solution solu;
    vector<int> nums = {1,1,1,2,2,2,3,3};
    int res = solu.removeDuplicates(nums);
    for (int i = 0; i < res; ++i) {
        cout << nums[i] << ", ";
    }
    cout << '\n';
    return 0;
}