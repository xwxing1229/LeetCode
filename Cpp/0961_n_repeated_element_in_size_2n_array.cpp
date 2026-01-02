// https://leetcode.cn/problems/n-repeated-element-in-size-2n-array/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> s;
        for (const int &num: nums) {
            if (s.find(num) != s.end()) {
                return num;
            }
            s.insert(num);
        }
        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,2,3,3};
    cout << sol.repeatedNTimes(nums) << '\n';
    return 0;
}