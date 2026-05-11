// https://leetcode.cn/problems/separate-the-digits-in-an-array/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        res.reserve(n * 6);
        for (const int &num: nums) {
            string s = to_string(num);
            for (const char &ch: s) {
                res.push_back(ch - '0');
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {13,25,83,77};
    auto res = sol.separateDigits(nums);
    for (const int &val: res) cout << val << ", ";
    cout << '\n';
    return 0;
}