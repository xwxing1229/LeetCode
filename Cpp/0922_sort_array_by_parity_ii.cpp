// https://leetcode.cn/problems/sort-array-by-parity-ii/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> res(nums.size());
        int even = 0, odd = 1;
        for (int num: nums) {
            if (num % 2 == 0) {
                res[even] = num;
                even += 2;
            }
            else {
                res[odd] = num;
                odd += 2;
            }
        }
        return res;
    }
};


int main() {
	Solution sol;
    vector<int> nums = {2,4,5,7};
    auto res = sol.sortArrayByParityII(nums);
    for (int val: res) cout << val << ", ";
    cout << '\n';
    return 0;
}