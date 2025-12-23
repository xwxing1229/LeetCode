// https://leetcode.cn/problems/delete-columns-to-make-sorted/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int res = 0;
        int n = strs.size();
        for (int col = 0; col < strs[0].size(); ++col) {
            for (int row = 1; row < n; ++row) {
                if (strs[row][col] < strs[row-1][col]) {
                    res += 1;
                    break;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<string> strs = {"cba", "daf", "ghi"};
    cout << sol.minDeletionSize(strs) << '\n';
    return 0;
}