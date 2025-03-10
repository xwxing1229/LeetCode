// https://leetcode.cn/problems/most-beautiful-item-for-each-query/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        vector<int> res(queries.size(), 0);
        sort(items.begin(), items.end());
        int n = items.size();
        vector<int> beauties(n, items[0][1]);
        for (int i = 1; i < n; ++i) {
            beauties[i] = max(beauties[i-1], items[i][1]);
        }
        for (int i = 0; i < queries.size(); ++i) {
            int left = 0, right = n-1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (items[mid][0] <= queries[i]) {
                    res[i] = beauties[mid];
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> items = {{1,2}, {3,2}, {2,4}, {5,6}, {3,5}};
    vector<int> queries = {1,2,3,4,5,6}; // {2,4,5,5,6,6}
    auto res = sol.maximumBeauty(items, queries);
    for (auto val: res) cout << val << ", ";
    cout << '\n';
    return 0;
}