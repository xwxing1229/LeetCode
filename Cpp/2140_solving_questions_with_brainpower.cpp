// https://leetcode.cn/problems/solving-questions-with-brainpower/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n+1, 0);
        for (int i = n-1; i >= 0; --i) {
            int j = min(n, i + questions[i][1] + 1);
            dp[i] = max(dp[i+1], dp[j] + questions[i][0]);
        }
        return dp[0];
    }
};

int main() {
    Solution sol;
    vector<vector<int>> questions = {};
    cout << sol.mostPoints(questions) << '\n';
    return 0;
}