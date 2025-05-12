// https://leetcode.cn/problems/finding-3-digit-even-numbers/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        sort(digits.begin(), digits.end());
        int n = digits.size();
        vector<vector<int>> base {
            {100, 10, 1}, {10, 100, 1},
            {100, 1, 10}, {1, 100, 10},
            {10, 1, 100}, {1, 10, 100}
        };
        unordered_set<int> s;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; ++i) {
            if (i > 0 && digits[i] == digits[i-1]) continue;
            for (int j = i+1; j < n; ++j) {
                if (j > i+1 && digits[j] == digits[j-1]) continue;
                for (int k = j+1; k < n; ++k) {
                    if (k > j+1 && digits[k] == digits[k-1]) continue;
                    for (auto &val: base) {
                        int num = digits[i] * val[0] + digits[j] * val[1] + digits[k] * val[2];
                        if (num / 100 > 0 && num % 2 == 0 && s.find(num) == s.end()) {
                            s.insert(num);
                            pq.push(num);
                        }
                    }
                }
            }
        }
        
        vector<int> res;
        while (!pq.empty()) {
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> digits {2,2,8,8,2};
    auto res = sol.findEvenNumbers(digits);
    for (auto &val: res) cout << val << ", ";
    cout << '\n';
    return 0;
}