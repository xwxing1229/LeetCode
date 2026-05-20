// https://leetcode.cn/problems/find-the-prefix-common-array-of-two-arrays/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<vector<int>> check(2, vector<int>(n+1, 0));
        check[0][A[0]] = 1;
        check[1][B[0]] = 1;
        vector<int> res(n, 0);
        res[0] = (A[0] == B[0]);
        for (int i = 1; i < n; ++i) {
            int a = A[i], b = B[i];
            check[0][a] = 1;
            check[1][b] = 1;
            res[i] = res[i-1] + check[1][a] + check[0][b] - (a == b);
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> A = {3,1,2,4};
    vector<int> B = {1,3,2,4};
    auto res = sol.findThePrefixCommonArray(A, B);
    for (const auto &val: res) cout << val << ", ";
    cout << '\n';
}