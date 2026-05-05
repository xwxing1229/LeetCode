// https://leetcode.cn/problems/sort-integers-by-the-number-of-1-bits/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        auto bit_cnt = [](int num) {
            int res = 0;
            while (num > 0) {
                res += (num & 1);
                num >>= 1;
            }
            return res;
        };
        sort(arr.begin(), arr.end(), [&](const int a, const int b) {
            int cnt_a = bit_cnt(a), cnt_b = bit_cnt(b);
            return cnt_a < cnt_b || (cnt_a == cnt_b && a < b);
        });
        return arr;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1024,512,256,128,64,32,16,8,4,2,1};
    auto res = sol.sortByBits(arr);
    for (const auto &val: res) {
        cout << val << ", ";
    }
    cout << '\n';
    return 0;
}