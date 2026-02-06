// https://leetcode.cn/problems/minimum-absolute-difference/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int diff_min = arr[1] - arr[0];
        for (int i = 1; i < n; ++i) {
            diff_min = min(diff_min, arr[i] - arr[i-1]);
        }
        vector<vector<int>> res;
        for (int i = 1; i < n; ++i) {
            if (arr[i] - arr[i-1] == diff_min) {
                res.push_back({arr[i-1], arr[i]});
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {4,2,1,3};
    auto res = sol.minimumAbsDifference(arr);
    for (const auto &value: res) {
        cout << value[0] << ", " << value[1] << '\n';
    }
    return 0;
}